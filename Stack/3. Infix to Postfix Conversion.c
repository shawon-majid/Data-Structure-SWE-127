#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char stk[1000l];
int top = -1;

void PUSH(char el){
    if(top >= 10000){
        printf("Stack Overflow!\n");
        return;
    }
    stk[top+1] = el;
    top++;
}

void POP()
{
    if(top < 0){
        printf("Stack is Empty!\n");
        return;
    }
    top--;
}

void printstack(){
    printf("Current stack: ");
    for(int i = 0; i <= top; i++){
        printf("%c ", stk[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the size of infix: ");
    scanf("%d", &n);
    char infix[n+1][5], postfix[1000][5];

    printf("Enter the infix: ");
    for(int i = 0; i < n; i++){
        char temp[5];
        scanf("%s", temp);
        int t_size = strlen(temp);
        for(int j = 0; j < t_size; j++){
            infix[i][j] = temp[j];
        }
        infix[i][t_size] = '\0';
    }
    // initialization
    infix[n][0] = ')', infix[n][1] = '\0';
    PUSH('(');

    int i = 0, po = 0;
    while(top != -1){
        printf("pass %d: ", i+1);
        printstack();

        if(infix[i][0] == '(' || infix[i][0] == '^'){
            PUSH(infix[i][0]);
        }
        else if(infix[i][0] == ')'){
            while(stk[top] != '('){
                postfix[po][0] = stk[top];
                postfix[po][1] = '\0';
                po++;
                POP();
            }
            POP();
        }
        else if(infix[i][0] == '+' || infix[i][0] == '-'){
            while(stk[top] != '('){
                postfix[po][0] = stk[top];
                postfix[po][1] = '\0';
                po++;
                POP();
            }
            PUSH(infix[i][0]);
        }
        else if(infix[i][0] == '*' || infix[i][0] == '/'){
            while(stk[top] != '(' && stk[top] != '+' && stk[top] != '-'){
                postfix[po][0] = stk[top];
                postfix[po][1] = '\0';
                po++;
                POP();
            }
            PUSH(infix[i][0]);
        }
        else{
            int t_size = strlen(infix[i]);
            for(int j = 0; j < t_size; j++){
                postfix[po][j] = infix[i][j];
            }
            postfix[po][t_size] = '\0';
            po++;
        }
        i++;
    }
    printf("Corresponding postfix: ");
    for(int k = 0; k < po; k++){
        printf("%s ", postfix[k]);
    }
    printf("\n");

}

