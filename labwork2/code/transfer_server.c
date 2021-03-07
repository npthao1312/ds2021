/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "transfer.h"

char opened_file[SIZE];
FILE *fp;
long long int total = 0;

int *
transf_1_svc(file *argp, struct svc_req *rqstp)
{
	static int  result;
	
	/*
	 * insert server code here
	*/
	static char temp[SIZE];

	total += argp->nbytes;

	if (strcmp(opened_file, "") == 0 && fp == NULL) {
		printf("Receiving new file %s.\n", argp->name);

		strcpy(opened_file, argp->name);
		fp = fopen("received_sample", "ab+");
	}
	if (strcmp(opened_file, argp->name) == 0) {
		fflush(stdout);

		fwrite(argp->data, 1, argp->nbytes, fp);

		if (argp->nbytes < SIZE) {
			printf("\nFinished receiving %s.\n", argp->name);
			total = 0;
			fclose(fp);
			fp = NULL;
			strcpy(opened_file, "");
		}
	}

	return &result;
}
