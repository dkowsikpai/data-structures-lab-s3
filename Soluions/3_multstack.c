#include <stdio.h>
#define MAX 10
 
int STACK[MAX], top_a=-1, top_b=MAX;
// Stack A From the Front
void pushA(int data){
	if (top_a == top_b-1){
		printf("STACK A IS OVERFLOW");	
	} else {
		top_a++;
		STACK[top_a] = data;
	}
}
 
void popA(){
	if (top_a == -1){
		printf("STACK A UNDERFLOW");
	} else {
		printf("%d", STACK[top_a]);
		top_a--;
	}
}
 
void displayA(){
	int temp = top_a;
	if (top_a == -1){
		printf("STACK A IS EMPTY");
	} else {
		for (; temp >=0; temp--){
			printf("%d ", STACK[temp]);
		}
	}
}
// Stack B fro the Back
void pushB(int data){
	if (top_a == top_b-1){
		printf("STACK B IS OVERFLOW");	
	} else {
		top_b--;
		STACK[top_b] = data;
	}
}
 
void popB(){
	if (top_a == -1){
		printf("STACK B UNDERFLOW");
	} else {
		printf("%d", STACK[top_b]);
		top_b++;
	}
}
 
void displayB(){
	int temp = top_b;
	if (top_a == -1){
		printf("STACK B IS EMPTY");
	} else {
		for (; temp < MAX; temp++){
			printf("%d ", STACK[temp]);
		}
	}
}
 
void main(){
	int op, ex=0, data;
 
		printf("-------------MENU------------------");
	printf("\n1. Push to STACK A\n2. Push to STACK B\n3. Pop from STACK A\n4. Pop from STACK B\n5. Display FULL STACK A\n6. Display FULL STACK B \n7. Exit");
	while (1){
		if (ex == 1)break;
		printf("\nEnter the option: ");
		scanf("%d", &op);
		switch (op){
			case 1: 
				printf("Enter the data: ");
				scanf("%d", &data);
				pushA(data);
				break;
			case 2: 
				printf("Enter the data: ");
				scanf("%d", &data);
				pushB(data);
				break;
			case 3: popA(); break;
			case 4: popB(); break;
			case 5: displayA(); break;
			case 6: displayB(); break;
			case 7: ex = 1; break;
			default: printf("Invaid Option"); break;
		}
	}	
}
 
