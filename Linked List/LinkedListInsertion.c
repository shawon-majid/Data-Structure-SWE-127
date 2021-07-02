#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

void showList(Node *n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void pushFront(Node** cur_head, int newData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = newData;
    newNode -> next = (*cur_head);
    *cur_head = newNode;
}

void insertAfter(Node* previousNode, int newData){
    if(previousNode == NULL){
        printf("This node is Null\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = newData;

    newNode ->next = previousNode -> next;
    previousNode ->next = newNode;

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


int main(){
    Node* head = (Node*)malloc(sizeof(Node));

    head -> data = 10;
    head -> next = NULL;
    showList(head);

    pushFront(&head, 20);  //O(1)
    showList(head);

    insertAfter(head, 15); //O(1)
    showList(head);

    pushBack(head, 50);    //O(n)
    showList(head);

}
