# How to run OpenMPI Container on Eaasi

## Table of Contents
- [Problem](#problem)
- [Get Started](#step-1)

## Problem
The problem that this tutorial will solbe is the need to add software onto our base EaaSi environment. ​Software resources can normally be added to 
environments as an externally mounted drive​. Unfortunately, this does not work for Lubuntu as adding software to a Lubuntu environment seems to not do anything. For this reason,
this tutorial demonstrates the currently best known work around method for uploading software resources to EaaSi. 

### Step 1
First, create a container that you want to upload using a Dockerfile​. An example of an OpenMPI container is shown below. 

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
$ docker save <image_name> > image.tar​
$ gzip image.tar
```

### Step 3
As this method only allows for up to 2.6MB to be uploaded at a time, any file larger than this size will need to be split into multiplie pieces and reocombined later. 

