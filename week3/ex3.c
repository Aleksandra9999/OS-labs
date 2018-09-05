#include <stdio.h>

#include <stdlib.h>



struct node {

   int data;

   struct node *next;

};



struct node *head = NULL;


void printList() {

   struct node *temp = head;

	
   while(temp != NULL) {

      printf("%d ", temp->data);

      temp = temp->next;

   }

}



void insert_in_head(int new_data) {

    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data  = new_data;

    new_node->next = head;

    head = new_node;

}




void insert_after_elem(struct node* prev, int new_data) {

    struct node* new_node =(struct node*)malloc(sizeof(struct node));

    new_node->data  = new_data;

    new_node->next = prev->next;

    prev->next = new_node;

}




void delete_elem(int value) {


   struct node* current = head;

   struct node* previous = NULL;


   if(head == NULL) {

      return;

   }


   while(current->data != value) {


      if(current->next == NULL) {

      	return;

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
}



int main(){

	insert_in_head(5);

	insert_in_head(6);

	insert_in_head(7);

	insert_after_elem(head, 8);

	insert_after_elem(head->next, 9);

	printList();

	printf("\n");

	
delete_elem(5);

	
printList();

	
return 0;

}