#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct node {
	
	int value;
	struct node *next;
};

int main(void) {
	
	
	void print_list(struct node*);
	
	void insert_node(struct node**, struct node**, int x);
	
	struct node *last_occur (struct node *h, int x);

	void delete_node (struct node **ph, int x);

	struct node *head, *tail;
	int i;
	int eight = 8 ;
	struct node *lo ; 
	head = tail = NULL;
	i = 0;
	srand(time(NULL));

	while (i != 8) {
	
		i = rand () % 25 ;
		if (i == 8)	{
		break;
		} else {
				insert_node(&head, &tail, i);
		}

	}
	*lo = *last_occur(head,5);
	if (lo != NULL) {

		printf("Last occuring number 5 is at memory address: %p\n" , lo );
		fflush(stdout);
	} else {
		printf("There is no 5 stored in the list. ");
	}
	// delete last node since it contains 8

	
	print_list(head);
	void delete_node(head,eight);
	printf("Printing without the number 8: ");
	print_list(head);
	return 0;
	
}	

void insert_node (struct node **h, struct node **t, int v) {

	
	struct node *temp;
	if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL) {
		printf("Node allocation failed. \n");
		exit(1); 
	}
	
	
	temp->value = v; temp->next = NULL;
	if (*h == NULL) {
		
		
		*h = *t = temp;
	}
	
	else { 

		(*t)->next = temp; *t = (*t)->next;
	}
	
} 

void print_list(struct node *h) {
	
	if (h == NULL) {
		printf("The list is empty.\n");
	}
	
	else {
		
		printf("Values in the list are:\n");
		while (h != NULL) {
			printf("%d\n", h->value);
			h = h->next;
		}
	}
}

struct node *last_occur (struct node *h, int x) {
	while (h->value != x) {
		h = h -> next ;
	}
	if (h->value == x) {
		return h ;
	} else {
		printf("Value not found.");
	}
}

void delete_node (struct node **ph, int x) {

	struct node *temp = *ph, *previous ;

	if (temp != NULL && temp->value == x) {
		*ph = temp->next ;
		free(temp);
	}

	while (temp != NULL && temp->value != x) {
		previous = temp ;
		temp = temp->next ;
	}

	if (temp == NULL) {
		printf("The value does not exist in the list. ");
		fflush(stdout);
	}

	previous -> next = temp -> next ;
	free(temp);

}