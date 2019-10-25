#include <stdio.h>
#define SIZE 20

int q[SIZE], front = -1, rear = -1;

void insert(int x){
	if (rear == SIZE-1) puts("\nQueue Overflow");
	else{
		if (front == -1){
			rear = 0;
			front = 0;
		} else {
			rear++;
		}
		q[rear] = x;
	}
}


void delete(){
	int x;
	if (front == -1 || front > rear)puts("\nQueue Underflow");
	else {
		printf("%d", q[front]);
		front++;
	}
}

void display(){
	int i;
	if (front == -1)puts("Queue Empty");
	else{
		for (i=front; i<=rear; i++)printf("%d->", q[i]);
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
