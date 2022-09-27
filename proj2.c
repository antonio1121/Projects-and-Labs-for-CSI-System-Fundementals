/** ICSI 333. System Fundamentals, Spring 2022
 *  TA: Omkar Kulkarni
 *  Antonio Halkiadakis, 001485884
 *  Takes commands from the user to be implemented in a 
 * linked list.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// temporary storage for user input

char cmd[4] ;
int number;
char name[255];

// node structure for linked list

struct node {

   char* data;
   int index;
   struct node *next;

};

struct node *head = NULL;
struct node *current = NULL;

// Displays the list
void printList() {

   struct node *ptr = head;

   printf("\n");
	
   while(ptr != NULL) {
      printf("%d %s \n" , ptr->index, ptr->data);
       fflush(stdout);
      ptr = ptr->next;
   }
	
   printf(" ");
}

// inserts into the linked list after a certain index (buggy(?))
void insertA(char* data, int index) {

	struct node *link = (struct node*) malloc(sizeof(struct node));

	struct node *ptr = head;
	
   while(ptr != NULL) {
      if(link->index < index) {

      	link->index = link->index + 1 ;

      	link->data = data ;


      }
       
      ptr = ptr->next;
   }

	//link->data = data ;

	//link->next = NULL ;

}

// Inserts into the linked list before an index.

void insertBefore(char* data, int index) {

   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->index = index ; 	

   link->data = data ;
	
   link->next = head ;
	
   head = link ;
}


// Replaces a phrase at an index.

void replace(int index, char* data) {

   struct node* current = head;

   if(head == NULL) {

      printf("List is empty.");
      fflush(stdout);

   }

   while(current->index != index) {

      if(current->next == NULL) {

         printf("Could not be found?");

         fflush(stdout);

      } else {

         current = current->next;
      }
   }      
	
   current-> data = data ;
}

// Deletes a phrase at an index.

struct node* delete(int index) {

   struct node* current = head;
   struct node* previous = NULL;
	
   if(head == NULL) {

      return NULL;
   }

   while(current->index != index) {

      if(current->next == NULL) {

         return NULL;

      } else {

         previous = current;

         current = current->next;
      }
   }


   if(current == head) {

      head = head->next;

   } else {

      previous->next = current->next;
   }    
	
   return current;
}

//Takes in user input according to specifications.

void read() {

	printf("\nPlease enter a command: ");
	scanf("%4s %d %255s" , &cmd , &number , &name);
	fflush(stdout);
}

//Checks what the user input is and decides accordingly what function to run.

void check() {

	char ina[] = "ina" ;
	char inb[] = "inb" ;
	char del[] = "del" ;
	char rep[] = "rep" ;
	char prn[] = "prn" ;
	char end[] = "end" ;

	if (strcmp(ina, cmd) == 0) {

		insertA(name,number);
		printf("\nOK");
		fflush(stdout);

	} else if (strcmp(inb, cmd) == 0) {

		insertBefore(name,number);
		printf("\nOK");
		fflush(stdout);

	} else if (strcmp(del, cmd) == 0) {

		delete(number);
		printf("\nOK");
		fflush(stdout);

	} else if (strcmp(rep, cmd) == 0) {

		replace(number,name);
		printf("\nOK");
		fflush(stdout);

	} else if (strcmp(prn, cmd)  == 0) {

		printList();

	} else {

		printf("Please enter correctly.");
		fflush(stdout);

	}

}

/** Runs an infinite loop, checking for the end phrase, allowing
 *  for user input into the list. For some reason, it sometimes
 *  asks for input twice.
 * */

int main () {

 while (strcmp("end", cmd) != 0) {

 	if (strcmp("end", cmd) == 0) {

 		printf("Ending program");
		exit(0);
 	}

 	read();
	check();

	} 

	return 0 ;
}
