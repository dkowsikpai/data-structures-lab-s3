#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

int isFull(){
	if (front == rear+1 || (front == 0 && rear == SIZE -1)) return(1);
	else return(0);
}

int isEmpty(){
	if (front == -1) return(1);
	else return(0);
}

void insert(int x){
	if (isFull()) puts("\nQueue Overflow");
	else{
		if (front == -1){
			front = 0;
		}
		rear = (rear+1)%SIZE;
		q[rear] = x;
	}
}


void delete(){
	int x;
	if (isEmpty())puts("\nQueue Underflow");
	else {
		if(front == rear){
			front = -1;
			rear = -1;
		}
		printf("%d", q[front]);
		front = (front + 1)%SIZE;
	}
}

void display(){
	int i;
	if (front == -1)puts("Queue Empty");
	else{
		printf("Front->");
		for (i=front; i!=rear; i=(i+1)%SIZE)printf("%d->", q[i]);
		printf("%d<-Rear", q[rear]);
		
	}
}

void main(){
	int op, x;
	do{
		puts("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
		scanf("%d", &op);
		switch(op){
			case 1:
				puts("\nEnter the element: ");
				scanf("%d", &x);
				insert(x);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			default: break;
		}
	}while (op!=4);
}
