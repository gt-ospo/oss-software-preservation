FROM alpine:3.21.2@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099 AS build
RUN apk add --no-cache openmpi
RUN apk add --no-cache build-base openmpi-dev
RUN mkdir /build
COPY ./mpi_test.cxx /build
RUN mpicxx /build/mpi_test.cxx -o /build/mpi_test

FROM alpine:3.21.2@sha256:56fa17d2a7e7f168a043a2712e63aed1f8543aeafdcee47c58dcffe38ed51099
RUN apk add --no-cache openmpi
COPY --from=build /build/mpi_test /mpi_test
CMD ["mpirun", "-n", "4", "/mpi_test"]
