#include <stdio.h>
#include <string.h>


int top = -1;
// push, pop, top, stack
void PUSH(char* stk, char el, int size){
    if(top >= size-1){
        printf("Stack Overflow!\n");
        return;
    }
    stk[top+1] = el;
    top++;
}

void POP(char *stk)
{
    if(top < 0){
        printf("Stack is Empty!\n");
        return;
    }
    top--;
}


int main(){

    int size;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    char stk[size+1];
    stk[0] = '\0';
    while(1){
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Show Top Element\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();
        if(choice == 1){
            printf("Enter element to push: ");
            char el;
            scanf("%c", &el);
            PUSH(stk, el, size);
        }
        else if(choice == 2){
            POP(stk);
        }
        else if(choice == 3){
            if(top < 0) printf("The stack is Empty!\n");
            else printf("Top: %c\n", stk[top]);
        }
        else if(choice == 0){
            break;
        }
        printf("current stack is: \n");
        for(int i = top; i >= 0; i--){
            printf("%c\n", stk[i]);
        }
        printf("\n");
    }
}

