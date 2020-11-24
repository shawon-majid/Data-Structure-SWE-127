#include <stdio.h>
#include <string.h>

void Insert(int *ara, int size, int x){
    int index;
    for(int i = 0; i < size-1; i++){
        if(ara[i] <= x && ara[i+1] > x){
            index = i+1;
            break;
        }
    }
    if(x > ara[size-1]){
        index = size;
    }
    if(x < ara[0]){
        index = 0;
    }

    for(int i = size-1; i >= index; i--){
        ara[i+1] = ara[i];
    }

    ara[index] = x;
}

int main(){
    int ara[10000], n, element, t;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter a sorted array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    printf("Enter number of operations: ");
    scanf("%d", &t);
    int len = n;
    while(t--){

        printf("Enter an element: ");
        scanf("%d", &element);

        Insert(ara, len, element);
        len++;
        printf("The array is: ");
        for(int i = 0; i < len; i++){
            printf("%d ", ara[i]);
        }
        printf("\n");

    }




}


