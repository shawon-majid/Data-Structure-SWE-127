#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;



void showList(Node* n){

    while(n != NULL){
        printf("%d ", n ->data);
        n = n ->next;
    }
    printf("\n");
}

void pushBack(Node *head, int newData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data =  newData;
    newNode ->next = NULL;
    while(head -> next != NULL){
        head = head ->next;
    }
    head -> next = newNode;
}

void iterativeDelete(Node** n, int key){
    Node* temp = *n;
    Node* prev;
    // if head is the key
    if(temp -> data == key){
        *n = temp ->next; // changed head;
        free(temp); // free old head
        return;
    }

    while(temp != NULL && temp -> data != key){
        prev = temp;
        temp = temp-> next;
    }
    if(temp == NULL){
        printf("Element not found!\n");
        return;
    }

    prev ->next = temp ->next;
    free(temp);
}


int main(){

    int n;
    printf("Enter the size of linked list: ");
    scanf("%d", &n);
    printf("Insert the numbers:\n");

    Node* list = (Node*)malloc(sizeof(Node));
    list ->next = NULL;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(i == 0){
            list ->data = x;
        }
        else pushBack(list, x);
    }
    showList(list);

    printf("Enter the number to delete: ");
    int del;
    scanf("%d", &del);
    iterativeDelete(&list, del);

    showList(list);

}
