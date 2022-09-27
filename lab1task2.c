#include <stdio.h>
int main()
{
	int dividend;
	int divisor;
	int quotient;
	int remainder;

	printf("Enter dividend: \n");
	scanf("%d" , &dividend);
	printf("Enter divisor: \n");
	scanf("%d" , &divisor);

	quotient = dividend / divisor ;
	remainder = dividend % divisor ;

	printf("The quotient is %d and the remainder is %d. " , quotient, remainder);

	return 0 ;
}