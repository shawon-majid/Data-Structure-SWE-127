#include <stdio.h>
typedef long long ll;

ll fact(ll n){
    if(n == 0){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%lld\n", fact(n));
}


