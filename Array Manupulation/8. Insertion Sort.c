#include <stdio.h>

void printara(int ara[], int l, int r){
    for(int i = l; i <= r; i++){
        printf("%d ", ara[i]);
    }
}

int step = 1;

void insertionSort(int *ara, int n){
    int i, j, item;
    for(i = 1; i < n; i++){
        item = ara[i];
        j = i-1;
        while(j >= 0 and ara[j] > item){
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = item;
        printf("step %d: ", step++);
        printara(ara, 0, n-1);
        printf("\n");
    }
}


int main(){
    int n = 14;
    int ara[] = {66, 33, 40, 22, 55, 88, 60, 11, 80, 20, 50, 44, 77, 30};
    printf("Given Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");

    insertionSort(ara, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");

}