#include <stdio.h>
int main()
{
	int a ;
	int b ;
	int *c = &a;
	int *d = &b;
	a = 2 ;
	*d = 3 ;
	printf("%d" , a);
	printf("%d" , b);
	printf("%d" , *c);
	printf("%d" , *d);
	return 0 ;
		
}