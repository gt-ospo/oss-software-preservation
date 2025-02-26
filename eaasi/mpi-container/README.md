# How to run OpenMPI Container on Eaasi

## Table of Contents
- [Problem](#problem)
- [Get Started](#step-1)

## Problem
The problem that this tutorial will solve is the need to add software onto our base EaaSi environment. ​Software resources can normally be added to 
environments as an externally mounted drive​. Unfortunately, this does not work for Lubuntu as adding software to a Lubuntu environment seems to not do anything. For this reason,
this tutorial demonstrates the currently best known work around method for uploading software resources to EaaSi. 

### Step 1
First, create a container that you want to upload using a Dockerfile​. An example of an OpenMPI container `Dockerfile` is shown below. 

Save as `<working_directory>/Dockerfile`:
```
FROM alpine:3.21.2@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099 AS build​
RUN apk add --no-cache openmpi​
RUN apk add --no-cache build-base openmpi-dev​
RUN mkdir /build​
COPY ./ping_pong.c /build​
RUN mpicc /build/ping_pong.c -o /build/ping_pong​

FROM alpine:3.21.2@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099​
RUN apk add --no-cache openmpi​
COPY --from=build /build/ping_pong /ping_pong​
CMD ["mpirun", "--allow-run-as-root", "-mca", "plm_rsh_agent", "", "-n", "1", "/ping_pong"]​
```

### Step 2
Next, export the container you have just made. 

```
$ cd <working_directory>
$ ls Dockerfile # make sure Dockerfile is in working directory
$ docker build .
$ docker save <image_name> > image.tar​
$ gzip image.tar
```

### Step 3
As this method only allows for up to 2.6MB to be uploaded at a time, any file larger than this size will need to be split into multiplie pieces and reocombined later. 

Assume we have the container, exported as image.tar:​
`$ gzip image.tar​`

We can split this `tar` file into multiple pieces by using the following command: 
`$ split –bytes=2400000 image.tar.gz​`

This will produce multiple files(`image.tar.gzaa`, `image.tar.gzab`, ...). 

### Step 4
Tar each of the files produced in the previous step. Note that this will result in `2` "layers of tarring". 

`image.tar.gzaa → image.tar.gzaa.tar​​`

### Step 5
Use [the method shown in this tutorial](./INDIVIDUAL_FILE.md) to upload the first of the split files onto EaaSi. 

### Step 6
Now, the data from the split files is present on the floppy disk attached to the EaaSi machine. We need to save this data onto the machine so that we can rebuild our original container. 

Open any terminal program and run the following command: 
`sudo tar mxf /dev/fd0​​`

This will untar the first layer of the tarred file. 
`image.tar.gzaa.tar → image.tar.gzaa​​`

### Step 7
Place the `image.tar.gzaa​​` file in your home directory. We have successfully imported the first piece of the split image to EaaSi. Shut down the VM using `shutdown now` in the terminal. 

### Step 8
Press the save emulation button. 

<img width="295" alt="Screenshot 2025-02-19 at 8 55 27 AM" src="https://github.com/user-attachments/assets/f65a0979-366f-49c7-bef2-343b978c6d9f" />

### Step 9
Repeat steps 5-8 for every section of the split container. 

### Step 10
At this step, all of the sections of the container should be uploaded to EaaSi as `tar` files. These sections need to be recombined again in order to be extracted and used. 

```
$ cat image.tar.gz?? | image.tar.gz​
$ gzip –d image.tar.gz # image.tar.gz → image.tar​
```

### Step 11
Import and run the docker image as usual:

```
$ docker load < image.tar​
$ docker run <image_identifier>​
```
