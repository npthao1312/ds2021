#define SIZE 1024

typedef opaque filebytes[SIZE];

struct file {
	char name[SIZE];
	filebytes data;
	int nbytes;
};

program TRANSFER {
	version TRANSFER_1 {
		int TRANSF(file) = 1;
	} = 1;
} = 0x31230000;
