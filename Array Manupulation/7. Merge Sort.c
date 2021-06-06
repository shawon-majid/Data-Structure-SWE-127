#include <stdio.h>

void printara(int ara[], int l, int r){
    for(int i = l; i <= r; i++){
        printf("%d ", ara[i]);
    }
}

int step = 1;

void merging(int *ara, int low, int mid, int high){
    int L = low, R = mid+1;
    int tempSize = high - low + 1; 
    int temp[tempSize];
    int tempInd = 0;
    while(L <= mid and R <= high){
        if(ara[L] <= ara[R]){
            temp[tempInd] = ara[L];
            L++;
        }
        else{
            temp[tempInd] = ara[R];
            R++;
        }
        tempInd++;
    }
    if(L > mid){
        while(tempInd < tempSize){
            temp[tempInd] = ara[R];
            tempInd++;
            R++;
        }
    }
    else if(R > high){
        while(tempInd < tempSize){
            temp[tempInd] = ara[L];
            tempInd++;
            L++;
        }
    }
    for(int i = low, j = 0; i <= high; i++, j++){
        ara[i] = temp[j];
    }
}

void mergeSort(int *ara, int low, int high){
    if(low < high){
        int mid = (low+high) / 2;
        int leftSize = mid - low + 1; 
        int rightSize = high - mid;
        int leftAra[leftSize];
        int rightAra[rightSize];

        mergeSort(ara, low, mid);
        mergeSort(ara, mid+1, high);
        printf("Step: %d:\n", step++);
        printf("Left: ");
        printara(ara, low, mid);

        printf("| ");
        printf("Right: ");
        printara(ara, mid+1, high);
        printf("\n");


        merging(ara, low, mid, high);        

        printf("Merged Array: ");

        printara(ara, low, high);
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

    mergeSort(ara, 0, n-1);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");

}