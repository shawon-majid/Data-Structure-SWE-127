#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void find_substring(char *str, int index, int length){
    int len = strlen(str);
    if(index > len) index = len;
    char temp[10000];
    for(int i = index, k = 0; k < length; i++, k++){
        temp[k] = str[i];
    }
    temp[length] = '\0';
    strcpy(str, temp);
}

int main(){

	while(1){
        char str[1000];
        int index, length;

        printf("Enter a string(Press 0 to exit): ");
        gets(str);

        if(strlen(str) == 1  && str[0] == '0'){
            break;
        }
        printf("Enter index and length of substring: ");
        scanf("%d %d", &index, &length);

        find_substring(str, index, length);

        printf("Substring: %s\n", str);
        getchar();

	}


}


