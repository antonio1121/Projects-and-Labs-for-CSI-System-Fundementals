#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

/** ICSI 333. System Fundamentals, Spring 2022
 *  TA: Omkar Kulkarni
 *  Antonio Halkiadakis, 001485884
 *  Takes commandline arguements to move and copy files, giving back errors if the
 * user has done something wrong.
 * */

char *PATHING ;
char yn ;

int main(int argc,char *argv[]) {

	// Where the commandline arguements are taken in. The loop lasts longer if theres more files to move.
	// It also determines if the file compiled is "copy" or "move" to copy and move the files.


	void move(char *filename);

	void copy(char *filename);

	PATHING = argv[argc-1];

	char M[] = "./move" ;
	char C[] = "./copy" ;

	if(strcmp(M,argv[0])==0) {

		printf("Moving ");

		int i = 1 ;

		while (i!=(argc - 1)) {

			printf("%s, ", argv[i]);
			move(argv[i]);
			i++;
		}

		printf("to %s .\n",PATHING);
		fflush(stdout);


		// move 1 a.c 2 a.exe 3 dir 4
		// 0       1     2       3


		

	} else if (strcmp(C,argv[0])==0) {

		printf("Copying ");

		int j = 1 ;

		while (j!=(argc)) {

			printf("%s, ", argv[j]);
			copy(argv[j]);
			j++;
		}

		printf("to %s .\n", PATHING);
		fflush(stdout);


	} else {

		printf("\nPlease compile the file as \"move\" or \"copy.\"\n");
		exit(0);
	}

	return 0 ;


}

void copy(char *filename) {

	// Checks if the filename given is a real file, and copies into the path given by user.
	// If there is an overwrite, it asks the user first if they would like to do so.

	struct stat *buffer ;

	buffer = malloc(sizeof(struct stat));

	stat(filename,buffer);

	// printf("\ndir: %s\nfilename: %s\n",PATHING,filename);

	char concat[1024];

	sprintf(concat, "%s%s",PATHING,filename);

	// printf("\nConcat: %s\n",concat);


	if ((buffer -> st_mode & S_IFMT) == S_IFREG) {

		if (link(filename,concat)!=0) {

			char *errorstring = strerror(errno) ;

			if(strcmp(errorstring,"File exists")==0) {

				memset(&yn,'\0', sizeof(yn));

				printf("\nFile exists. Would you like to overwrite (y or n) ?: \n" );
				fflush(stdout);

				
				scanf("%c", &yn);

				if (yn == 'n') {

					printf("\nExiting... ");

					exit(0);
					
				} memset(&yn,'\0', sizeof(yn));

			}
		}

		link(filename,concat);

		//printf("\n%s\n",errorstring);

		//printf("link working?: %i\n",status);
		
	} else {

		free(buffer);

		char *errorstring = strerror(errno) ;

		if (strcmp(errorstring,"File exists")!=0) {

			perror("Error");

		}

		exit(1);
	}

		
}

void move(char *filename) {

	// Does the same thing as the copy function, except "deletes" the original location of the file.
	// The function is simple here because the error handling is done in the copy function. 

	copy(filename);
	unlink(filename);

}
