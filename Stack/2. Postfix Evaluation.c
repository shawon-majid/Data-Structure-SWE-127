#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


double stk[1000l];
int top = -1;
// push, pop, top, stack
void PUSH(double el){
    if(top >= 10000){
        printf("Stack Overflow!\n");
        exit(-1);
        return;
    }
    stk[top+1] = el;
    top++;
}
void POP()
{
    if(top < 0){
        printf("Stack is Empty!\n");
        exit(-1);
        return;
    }
    top--;
}

int main(){
    int n;
    double res;
    printf("Enter the size of postfix: ");
    scanf("%d", &n);
    char postfix[n+1][5];
    printf("Enter the postfix(press space after each object): ");
    for(int i = 0; i < n; i++){
        char temp[5];
        scanf("%s", temp);
        int t_size = strlen(temp);
        for(int j = 0; j < t_size; j++){
            postfix[i][j] = temp[j];
        }
        postfix[i][t_size] = '\0';
    }
    postfix[n][0] = ')', postfix[n][1] = '\0'; // adding the finalizer
    n = n+1;

    for(int i = 0; i < n; i++){
        printf("Current object: %s\n", postfix[i]);
        if(i == n-1){
            res = stk[top];
            break;
        }
        int t_size = strlen(postfix[i]);
        if(t_size == 1){
            // + - * / number
            double a, b, ans;
            if(postfix[i][0] == '+'){
                a = stk[top];
                POP();
                b = stk[top];
                POP();

                ans = b+a;

                PUSH(ans);
            }
            else if(postfix[i][0] == '-'){
                a = stk[top];
                POP();
                b = stk[top];
                POP();

                ans = b-a;

                PUSH(ans);
            }
            else if(postfix[i][0] == '*'){
                a = stk[top];
                POP();
                b = stk[top];
                POP();
                ans = b*a;

                PUSH(ans);
            }
            else if(postfix[i][0] == '/'){
                a = stk[top];
                POP();
                b = stk[top];
                POP();
                ans = b/a;

                PUSH(ans);
            }
            else{
                char *ptr;
                double x = strtod(postfix[i], &ptr);
                PUSH(x);
            }
        }
        else{
            char *ptr;
            double x = strtod(postfix[i], &ptr);
            PUSH(x);
        }
        printf("pass %d: ", i+1);
        for(int k = 0; k <= top; k++){
            printf("%g ", stk[k]);
        }
        printf("\n");
    }
    if(top != 0){
        printf("too many operands!\n");
    }
    else printf("ans = %g\n", res);

}


