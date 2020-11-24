#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int ara[n];
    printf("Enter the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }
    int k;
    printf("Enter the element to find: ");
    scanf("%d", &k);

    // bubble sort
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(ara[i] > ara[j]){
                int temp = ara[i];
                ara[i] = ara[j];
                ara[j] = ara[i];
            }
        }
    }
    // binary search
    int low = 0, high = n-1, p = 1, f = 0;
    while(low <= high){
        int mid = ((high+low)/2);
        printf("pass %d:\n", p);
        printf("high = %d, low = %d, mid = %d\nara[mid] = %d\n", high, low, mid, ara[mid]);
        if(ara[mid] == k){
            printf("Found the element\n");
            f = 1;
            break;
        }
        else if(ara[mid] > k){
            high = mid-1;
        }
        else low = mid+1;
        p++;
    }
    if(!f){
        printf("Element not found\n");
    }
    printf("Total number of steps: %d\n", p);

}


