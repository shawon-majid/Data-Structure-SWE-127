#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int find_substring_index(char str[], char substr[]){
    int len = strlen(str), sublen = strlen(substr);
    for(int i = 0; i < len - sublen + 1; i++){
        bool ok = 1;
        for(int j = i, k = 0; j < i+sublen; j++, k++){
            if(substr[k] != str[j]){
                ok = 0;
            }
        }
        if(ok) return i;
    }
    return -1;
}

int main(){

	while(1){
        char str[1000], substr[1000];

        printf("Enter a string(Press 0 to exit): ");
        gets(str);

        if(strlen(str) == 1  && str[0] == '0'){
            break;
        }

        printf("Now enter a substring of this string: ");
        gets(substr);

        int index = find_substring_index(str, substr);
        if(index != -1)printf(" \"%s\" occurs in \"%s\" at index %d\n", substr, str, index);
        else printf("\"%s\" is not a substring of \"%s\"\n", substr, str);
        printf("\n");
	}


}

