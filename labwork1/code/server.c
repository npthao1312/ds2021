#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#define SIZE 1024

void write_file(int sockfd){
	int n;
	char buffer[SIZE];
	
	FILE *fp;
	fp = fopen("received_sample.txt","w");
	while (1){
		n = recv(sockfd, buffer, SIZE, 0);
		if (n <= 0){
			break;
			return;
		}
		fprintf(fp, "%s", buffer);
		bzero(buffer, SIZE);
	}
	return;
}

int main() {
    int ss, cli, pid;
    struct sockaddr_in ad;
    char s[100];
    socklen_t ad_length = sizeof(ad);

    // create the socket
    ss = socket(AF_INET, SOCK_STREAM, 0);

    // bind the socket to port 12345
    memset(&ad, 0, sizeof(ad));
    ad.sin_family = AF_INET;
    ad.sin_addr.s_addr = INADDR_ANY;
    ad.sin_port = htons(12345);
    bind(ss, (struct sockaddr *)&ad, ad_length);

    // then listen
    listen(ss, 0);

    while (1) {
        // an incoming connection
        cli = accept(ss, (struct sockaddr *)&ad, &ad_length);

        pid = fork();
        if (pid == 0) {
            printf("client connected\n");
            write_file(cli);
            printf("Received file.");
            return 0;
        }
        else {
            // continue the loop to accept more clients
            continue;
        }
    }
    
    // disconnect
    close(cli);

}
