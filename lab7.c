#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	void doList();

	void returnList();

	doList();

	returnList();

	return 0 ;

}

void doList() {

	int list[100] ;
	char string[20];

	int sum = 0 ;
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;

	srand(time(NULL)) ;

	while (i != 100) {

		list[i] = rand() % 100 ;
		i++ ;
	}

	while (j != 100) {

		sum = sum + list[j] ;
		j++ ;
	}
	printf("The sum of the number is %i. Printing file... \n", sum);
	fflush(stdout);
	sprintf(string, "numbers.%i.txt", sum);

	FILE *fPtr ;

	fPtr = fopen(string , "w");

	if(fPtr == NULL) {
		printf("Could not create file.\n");
	}


	while(k != 100) {

		fprintf(fPtr, "%i\n", list[k]);
		k++ ;

	}

	fclose(fPtr);

	printf("Done.\n\n");
	fflush(stdout);


}

void returnList() {

	int number = 0 ;
	char string[20];
	int list[100];
	char numstring[100];


	while (number != 10001) {

		sprintf(string, "numbers.%i.txt" , number);

		int sum =  0 ;
		int i = 0 ;

		if (fopen(string, "r") != NULL) {

			FILE *fp = fopen(string, "r");

			printf("Found a numbers file, the name is: %s \n\n" , string);
			fflush(stdout);

			while (fgets(numstring, sizeof(numstring), fp) != NULL) {

				list[i] = atoi(numstring);
				i++ ;

			}

			int k = 0 ;
			while (k != 100) {
				printf("%i ", list[k]);
				k++ ;
			}

			int l = 0 ;
			while (l != 100) {
				sum = sum + list[l] ;
				l++ ;		
			}

			printf("\n\nThe sum is %i.\n\n\n" , sum);

			fclose(fp);


		}

			number++ ;
			
	}



}

