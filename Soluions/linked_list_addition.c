#include <stdio.h>
#include <stdlib.h>

struct Node {
	int pow, coeff;
	struct Node* next;
};

void createnode(int x, int y, struct Node **temp){
	struct Node *r, *z;
	z = *temp;
	if (z == NULL){
		r = (struct Node*)malloc(sizeof(struct Node));
		r->coeff = x;
		r->pow = y;
		*temp = r;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	} else {
		r->coeff = x;
		r->pow = y;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
}

void display(struct Node *node) 
{ 
while(node->next != NULL) 
    { 
    printf("%dx^%d", node->coeff, node->pow); 
    node = node->next; 
    if(node->next != NULL) 
        printf(" + "); 
    } 
} 
  

void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly){ 
    while(poly1->next && poly2->next){ 
            // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
            // and move its pointer 
            if(poly1->pow > poly2->pow) { 
                poly->pow = poly1->pow; 
                poly->coeff = poly1->coeff; 
                poly1 = poly1->next; 
            } 
              
            // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
            // and move its pointer 
            else if(poly1->pow < poly2->pow) { 
                poly->pow = poly2->pow; 
                poly->coeff = poly2->coeff; 
                poly2 = poly2->next; 
            } 
              
            // If power of both polynomial numbers is same then add their coefficients 
            else  { 
                poly->pow = poly1->pow; 
                poly->coeff = poly1->coeff+poly2->coeff; 
                poly1 = poly1->next; 
                poly2 = poly2->next; 
            } 
              
            // Dynamically create new node 
            poly->next = (struct Node *)malloc(sizeof(struct Node)); 
            poly = poly->next; 
            poly->next = NULL; 
        } 
    while(poly1->next || poly2->next) { 
            if(poly1->next) { 
                poly->pow = poly1->pow; 
                poly->coeff = poly1->coeff; 
                poly1 = poly1->next; 
            } 
            if(poly2->next) { 
                poly->pow = poly2->pow; 
                poly->coeff = poly2->coeff; 
                poly2 = poly2->next; 
            } 
            poly->next = (struct Node *)malloc(sizeof(struct Node)); 
            poly = poly->next; 
            poly->next = NULL; 
        } 
} 


void main(){
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    int n, pow, coe, i;
    printf("Enter the number of elements in Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter data in space seperated format. Each element in each line. Coeff <space> power\n");
    for (i=1; i<=n; i++){
        scanf("%d %d", &coe, &pow);
        createnode(coe, pow, &poly1);
    }
    printf("Enter the number of elements in Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter data in space seperated format. Each element in each line. Coeff <space> power\n");
    for (i=1; i<=n; i++){
        scanf("%d %d", &coe, &pow);
        createnode(coe, pow, &poly2);
    }
	printf("Polynomial 1: ");
	display(poly1);
	printf("\nPolynomial 2:");
	display(poly2);
	poly = (struct Node*)malloc(sizeof(struct Node));
	polyadd(poly1, poly2, poly);
	printf("\nPolynomial sum:");
	display(poly);
}
