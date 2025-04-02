#include <mpi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int rank, size;
    int shifts = 1;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("N = %d\n", size);
    }
    
    for (int i = 1; i < 20; i++) {
        int message_size = 1 << i;

        //printf("rank %d, size %d\n", rank, size);

        uint8_t *send_buffer = (uint8_t *)malloc(message_size * sizeof(uint8_t));
        uint8_t *recv_buffer = (uint8_t *)malloc(message_size * sizeof(uint8_t));

        memset(send_buffer, rank, message_size);

        int next = (rank + 1) % size;
        int prev = (rank - 1 + size) % size;

        double start_time = MPI_Wtime();
        for (int j = 0; j < 100; j++) {
            MPI_Sendrecv(send_buffer, message_size, MPI_BYTE, next, 0,
                            recv_buffer, message_size, MPI_BYTE, prev, 0,
                            MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        double end_time = MPI_Wtime();

        double time = (end_time - start_time) / 100;

        if (rank == 0) {
            printf("--------------------------------------- Message Size: %d bytes, Time: %e s ---------------------------------------\n", message_size, time);
            printf("Message Size: %d bytes, Time: %e s\n", message_size, time);
            printf("%e, ", time);
        }

        free(send_buffer);
        free(recv_buffer);
    }
    if (rank == 0) {
        printf("\n");
    }
    MPI_Finalize();
}
