//Bismillahir Rahman-ir Rahim
#include <stdio.h> 



int tree[500000];
int curInd = 1;

void printTree(int n){
    for(int i = 1; i <= n-1; i++){
        if(__builtin_popcount(i) == 1){
            printf("\n");   
        }
        printf("%d ", tree[i]);
        
    }
    printf("\n");
}


void insertHeap(int num){
    tree[curInd] = num;
    int tempInd = curInd;
    int parentInd = tempInd/2;
    while(parentInd >= 1){
        if(tree[tempInd] < tree[parentInd]){
            //swap(tree[parentInd], tree[tempInd]);
            int temp = tree[parentInd];
            tree[parentInd] = tree[tempInd];
            tree[tempInd] = temp;

            tempInd = parentInd;
            parentInd = tempInd/2;            
        }
        else{
            break;
        }
    }
    curInd++;
}

int popRoot(){ // deleting root from heap
    int ind = 1;
    int root = tree[ind];
    curInd--;
    tree[ind] = tree[curInd];
    while(ind < curInd){
        int leftInd = 2*ind, rightInd = leftInd + 1;
        if(leftInd >= curInd){ // there is no left child
            break;
        }   
        if(rightInd >= curInd){ // there is no right child but there is left child
            if(tree[ind] > tree[leftInd]){
                //swap(tree[ind], tree[leftInd]);
                int temp = tree[ind];
                tree[ind] = tree[leftInd];
                tree[leftInd] = temp;

                ind = leftInd;
            }
            else{
                break;
            }
        }
        else{ // both left and right child exist
            if(tree[leftInd] < tree[rightInd]){
                if(tree[ind] > tree[leftInd]){
                    //swap(tree[ind], tree[leftInd]);
                    int temp = tree[ind];
                    tree[ind] = tree[leftInd];
                    tree[leftInd] = temp;

                    ind = leftInd;
                }
            }
            else{
                if(tree[ind] > tree[rightInd]){
                    //swap(tree[ind], tree[rightInd]);
                    int temp = tree[ind];
                    tree[ind] = tree[rightInd];
                    tree[rightInd] = temp;

                    ind = rightInd;
                }
            }
        }
    }
    return root;
}   

void heapsort(int *ara, int n){
    int ind = 0;
    for(int i = 0; i < n; i++){
        insertHeap(ara[i]);
    }
    while(curInd > 1){
        int r = popRoot();
        ara[ind] = r;
        ind++;
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    int ara[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    heapsort(ara, n);
    for(int i = 0; i < n; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");


    return 0;
}