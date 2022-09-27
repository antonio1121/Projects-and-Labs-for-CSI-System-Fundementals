#include <stdio.h>
#include <stdlib.h>

int main () {

	FILE *fp = fopen("word.txt" , "r");
	int linecount ;
	char filestore[300];

	if ( fp == NULL) {

		printf("Error opening file. ");
		exit(-1);
	}

	while ( fscanf(fp , "%s", filestore) != EOF) {
			printf("%s \n" , filestore);
	}

	fclose(fp);

	return 0 ;


}