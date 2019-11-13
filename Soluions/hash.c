#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
    int data;
    int key;
}* hash[SIZE], *dummyitem, *item;


int hashCode(int key){
    return key % SIZE;
}

struct DataItem* search(int key){
    int hashindex = hashCode(key);

    while(hash[hashindex] != NULL){
        if(hash[hashindex]->key == key)
            return hash[hashindex];
        ++hashindex;

        hashindex %= SIZE;
    }

    return(NULL);
}

void insert(int key, int data){
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;    

    int hashindex = hashCode(key);
    while(hash[hashindex] != NULL && hash[hashindex]->key != -1){
        ++hashindex;
        hashindex %= SIZE;
    }

    hash[hashindex] = item;
}

struct DataItem* delete(struct DataItem* item){
    int key = item->key;
    int hashindex = hashCode(key);
    while (hash[hashindex] != NULL){
        if(hash[hashindex]->key == key){
            struct DataItem* temp = hash[hashindex];
            hash[hashindex] = dummyitem;
            return temp;
        }
        ++ hashindex;
        hashindex %= SIZE;
    }
    return(NULL);
}

void display(){
    int i = 0;
    for (i=0; i<SIZE; i++){
        if(hash[i] != NULL)
            printf("(%d, %d)", hash[i]->key, hash[i]->data);
        printf("\n");
    }
}


int main(){
    dummyitem = (struct DataItem*)malloc(sizeof(struct DataItem));
    dummyitem->data = -1;
    dummyitem->key = -1;
    int data1, data2, op;

    printf("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit");
    do{
        printf("Enter the choice: ");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("Enter key and value in space seperated format: ");
                scanf("%d %d", &data1, &data2);
                insert(data1, data2);
                break;
            case 2:
                display();
                break;
            case 3:
                delete(item);
                break;
            case 4:
                printf("Enter the data to search: ");
                scanf("%d", &data1);
                item = search(data1);
                if (item != NULL)
                    printf("Data found !!!");
                else
                    printf("Data not found");
                break;
        }

    }while(op!=5);
}