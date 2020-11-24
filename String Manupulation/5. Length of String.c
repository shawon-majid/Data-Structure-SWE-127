#include <stdio.h>
#include <string.h>


int main(){
    char str[1000];
    printf("Insert a string: ");
    gets(str);
    int len = 0;
    for(int i = 0; i < 1000; i++){
        if(str[i] == '\0'){
            break;
        }
        len++;
    }
    printf("%d\n", len);

}


