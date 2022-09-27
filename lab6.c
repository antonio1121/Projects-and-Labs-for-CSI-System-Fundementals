#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

	printf("This program has %d arguments\n",argc);

	for(int i = 0; i<=argc; i++) {

		printf("argv [ %d ] = %s\n",i, argv[i]);
	}

	if (argc == 2 ) {

		int decimal = atoi(argv[1]);
		printf("%d", decimal);
		int j = 0 ;
		int count = 0 ;

		while (j<=7) {

	
			if (decimal & 1) {
				

				count++ ;

			}
			decimal >>= 1 ;
			j++ ;
		}

		printf("\nYour number is %d and there are %d bits set to 1.", decimal, count);

	}		

	return 0;

}