#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 128
#define PORT 1369
#define SA struct sockaddr

void clisten(int connfd) {

	char buffer[MAX];
	
	while (1) {
		memset(buffer,0,MAX);
		
		
		read(connfd, buffer, sizeof(buffer));
		//sleep(1);
		
		printf("From client: %s\t To client : ", buffer);
		memset(buffer,0,MAX);

		char buffer[] = "pong\0" ;

		write(connfd, buffer, sizeof(buffer));

		
		if (strncmp("exit", buffer, 4) == 0) {

			printf("Server Exit...\n");
			break;
		}
	}
}


int main()
{
	void clisten(int connfd);

	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;


	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	memset(&servaddr,0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");


	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);


	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server accept failed...\n");
		exit(0);
	}
	else
		printf("server accept the client...\n");

	clisten(connfd);

	close(sockfd);
}
