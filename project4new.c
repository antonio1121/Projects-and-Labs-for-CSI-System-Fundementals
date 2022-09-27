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

/*
 *  ICSI 333. System Fundamentals,
 *  Spring 2022
 *  TA- Sourav
 *      Justin Moran
 *
 */


#define PORT 8000  // the port users will be connecting to
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define BACKLOG 10 // how many pending connections queue will hold

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

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

        pthread_t t;
        int *pclient = malloc(sizeof (int));
        *pclient = client;
        pthread_create(&t, NULL, connection_handle, pclient);

    }
    return 0;

}

int errorCheck(int exp, const char *msg) {
    if (exp == SOCKETERROR) {
        perror(msg);
        exit(1);

    }
    return exp;

}

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
    }

    close(client);
    close(fp);
    printf("Closing connection\n");
    return NULL;
}


