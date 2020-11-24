#include <stdio.h>
#include <string.h>

int ara[10000];
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

void Delete(int* ara, int size, int index){
    for(int i = index; i < size-1; i++){
        ara[i] = ara[i+1];
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(ara[i] > ara[j]){
                int temp = ara[j];
                ara[j] = ara[i];
                ara[i] = temp;
            }
        }
    }
    printf("The sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");
    int t;
    printf("Enter the number of operations: ");
    scanf("%d", &t);
    int len = n;
    while(t--){
        printf("1. Insert an element\n2.Delete an element\n");
        printf("Choose an option: ");
        int c;
        scanf("%d", &c);
        if(c == 1){
            // insert an element
            int element;
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
        else{
            // delete an element
            int element, index = -1;
            printf("Enter an element: ");
            scanf("%d", &element);

            // check if element is present on the list
            int ok = 0;
            for(int i = 0; i < len; i++){
                if(ara[i] == element){
                    index = i;
                    ok = 1;
                    break;
                }
            }
            if(!ok){
                printf("There is no such element!\n");
                continue;
            }
            Delete(ara, len, index);
            len--;
            printf("The array is: ");
            for(int i = 0; i < len; i++){
                printf("%d ", ara[i]);
            }
            printf("\n");
        }
    }

}

