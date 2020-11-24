#include <stdio.h>
#include <string.h>

void Delete(char* str, int index, int length){
    char temp[10000];
    int len = strlen(str);
    if(index > len) index = len;
    if(index+length > len) length = len-index;
    //add first part;
    for(int i = 0; i < index; i++){
        temp[i] = str[i];
    }
    // igonre the deleted part
    // add last part
    for(int i = index, k = index+length; k < len; k++, i++){
        temp[i] = str[k];
    }
    temp[len - length] = '\0';
    strcpy(str, temp);
}

int main(){

	while(1){
        char str[10000];
        int index, length;
        printf("Enter a string(Press 0 to exit): ");
        gets(str);

        if(strlen(str) == 1  && str[0] == '0'){
            break;
        }
        printf("Enter the index and the length of deletion: ");
        scanf("%d %d", &index, &length);


        Delete(str, index, length);
        printf("The string is: %s\n", str);

        getchar();
	}


}

