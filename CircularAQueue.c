#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularAQueue.h"

void initQueue(Queue *q){
	q->front = 7;
	q->rear = 6;
	
	for(int i = 0; i < MAX; i++){
		q->elems[i] = EMPTY;
	}
}

bool isFull(Queue q){
	return (q.rear + 2) % MAX == q.front;
}

bool isEmpty(Queue q){
	return (q.rear + 1) % MAX == q.front;
}

bool enqueue(Queue *q, int item){
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->elems[q->rear] = item;
		
		return true;
	}
	 
	return false;
}

bool dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->elems[q->front] = EMPTY;
		q->front = (q->front + 1) % MAX;
		
		return true;
	}
	
	return false;
}

int front(Queue q){
	if(!isEmpty(q)){
		return q.elems[q.front];
	}
	
	return EMPTY;
}

void displayQueue(Queue q){
	printf("%5s | %5s \n", "INDEX", "VALUE");
	printf("--------------------------\n");
	
	while(!isEmpty(q)){
		int value = front(q), i = q.front;
		
		printf("%5d | ", i);
		
		if(value != EMPTY){
			printf("%5d | ", value);
		}
		
		bool checker = dequeue(&q);
		
		if(checker) i = (i + 1) % MAX;
		
		printf("\n");
	}
	
	printf("--------------------------\n");
}

void visualize(Queue q){
	printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
	printf("--------------------------\n");
	
	for(int i = 0; i < MAX; i++){
		printf("%5d | ", i);
		
		if(q.elems[i] != EMPTY){
			printf("%5d | ", q.elems[i]);
		}else{		
			printf("%5s | ", " ");	
		}
		
		if(i == q.front){
			printf("Front");
		}
		
		if(i == q.rear){
			printf("Rear");
		}
		
		printf("\n");
	}
	printf("--------------------------\n");
}

bool removeItem(Queue *q, int item) {
	Queue tempQ;
	bool checker;
	
	tempQ.front = q->front;
	tempQ.rear = q->front - 1;
	
	// could use init function but starting front and rear might now be the same when this function is called
	for(int i = 0; i < MAX; i++){
		tempQ.elems[i] = EMPTY;
	}
	
	while(!isEmpty(*q)){
		int value = front(*q);
		
		checker = dequeue(q);
		
		if(checker) {
			if(value == item){
				item = EMPTY;
			}else{
				enqueue(&tempQ, value);
			}
		}
		
	}
	
	checker = (q->rear != tempQ.rear) ? true : false;
	*q = tempQ;
	
	return checker;
}
Queue removeEven(Queue q) {
	Queue tempQ;
	
	tempQ.front = q.front;
	tempQ.rear = q.front - 1;
	
	for(int i = 0; i < MAX; i++){
		tempQ.elems[i] = EMPTY;
	}
	
	while(!isEmpty(q)){
		int value = front(q);
		
		bool checker = dequeue(&q);
		
		if(checker){
			if(value%2 == 0){
				enqueue(&tempQ, value);
			}
		}
	}
	
	return tempQ;
}
int doubleTheValue(Queue *q, int value) {
	Queue tempQ;
	int counter = 0, head = q->front;
	
	tempQ.front = q->front;
	tempQ.rear = q->front - 1;
	
	for(int i = 0; i < MAX; i++){
		tempQ.elems[i] = EMPTY;
	}
	
	while(!isEmpty(*q)){
		int item = front(*q);
		
		bool checker = dequeue(q);
		
		if(checker) {
			if(item % value == 0){
				item*=2;
				counter++;
			}			
		}
		

		
		enqueue(&tempQ, item);
	}
	
	*q = tempQ;
	
	return counter;
}
