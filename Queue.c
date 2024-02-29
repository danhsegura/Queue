
// Simple Queue

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define FALSE 0



void insertNode(int data);
void printList();
void search(int data);
void delete_Node(int data);


struct node{

	int data;

	struct node *next; //Pointing at the same structure

};


struct node *head = NULL;
struct node *current = NULL;
struct node *tail = NULL;
struct node *previous = NULL;
struct node *auxiliarPointer = NULL;

int main(){

    int option;
    int value;
    int handledOption;

    do{
        printf("\n Menu");
        printf("\n 1. Add node");
        printf("\n 2. Print list");
        printf("\n 3. Search node");
        printf("\n 4. Remove node");
        printf("\n Choose an option: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            printf("\n Insert the node (number): ");
            scanf ("%d",&value);
            insertNode(value);
            break;
        
        case 2:

            printList();
            break;

        case 3:

            printf("\n Which node you want to search?: ");
            scanf ("%d",&value);
            search(value);
            break;

        case 4:

            printf("\n Which node you want to remove?: ");
            scanf ("%d",&value);
            delete_Node(value);
            break;

        default:
            printf("\n Wrong option!!!");
            break;
        }

        printf("\n Do you want to continue? \n 1. yes \n 2. No \n option: ");
        scanf("%d",&handledOption);


    }while(handledOption != 2);



    return 0;

}

void printList(){

    current = head;

    while(current != NULL){
        
        printf(" %d ->",*current);
        
        current = current -> next;
    }

    printf("\n");
}

void search(int data){

    current = head;

    bool bol = false;

    while(current != NULL && bol == false){

            if(current -> data == data){

                printf("Value: %d found in Queue",*current);
                
                bol = true;
            }

            current = current->next;
    }
    if(bol == false)

        puts("Value not found");
    }


//Insert node in LinkedList

void insertNode(int data){

	//Create Node (dynamically) with malloc
	struct node *new_node;

	new_node = malloc(sizeof(struct node)); //This line store the adress of struct Node

	new_node -> data = data;

	new_node -> next = NULL;


	if(head == NULL){ //List is Empty
		
        head = new_node;
		
        tail = new_node;
	}else{

		tail -> next = new_node;
		
        tail = new_node;
	}
}

void delete_Node(int data){

    current = head;

    previous = head;
    
    if(head -> data == data){
        
        head = head -> next;
        
        auxiliarPointer = current;

        free(auxiliarPointer);
        
        printList();
    
    }
    if(tail -> data == data){

        while(current != tail){
                
                previous = current;
                
                current = current -> next;
            }

        tail = previous;
    }
    if(tail -> data != data && head -> data != data){

            while(current -> data != data){

                previous = current;

                current = current -> next;
    }

    previous -> next = current -> next;
    
    free(current);
    
    printList();

  }
}
