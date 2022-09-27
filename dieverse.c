#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {

	srandom(time(NULL));

	int die = 0 ;

	int die2 = 0 ;

	double diesum = 0 ;

	double die2sum = 0 ;

	double fullsum = 0 ;

	double diePercent = 0 ;

	double diePercent2 = 0 ;

	int i = 0 ;

	int j = 0 ;

	float wait = 0 ;

	int one,two,three,four,five,six = 0 ;
	int one2,two2,three2,four2,five2,six2 =  0 ;

	printf("How many runs?: \n");
	scanf("%6i",&i);
	printf("How long of a wait between run intervals? (seconds) : \n");
	scanf("%f",&wait);
	fflush(stdout);

	 while (j != (i+1)) {

	 	fork();

	 	fork();

	 	fork();

	 	die = random() % 6 + 1 ;

	 	die2 = random() % 6 + 1 ;

	 	diesum = diesum + die ;

	 	die2sum = die2sum + die2 ;

	 	fullsum = diesum + die2sum ;

	 	diePercent = (diesum) / (fullsum) * 100 ;

	 	diePercent2 = (die2sum) / (fullsum) * 100 ;

	 	if(die==1){one++;}
	 	if(die2==1){one2++;}
	 	if(die==2){two++;}
	 	if(die2==2){two2++;}
	 	if(die==3){three++;}
	 	if(die2==3){three2++;}
	 	if(die==4){four++;}
	 	if(die2==4){four2++;}
	 	if(die==5){five++;}
	 	if(die2==5){five2++;}
	 	if(die==6){six++;}
	 	if(die2==6){six2++;}
	 	


	 	printf("|ROLL %i|\n\n", j);
	 	printf(" Die 1: %i\n Die 2: %i\n\n Die 1 Sum: %.0f\n Die 2 Sum: %.0f\n Die 1 Percent: %.6f %%\n Die 2 Percent: %.6f %%\n\n" , die ,die2 ,diesum, die2sum, diePercent, diePercent2);
	 	fflush(stdout);
	 	usleep(wait * 1000000);
	 	j++ ;

	 }

	 printf("\nThe total rolls are as follows: ");
	 printf("\nDie 1: \n1:%i\n2:%i\n3:%i\n4:%i\n5:%i\n6:%i\n\n", one,two,three,four,five,six);
	 printf("\nDie 2: \n1:%i\n2:%i\n3:%i\n4:%i\n5:%i\n6:%i\n\n", one2,two2,three2,four2,five2,six2);
	 fflush(stdout);

}