# How to upload a Large File (>2.6MB) to a Lubuntu Eaasi Environment

## Table of Contents
- [Problem](#problem)
- [Overview](#overview)
- [Get Started](#step-1)

## Problem
The problem that this tutorial will solve is the need to add software onto our base EaaSi environment. This tutorial will focus on files with a size greater than 2.6MB. For files smaller than 2.6MB size, [this](./uploading-small-files.md)  simpler turotial can be followed. 

## Overview
Since we currently can not support uploading files larger than 2.6MB in a single attempt, we need to split larger files into multiple small chunks. These chunks are uploaded individually from your local machine to an Eaasi Lubuntu instance. Once uploaded to the Eaasi instance, these chunks are recombined back into the large original file. 

### Step 1
On your local machine, `cd` to the directory of the large file you would like to upload to EaaSi. The file that we will be uploading in this tutorial has been is provided [here](../mpi-container/image.tar.gz).


### Step 3

Assume we have the container, exported as image.tar:​
`$ gzip image.tar​`

We can split this `tar` file into multiple pieces by using the following command: 
`$ split –bytes=2400000 image.tar.gz​`

This will produce multiple files(`image.tar.gzaa`, `image.tar.gzab`, ...). 

### Step 4
Tar each of the files produced in the previous step. Note that this will result in `2` "layers of tarring". 

`image.tar.gzaa → image.tar.gzaa.tar​​`

### Step 5
[Upload the first part of the split file onto EaaSI](./INDIVIDUAL_FILE.md).

### Step 6
Now, the data from the first part of the split file is present on the floppy disk attached to the EaaSi machine. We need to save this data onto the machine so that we can rebuild our original container. 

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
