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
On your local machine, `cd` to the directory of the large file you would like to upload to EaaSi. The file that we will be uploading in this tutorial has been is provided [here](./mpi-container/image.tar.gz).

### Step 2
This example file is 7.59MB, which is larger than the 2.6MB limit. For this reason, it will need to be split into multiple chunks. 

We can split this `tar` file into multiple pieces by using the following command: 
`split –bytes=2400000 <image_name>​`

For example, to split the example file within the current directory, the command will look like: 
`split –bytes=2400000 image.tar.gz`

This split command will produce multiple new files within the current directory. The names of the new files will contain the original file name followed by a sequence of characters. The example file should be split into 4 chunks named: 

- `image.tar.gzaa`
- `image.tar.gzab`
- `image.tar.gzac`
- `image.tar.gzad`

The suffexes in the file names (`aa`, `ab`, etc.) represent the order of the split files in relation to that data's position within the original file. In other words, data from the start of the original large file will be located in the chunk with the smallest lexographical suffix. 

### Step 3
Tar each of the chunks produced in the previous step with the following command. Note that if you are using the example file, this will result in `2` "layers of tarring" (ex `image.tar.gzaa` will become `image.tar.gzaa.tar​​`). 

Command: `tar -cvf <chunk_name>.tar <chunk_name>
Example usage: `tar -cvf image.tar.gzaa.tar image.tar.gzaa`

### Step 4
[Upload the first chunk of the split file onto EaaSI](./uploading-small-files.md).

### Step 5
Now, the data from the first chunk of the split file is present on the floppy disk attached to the EaaSi machine. We need to save this data onto the machine so that we can rebuild our original file. 

Open any terminal program and run the following command: 
`sudo tar mxf /dev/fd0​​`

This will untar the first layer of the tarred file. 
`image.tar.gzaa.tar → image.tar.gzaa​​`

### Step 6
Place the `image.tar.gzaa​​` file in your home directory. We have successfully imported the first piece of the split file to EaaSi. Shut down the VM using `shutdown now` in the terminal. 

### Step 7
Press the save emulation button. 

<img width="295" alt="Screenshot 2025-02-19 at 8 55 27 AM" src="https://github.com/user-attachments/assets/f65a0979-366f-49c7-bef2-343b978c6d9f" />

### Step 8
Repeat steps 4-8 for every chunk of the split container. 

### Step 9
At this step, all of the sections of the container should be uploaded to EaaSi as `tar` files. These sections need to be recombined again in order to be extracted and used. Before proceeding, ensure that all of the chunks that represent your original file are present in your current EaaSi instance directory. Next, run this command to combine all the chunks into one file: 

Command: `cat <file_name>?? | <file_name>.tar.gz​`
Example Usage: `cat image.tar.gz?? | image.tar.gz​`

### Step 10
Uncompress 

gzip –d image.tar.gz # image.tar.gz → image.tar​

### Step 10
Import and run the docker image as usual:

```
docker load < image.tar​
docker run <image_identifier>​
```
