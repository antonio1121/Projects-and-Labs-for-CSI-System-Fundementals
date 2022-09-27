#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

float BET ;

int main(void) {

	void win(float win, float lose);

	srandom(time(NULL));

	int die = 0 ;

	int die2 = 0 ; 

	int die3 = 0 ;

	int tdie = 0 ;

	int tdie2 = 0 ;

	int tdie3 = 0 ;

	float wait = 0.3 ; // seconds

	char filler ;

	float bal ;

	float bal2 ;

	char name[64] ;

	char name2[64] ;

	// printf("How long of a wait between run intervals? (seconds) : \n");
	// scanf("%f",&wait);

	printf("Player 1 name: ");
	scanf("%s",name);

	printf("\nPlayer 2 name: ");
	scanf("%s",name2);

	printf("Betting amount each round: ");
	scanf("%f",&BET);

	printf("\nAfter each roll, type anything and  press 'enter' to go into the next round.");

	fflush(stdout);

	while (1) {

		die = random() % 6 + 1 ;

		die2 = random() % 6 + 1 ;

		die3 = random() % 6 + 1 ;

		tdie = random() % 6 + 1 ;

		tdie2 = random() % 6 + 1 ;

		tdie3 = random() % 6 + 1 ;

		// CHECK

		switch(die) {

			case 1:
			case 2:
			case 3:

			switch(die2) {

				case 1:
				case 2:
				case 3:

				switch(die3) {

					case 1:
					case 2:
					case 3:


				}

			}
	
		}





		printf("\nRolled a: %i", die);
		fflush(stdout);

		usleep(wait * 1000000);
		printf(" %i", die2);
		fflush(stdout);

		usleep(wait * 1000000);
		printf(" %i\n", die3);
		fflush(stdout);


		printf("\nOther person rolled a: %i", tdie);
		fflush(stdout);

		usleep(wait * 1000000);
		printf(" %i", tdie2);
		fflush(stdout);

		usleep(wait * 1000000);
		printf(" %i\n", tdie3);
		fflush(stdout);

		scanf(" %c",&filler);

		// scanf("%[^\n]", filler);
		//getchar();    

	}

}

	void win(float win, float lose) {

		win = win + BET ;

		lose = lose - BET ;

	}

