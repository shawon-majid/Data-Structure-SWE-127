#include <stdio.h>

void printara(int ara[], int l, int r){
    for(int i = l; i <= r; i++){
        printf("%d ", ara[i]);
    }
}

int step = 1;

void selectionSort(int *ara, int n){
    int i, j, index_min, temp;

    for(i = 0; i < n-1; i++){
        index_min = i;
        for(j = i+1; j < n; j++){
            if(ara[j] < ara[index_min]){
                index_min = j;
            }
        }
        if(index_min != i){
            temp = ara[i];
            ara[i] = ara[index_min];
            ara[index_min] = temp;
        }
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

    selectionSort(ara, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");

}