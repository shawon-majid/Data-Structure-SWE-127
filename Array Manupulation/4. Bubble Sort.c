#include <stdio.h>
#include <string.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int ara[n];
    printf("Enter the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }
    int number_of_comparison = 0, number_of_interchange = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            number_of_comparison++;
            if(ara[i] > ara[j]){
                number_of_interchange++;
                int temp = ara[j];
                ara[j] = ara[i];
                ara[i] = temp;
            }
        }
    }
    printf("Number of interchange: %d\nNumber of Comparison: %d\n", number_of_interchange, number_of_comparison);
}


