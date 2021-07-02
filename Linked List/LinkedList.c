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


int main(){
    Node* Head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    Head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    Head -> data = 1; //(*Head).data = 1
    Head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;

    /*   We have the linked list ready.

           head
             |
             |
        +---+---+     +---+---+       +----+------+
        | 1  | o----->|  2  | o-----> |  3 | NULL |
        +---+---+     +---+---+       +----+------+


    Note that only head is sufficient to represent
    the whole list.  We can traverse the complete
    list by following next pointers.    */
    showList(Head);

}

