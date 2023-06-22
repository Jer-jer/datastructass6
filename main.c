#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularAQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue queue;
	int choice, i, value;
	bool checker;
	String menuOption[10] = {"Enqueue", 
							"Dequeue", "Is Empty", "Is Full", "Display", 
							"Visualize", "Front", "Remove Item", "Remove Uneven Values", 
							"Double Data"};
	
	initQueue(&queue);

// Needed for notes don't mind	
//	checker = enqueue(&queue, 10);
//	checker = enqueue(&queue, 69);
//	checker = enqueue(&queue, 5);
//	checker = enqueue(&queue, 89);
//	checker = enqueue(&queue, 100);
//	checker = enqueue(&queue, 50);
//	checker = enqueue(&queue, 5);
//	checker = enqueue(&queue, 3);
//	checker = enqueue(&queue, 2);
//	checker = enqueue(&queue, 6);
//	
//	displayQueue(queue);
//	
//	checker = removeItem(&queue, 5);
//	displayQueue(queue);
//	
//	queue = removeEven(queue);
//	displayQueue(queue);
//	
//	printf("Values that're a multiple of n: %d\n", doubleTheValue(&queue, 5));
//	displayQueue(queue);
	
	do {
		system("cls");
		printf("MENU\n");
		
		for(i = 0; i < 10; i++){
			printf("[%d] %s\n", i+1, menuOption[i]);
		}
		
		printf("Enter your choice <0 to EXIT>: ");
		scanf("%d", &choice);
				
		switch(choice){
			case 1:
				system("cls");
				printf("ENQUEUE\n\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				
				checker = enqueue(&queue, value);
				checker ? printf("Queue has been updated\n\n") : printf("Queue is full\n\n");
				break;
				
			case 2:
				system("cls");
				printf("DEQUEUE\n\n");
				
				checker = dequeue(&queue);
				checker ? printf("Queue has been updated\n\n") : printf("Queue is empty\n\n");
				break;
				
			case 3:
				system("cls");
				printf("IS EMPTY\n\n");
				
				checker = isEmpty(queue);
				checker ? printf("Queue is empty\n\n") : printf("Queue is not empty\n\n");
				break;
				
			case 4:
				system("cls");
				printf("IS FULL\n\n");
				
				checker = isFull(queue);
				checker ? printf("Queue is full\n\n") : printf("Queue is not yet full\n\n");
				break;
				
			case 5:
				system("cls");
				printf("DISPLAY QUEUE\n\n");
				
				displayQueue(queue);
				break;
				
			case 6:
				system("cls");
				printf("VISUALIZE QUEUE\n\n");
				
				visualize(queue);
				break;
				
			case 7:
				system("cls");
				printf("RETREIVE FRONT\n\n");
				
				value = front(queue);
				printf("The first in line: %d\n", value);
				break;
				
			case 8:
				system("cls");
				printf("REMOVE A SPECIFIC ITEM\n\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				
				checker = removeItem(&queue, value);
				checker ? printf("Item has been removed\n\n") : printf("Item has not been removed\n\n");
				break;
				
			case 9:
				system("cls");
				printf("REMOVED UNEVEN VALUES\n\n");
				
				queue = removeEven(queue);
				break;
				
			case 10:
				system("cls");
				printf("DOUBLE DATA THAT'S MULTIPLE OF N \n\n");
				printf("Enter the value of n: ");
				scanf("%d", &value);
				
				printf("Values that're a multiple of n: %d\n\n", doubleTheValue(&queue, value));
				break;
				
			case 0:
				printf("\nExiting...\n\n");
				break;
				
			default: 
				system("cls");
				printf("INVALID CHOICE\n\n");
		}
		system("pause");
	} while(choice != 0); 
	
	printf("BYE!!!!!!!!\n\n");
	
	return 0;
}
