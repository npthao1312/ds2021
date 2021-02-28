#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#define SIZE 1024

void write_file(char* content){
	FILE *fp;
	fp = fopen("sample.txt", "w");
	fprintf(fp, content);
	fclose(fp);
}

void send_file(FILE *fp, int sockfd){
    int n;
    char data[SIZE] = {0};

    while (fgets(data, SIZE, fp) != NULL){
    	if (send(sockfd, data, sizeof(data), 0) == -1){
			perror("Can't send the file!");
			exit(1);
		}
		bzero(data, SIZE);
    }
}

int main(int argc, char* argv[]) {
    int so;
    char s[100];
    FILE *fp;
    struct sockaddr_in ad;

    socklen_t ad_length = sizeof(ad);
    struct hostent *hep;

    // create socket
    int serv = socket(AF_INET, SOCK_STREAM, 0);

    // init address
    hep = gethostbyname(argv[1]);
    memset(&ad, 0, sizeof(ad));
    ad.sin_family = AF_INET;
    ad.sin_addr = *(struct in_addr *)hep->h_addr_list[0];
    ad.sin_port = htons(12345);

    // connect to server
    connect(serv, (struct sockaddr *)&ad, ad_length);

    while (1) {
        // after connected, client will generate a file contain message
        printf("Message to write to the file: ");
        gets(s);
        write_file(s);
        
        // read generated file
        fp = fopen("sample.txt", "r");
        if (fp == NULL){
        	perror("Error in reading file.");
        	exit(1);
        }

        // send file to the server
        printf("Sending file...\n");
		send_file(fp, serv);
		printf("Sent successfully.\n");

        // then close connection
		close(serv);

		return 0;
    }
}

