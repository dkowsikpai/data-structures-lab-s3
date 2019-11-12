#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *ptr;
}*top, *top1, *temp;

void create(){
	top = NULL;
}

void push(int data){
	if (top == NULL){
		top = (struct Node*)malloc(sizeof(struct Node));
		top->ptr = NULL;
		top->data = data;
	} else {
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->ptr = top;
		top = temp;
	}
}

void display(){
	top1 = top;
	if(top == NULL)
		printf("Empty");
	else{
		while (top1 != NULL){
			printf("%d->", top1->data);
			top1 = top1->ptr;
		}
	}
}

void pop(){
	top1 = top;
	if (top == NULL)
		printf("empty");
	else {
		printf("Deleted data: %d", top->data);
		top = top->ptr;
		free(top1);
	}

}


void main(){
	int op, data;
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
	do{
		printf("\nEnter the choice: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	}while(op != 4);
}
