#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>

#define PORT 8000  // the port users will be connecting to
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define BACKLOG 10 // how many pending connections queue will hold

/*
 *	ICSI 333. System Fundamentals,
 *	Spring 2022
    TA Omkar Kulkarni
 *	TA- Sourav
 *  	Justin Moran, ID- 001489066,  Antonio Halkiadakis, ID- 001485884
 *	
 */

/* In this program we created a simple web server in c. We do this by connection
 * to a port and listen to the request and sends the file back to the requester.
 * Using HTTP level protocal  to interact to interact with with web resources.
 * The web server is using TCP connection.
 */

/* Team work load distribution.
 * 
 * Justin- created the functions, connection handle, error check, 
 * Antonio- Managed system calls, other error handling, printing out file to local server
 */

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

// Functions for error checking and for 
void * connection_handle(void* pclient_socket);
int errorCheck(int exp, const char *msg);

int main(int argc, char *argv[]) {
    int server, client, addr_size;
    SA_IN server_addr, client_addr;

    errorCheck((server = socket(AF_INET, SOCK_STREAM, 0)), "connection failed");

    // the address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
// call to the error checking method for binding and for listening.
    errorCheck(bind(server, (SA*) & server_addr, sizeof (server_addr)), "bind failed");
    errorCheck(listen(server, BACKLOG), "listen failed");

    while (true) {
        printf("Waiting for the connection ... \n");

        // waiting for the connection

        addr_size = sizeof (SA_IN);

        errorCheck(client =
                accept(server, (SA*) & client_addr, (socklen_t*) & addr_size),
                "accept fail");
        printf("connected \n");

        // Create the p-thread and allocate memory.
        pthread_t t;
        int *pclient = malloc(sizeof (int));
        *pclient = client;
        pthread_create(&t, NULL, connection_handle, pclient);

    }
    return 0;

}

// In this function this handles the error messages and returns exp.

int errorCheck(int exp, const char *msg) {
    if (exp == SOCKETERROR) {
        perror(msg);
        exit(1);

    }
    return exp;

}

// In this function this is where the content of the file is read to the client 
// and print the content to the server terminal.

void * connection_handle(void* pclient) {
    int client = *((int*) pclient);
    free(pclient);
    char buffer[BUFSIZE];
    size_t Bread;
    int Msize = 0;
    char ch;

    // read the client  message

    while ((Bread = read(client, buffer + Msize, sizeof (buffer) - Msize - 1)) > 0) {
        Msize += Bread;
        if (Msize > BUFSIZE - 1 || buffer[Msize - 1] == '\n')break;

    }
    
    // checks for the rec error
    errorCheck(Bread, "rec error");
    buffer[Msize - 1] = 0; // null terminater
    printf("Request: %s\n", buffer);
    fflush(stdout);

// test file is foo
   // FILE *fp = fopen("foo.txt", "r");

   // if (fp == NULL) {
     //   printf("error (open):%s\n", buffer);
     //   close(client);
      //  return NULL;

    int fp = open("foo.txt", O_RDONLY);
        if (fp == -1) {
            
            perror("Error 404");
            exit(1);
        }

    

    // read the file and sends it to the client

        

    while ((Bread = read(fp, buffer, BUFSIZE)) > 0) {

        printf("HTTP/1.0 200 OK \n");
        printf("content-length: %zu \n", Bread);
       // printf("%s\n", buffer);
        printf("\n");
        printf("File opened successfully. Reading file contents character by character. \n\n");


       write(client, buffer, Bread);
      // read(fp,buffer,BUFSIZE);
       printf("%s\n\n", buffer);
       fflush(stdout);
    }
    
// closes the file and closes the client connection
    close(client);
    close(fp);
    printf("Closing connection\n");
    fflush(stdout);
    return NULL;
}

