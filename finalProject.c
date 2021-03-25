#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

struct peer
{
    char name[20];
    int rank;
};
int main(int argc, char *argv[])
{
    // struct peer peerList[2];

    int num_errors = 0;
    int rank, size;
    char port1[MPI_MAX_PORT_NAME];
    char port2[MPI_MAX_PORT_NAME];
    MPI_Status status;
    MPI_Comm comm1, comm2;
    int data;
    struct peer peerList[2] = {
        {"Client 1", 1},
        {"CLient 2", 2}};
    int dataO=0;
    int dataS=0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (size < 3)
    {
        printf("Three processes needed to run this test.\n");
        fflush(stdout);
        MPI_Finalize();
        return 0;
    }

    if (rank == 0)
    {
        fflush(stdout);
        MPI_Open_port(MPI_INFO_NULL, port1);
        MPI_Open_port(MPI_INFO_NULL, port2);
        printf("Server opened port1: <%s> for Client 1\n", port1);
        printf("Server opened port2: <%s> for Client 2\n\n", port2);
        fflush(stdout);

        MPI_Send(port1, MPI_MAX_PORT_NAME, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Send(port2, MPI_MAX_PORT_NAME, MPI_CHAR, 2, 0, MPI_COMM_WORLD);

        printf("Server connected CLient 2 via port2.\n");
        fflush(stdout);
        MPI_Comm_accept(port2, MPI_INFO_NULL, 0, MPI_COMM_SELF, &comm2);
        printf("Server connected CLient 1 via port1.\n");
        fflush(stdout);
        MPI_Comm_accept(port1, MPI_INFO_NULL, 0, MPI_COMM_SELF, &comm1);
        MPI_Close_port(port1);
        MPI_Close_port(port2);

        printf("\nServer sending peer's rank available to process 1.\n");
        printf("Server sending peer's rank available to process 2.\n");
        data = 2;
        MPI_Send(&data, 1, MPI_INT, 0, 0, comm1);
        fflush(stdout);
        data = 1;
        MPI_Send(&data, 1, MPI_INT, 0, 0, comm2);
        fflush(stdout);

        MPI_Comm_disconnect(&comm1);
        MPI_Comm_disconnect(&comm2);
    }
    else if (rank == 1)
    {
        MPI_Recv(port1, MPI_MAX_PORT_NAME, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Comm_connect(port1, MPI_INFO_NULL, 0, MPI_COMM_SELF, &comm1);
        MPI_Recv(&dataO, 1, MPI_INT, 0, 0, comm1, &status);

        if (dataO)
        {
            printf("Client 1 received peer's rank available from server: %d \n", dataO);
            char smt[80] = "Hello";
        MPI_Send(&smt, strlen(smt) + 1, MPI_CHAR, dataO, 2, MPI_COMM_WORLD);
        printf("\nClient 1 say Hello to Client 2\n");
        sleep(2);
        char reply[20];
        MPI_Recv(&reply, 100, MPI_CHAR, dataO, 1, MPI_COMM_WORLD, &status);
        printf("Client 1 received response from Client 2: %s\n", reply);
        }
        MPI_Comm_disconnect(&comm1);
    }
    else if (rank == 2)
    {
        MPI_Status status;
        MPI_Recv(port2, MPI_MAX_PORT_NAME, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        /* make sure process 1 has time to do the connect before this process attempts to connect */
        sleep(2);
        MPI_Comm_connect(port2, MPI_INFO_NULL, 0, MPI_COMM_SELF, &comm2);
        MPI_Recv(&dataS, 1, MPI_INT, 0, 0, comm2, &status);
        if (dataS)
        {
            printf("\n\nClient 2 received peer's rank available from server: %d \n", dataS);
            char smt[80];
            
            sleep(2);
            MPI_Recv(&smt, 100, MPI_CHAR, dataS, 2, MPI_COMM_WORLD, &status);
            printf("Client 2 received message from Client 1: %s \n", smt );
            char bye[20] = "Bye";
            MPI_Send(&bye, 40, MPI_CHAR, dataS, 1, MPI_COMM_WORLD);
            printf("Client reply back to Client 1.\n");
        }
        
        MPI_Comm_disconnect(&comm2);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}