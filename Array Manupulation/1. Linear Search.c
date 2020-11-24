#include <stdio.h>
#include <string.h>

int linear_search(int ara[], int size, int x){
    for(int i = 0; i < size; i++){
        if(ara[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int ara[n];
    printf("Enter the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    int t;
    printf("Enter the number of operations: ");
    scanf("%d", &t);
    while(t--){
        printf("Enter an element: ");
        int x;
        scanf("%d", &x);
        if(linear_search(ara, n, x) == -1){
            printf("This element is not in the array!\n");
        }
        else{
            printf("The index of the element is: %d\n", linear_search(ara, n, x));
        }
    }

}

