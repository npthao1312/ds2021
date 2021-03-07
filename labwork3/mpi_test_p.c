#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    int noProc, idProc;
	char inmsg, outmsg = 'x';
	int dest, source,tag = 2;
	MPI_Status Stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &noProc);
	MPI_Comm_rank(MPI_COMM_WORLD, &idProc);

	if(idProc == 0)
	{
		// from 0 to 1
		dest = 1;
		source = 1;
		MPI_Send(&outmsg,1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
                //nhan du lieu 'y' tu tac vu co id = 1
		MPI_Recv(&inmsg,1,MPI_CHAR,source,tag,MPI_COMM_WORLD,&Stat);
		printf("ProcessID: %d, Message: %c\n",idProc,inmsg);
	}
	if(idProc == 1)
	{
		source = 0;
		dest = 0;
		MPI_Recv(&inmsg,1,MPI_CHAR,0, 0,MPI_COMM_WORLD,&Stat);
		printf("ProcessID: %d, Message: %c\n",idProc,inmsg);
	}

	MPI_Finalize();
	return 0;
}