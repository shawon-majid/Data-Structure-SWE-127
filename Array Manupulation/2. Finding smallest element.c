#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    int ara[n];
    printf("Enter the Dataset: ");
    for(int i =0; i < n; i++){
        scanf("%d", &ara[i]);
    }
    int mn = ara[0];
    for(int i = 0; i < n; i++){
        if(ara[i] < mn){
            mn = ara[i];
        }
    }
    printf("The smallest value is: %d\n", mn);

}

