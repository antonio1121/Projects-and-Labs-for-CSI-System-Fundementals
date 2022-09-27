/** ICSI 333. System Fundamentals, Spring 2022
 *  TA: Omkar Kulkarni
 *  Antonio Halkiadakis, 001485884
 * Evaluates an expression from left to right then converts it to a
 * different base system number.
 * */



#include <stdio.h>
#include<string.h>

int mathOp(int first, int second, char operate){
// Does the math when an operator appears in the expression. Takes the first number, then second, then an operand to evaluate.
	int result = 0;
	switch(operate) {
		case '+':
		result= first + second ;
		break;
		case '-':
		result= first - second ;
		break;
		case '*':
		result = first * second ;
		break;
		case '/':
		result= first / second ; 
	}
	return result;
}

int skipWhiteSpace(char numArray[], int i, int length) {

	// Looks for blank characters to skip for in the expression represented by the char array.

	while(numArray[i]==' '|| numArray[i]=='\t')
	i++;
	return i;
}

int numtoAscii(char c)

//Converts numbers above 10 to letters if the radix is above 10.

{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}


static char reVal(int num)

// returns a character based on the value that it is provided

    {
        if (num >= 0 && num <= 9)
            return(char)(num + '0');
        else
            return(char)(num - 10 + 'A');
    }

    char *strrev(char *str)

    // function that reverses an array of characters.
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

  char res[] = "\0";

static void convertBase(int base2, int inputNum)

// Converts a decimal number into a base system of your choosing, asking for the number and then radix.

    {
         
        while (inputNum > 0)
        {

            inputNum = inputNum / base2;
        }
        strrev(res);
    }


int main()

{
	/** Asks for expression, evaluates the math with consideration for
	 * whitespaces until it reaches the end. Then asks user for what base
	 * number system to convert the evaluated expression to, and prints it
	 * out.
	 * */

	char numArray[80] = {'\0'};
	printf("Enter expression: ");
	fgets (numArray, 80, stdin);
	fflush(stdout);
	int length = strlen(numArray);
	int i, result;
	int boolean = 1;
	if(length == 1)
	printf("Result: %c\n",numArray[0]);
	else{
		
		for(i=0; i < length;) {
			
			
			i = skipWhiteSpace(numArray, i, length);
			if(i >= length) 
			break;
			
			int first;
			if(boolean){
				first = numArray[i++] - '0';
				boolean = 0;
			}else{
				first= result;
			}
			
		
			i = skipWhiteSpace(numArray, i, length);
			if(i >= length) 
			break;
			
			char operate = numArray[i++];
			
			
			i = skipWhiteSpace(numArray, i, length);
			if(i >= length)
			break;
			
			int second = numArray[i++] - '0';
			result = mathOp(first, second, operate);
		}
	}

	int arrtoInt(char arr[]) {

		// Converts a character array into an integer.

		int i = 0 ;
		signed int k = 0 ;
		for (i = 0 ; i < strlen(arr) ; i++) {
			k = 10 * k + arr[i];
		}
		return k ;
	}

	int radix ;

	printf("Result: %d\n",result);
	fflush(stdout);

	printf("Enter input radix (between 2 and 16) : \n");
	fgets ((int) radix, 3, stdin);
	fflush(stdout);


	int arraytoInt = arrtoInt(numArray);
	convertBase(radix,arraytoInt);
	printf("The answer is: %s", res);
	fflush(stdout);

	return 0;
}