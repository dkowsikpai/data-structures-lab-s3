
// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 

struct node { 
   int key; 
   struct node *left, *right; 
};

struct node* newNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

void inorder(struct node *root){
    if(root !=NULL){
        inorder(root->left);
        printf("%d\n", root->key);
        inorder(root->right);
    }

}

void preorder(struct node *root){
    if(root !=NULL){
        printf("%d\n", root->key);
        inorder(root->left);
        inorder(root->right);
    }

}

void postorder(struct node *root){
    if(root !=NULL){
        
        inorder(root->left);
        inorder(root->right);
        printf("%d\n", root->key);
    }

}

struct node* insert(struct node* node, int key) { 
    if (node == NULL) return newNode(key); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
    return(node);

}

struct node* minValueNode(struct node* root){
    struct node* current = root;
    while(current && current->left != NULL){
        current = current->left;
    }
    return(current);
    
}

struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

void main(){
    struct node* root = NULL;
    int op, data;
    printf("1.Insert into BST\n2.Delete from BST\n3.Display BST inorder\n4.Display BST preorder\n5.Display BST postorder\n6.Quit");
    do{
        printf("\nEnter option:");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
            break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                deleteNode(root, data);
            break;
            case 3:
                printf("Inorder BST: \n");
                inorder(root);
            break;
            case 4:
                printf("Preorder BST: \n");
                preorder(root);
            break;
            case 5:
                printf("Postorder BST: \n");
                postorder(root);
            break;
            
            
        }
    }while(op != 6);
    
}
