#include<stdio.h>
#include<string.h>

int main () {
	int i, j ;
	char first[30] ;
	char last[30] ;
	char cat [60];

	printf("Enter first name: ") ;
	scanf("%29s", first) ;

	printf("Enter last name: ") ;
	scanf("%29s" , last) ;

	i = strlen(first);
	for (j = 0 ; last[j] != '\0' ; i++ , j++) {
		first[i] = last[j] ;
	}

	first[i] = '\0' ;

	printf("\n Concatenated string is : %s" , first) ;

	return 0 ;
}