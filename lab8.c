#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#define PIPSIZE 4

int main(void) {

	int ping(int value);

	int pong(int value);

	int piip[2] ;
	int value = 0 ;
	int childvalue = 0 ;

	pid_t child ;

	int pstatus = pipe(piip);

	child = fork();

	if(pstatus == -1) {
		printf("Pipe did not work.\n");
		exit(1);
	}

	 while(value!=100) {



		if (child==0) {

			read(piip[1],&value, PIPSIZE);
			value = ping(value);

			write(piip[0],&value, PIPSIZE);
			close(pstatus);



		} else {

			read(piip[0],&value, PIPSIZE);
			value = pong(value);

		  	write(piip[1],&value, PIPSIZE);
		  	  wait(NULL);
		  	close(pstatus);

		  	if (value==100) {

		  		printf("Done.\n");
		  		exit(0);
		  	}

		  }

		  



	}

	return 0 ;
}

int ping(int input) {

	int value = 0 ;
	value = input + 1 ;
	usleep(500000);
	printf("Ping: %i\n",value);
	return value ;

}

int pong(int input) {

	int value = 0 ;
	usleep(500000);
	value = input + 1 ;
	printf("Pong: %i\n", value);
	return value ;
}