#include <stdio.h>
int evaluate(char operator, int x, int y)

{
	switch(operator)
	{

		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;

	}

	return 0;
}

int main()

{
	char exp[80];
	printf("Enter the expression: ");
	scanf("%s", exp);
	int result, operand = 0;
	char *expression = exp, operator;
	char ch = *expression;
	result = ch - '0';
	expression++;
	while(*expression != '\0')
	{
		char ch = *expression;

		switch(ch)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': result = evaluate(operator, result, ch-'0'); break;
			case '+': operator = '+'; break;
			case '-': operator = '-'; break;
			case '*': operator = '*'; break;
			case '/': operator = '/'; break;
		}
		expression++;
		printf("%d ", result);
	}
	printf("The result of the expression is: %d\n", result);
}