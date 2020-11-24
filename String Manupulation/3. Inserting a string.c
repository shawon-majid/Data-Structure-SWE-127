#include <stdio.h>
#include <string.h>

void insert(char* str, char* newstr, int index){

    int len1 = strlen(str),  len2 = strlen(newstr);
    if(index > len1) index = len1;
    char final_str[len1+len2+2];
    //add first part;
    for(int i = 0; i < index; i++){
        final_str[i] = str[i];
    }
    //insert the new string
    for(int i = index, k = 0; k < len2; k++, i++){
        final_str[i] = newstr[k];
    }
    //add last part;
    for(int i = index+len2, k = index; i < (len1+len2); i++, k++){
        final_str[i] = str[k];
    }

    final_str[len1+len2] = '\0';
    strcpy(str, final_str);
}


int main(){

	while(1){
        char str[10000], newstr[10000];
        int index;
        printf("Enter a string(Press 0 to exit): ");
        gets(str);

        if(strlen(str) == 1  && str[0] == '0'){
            break;
        }
        printf("insert a string: ");
        gets(newstr);

        printf("Enter index of insertion: ");
        scanf("%d", &index);

        //insert(str, newstr, index);

        int len1 = strlen(str), len2 = strlen(newstr);
        if(len1+len2 > 10000){
            printf("Too big to insert!\n");
        }
        else {
            insert(str, newstr, index);
            printf("The string is: %s\n", str);
        }
        getchar();

	}


}

