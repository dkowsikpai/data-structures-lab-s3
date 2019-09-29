#include <stdio.h>
#define MAX 10
 
int STACKA[MAX], top_a=-1;
 
void push(int data){
	if (top_a == MAX-1){
		printf("STACK A IS OVERFLOW");	
	} else {
		top_a++;
		STACKA[top_a] = data;
	}
}
 
void pop(){
	if (top_a == -1){
		printf("STACK A IS EMPTY");
	} else {
		printf("%d", STACKA[top_a]);
		top_a--;
	}
}
 
void display(){
	int temp = top_a;
	if (top_a == -1){
		printf("STACK A IS EMPTY");
	} else {
		for (; temp >=0; temp--){
			printf("%d ", STACKA[temp]);
		}
	}
}
 
 
void main(){
	int op, ex=0, data;
	while (1){
		if (ex == 1)break;
		printf("\n1. Push to STACKA\n2. Pop from STACKA\n3. Display FULL STACKA\n4. Exit\nEnter the option: ");
		scanf("%d", &op);
		switch (op){
			case 1: 
				printf("Enter the data: ");
				scanf("%d", &data);
				push(data);
				break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: ex = 1; break;
			default: printf("Invaid Option"); break;
		}
	}	
}
