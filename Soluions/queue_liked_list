#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *ptr;
}*front, *rear, *front1, *temp;

void create(){
	front = NULL;
}

void enq(int data){
	if (rear == NULL){
		rear = (struct Node*)malloc(sizeof(struct Node));
		rear->ptr = NULL;
		rear->data = data;
		front = rear;
	} else {
		temp = (struct Node*)malloc(sizeof(struct Node));
		rear->ptr = temp;
		temp->data = data;
		temp->ptr = NULL;
		rear = temp;
	}
}

void display(){
	front1 = front;
	if(front != rear && rear == NULL)
		printf("Empty");
	else{
		while (front1 != NULL){
			printf("%d->", front1->data);
			front1 = front1->ptr;
		}
	}
}

void deq(){
	front1 = front;
	if (front1 == NULL)
		printf("empty");
	else {
		printf("Deleted data: %d", front->data);
		front = front->ptr;
		free(front1);
	}

}


void main(){
	int op, data;
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
	create();
	do{
		printf("\nEnter the choice: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				enq(data);
				break;
			case 2:
				deq();
				break;
			case 3:
				display();
				break;
		}
	}while(op != 4);
}
