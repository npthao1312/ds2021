#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int process_Rank, size_Of_Cluster, len;
    char message[1000];
    char name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);
    MPI_Get_processor_name(name, &len);
    
    FILE *fptr;
    if ((fptr = fopen("test.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline is encountered
    fscanf(fptr, "%[^\n]", message);
    //printf("Data from the file:\n%s\n", );
    fclose(fptr);

    if(process_Rank == 0){
    	//printf("Enter the message to sent: \n");
    	//scanf("%s",message);
        MPI_Send(&message, strlen(message), MPI_CHAR, 1, 1, MPI_COMM_WORLD);
        printf("Content of file test.txt sent from processor %s: %s\n", name, message);
    }

    else if(process_Rank == 1){
        MPI_Recv(&message, strlen(message), MPI_CHAR, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Content of file test.txt received from processor %s: %s\n", name, message);
    }

    MPI_Finalize();
    return 0;
}