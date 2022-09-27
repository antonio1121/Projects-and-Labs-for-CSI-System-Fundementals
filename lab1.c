#include <stdio.h>

int main(void) {

	int dividend, divisor, quotient, remainder ;

	printf("\nWhat is the dividend?: ");
	fflush(stdout);

	scanf("%i", &dividend);

	printf("\nWhat is the divisor?: ");
	fflush(stdout);

	scanf("%i", &divisor);

	quotient = dividend / divisor ;

	remainder = dividend % divisor ;

	printf("\n%i divided by %i equals %i, with a remainder of %i.\n\n", dividend, divisor, quotient, remainder);
	fflush(stdout);

}