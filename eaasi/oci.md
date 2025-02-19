# OCI (Docker) containers on EaaSI

The recommended method to run Linux and command-line software on EaaSI is to upload it as a OCI (Docker) container.

## Example for a software that uses MPI

Below is an example Dockerfile to make a container.
Make sure to follow the following guidelines:

- Pin the base images (in the `FROM` lines) to a SHA256 digest, so the exact same base image is used every single time
- If not required, keep the resultant image small to make uploading quicker (and potentially easier).

```Dockerfile
FROM alpine:3.21.2@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099 AS build
RUN apk add --no-cache openmpi
RUN apk add --no-cache build-base openmpi-dev
    # ↑ Install openmpi and compilers
    #   Keep openmpi line separate to aid with build time/cache.
RUN mkdir /build
COPY ./mpi_test.cxx /build
RUN mpicxx /build/mpi_test.cxx -o /build/mpi_test

FROM alpine:3.21.2@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099
RUN apk add --no-cache openmpi
    # ↑ Installs mpirun etc
COPY --from=build /build/mpi_test /mpi_test
    # ↑ Copy only the compiled mpi_test binary from the build stage.
    #   If other tools are required in the resultant image, install them here (after the 2nd FROM line).
CMD ["mpirun", "-n", "1", "/mpi_test"]
    # ↑ Default command to run when running the image.
    #   The command can be overridden at runtime.
```

Use these commands to build the image:

```sh
cd mpi-container
# ↑ Change to the directory with Dockerfile.
docker build -t tag_abc .
# ↑ tag_abc should describe what you're building, but will not appear in the final result on EaaSI.
#   (Change both line above and below.)
docker image save tag_abc -o mpi-container.tar.gz
```

Now, the image is in the `mpi-container.tar.gz` file.
[Upload the image (tar.gz) as a Software Resource](./upload-software-resource.md).
After uploading, inside the EaaSI Environment, run `docker load < /path/to/uploaded/container.tar.gz`
(try `podman` instead of `docker` if the command is not found).
