#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

int REPLACE(char* str, char* s1, char* s2){
    int index = find_substring_index(str, s1);
    if(index == -1) return 0;
    int len = strlen(s1);
    Delete(str, index, len);
    insert(str, s2, index);
    return 1;
}


int main(){

    char str[1000], s1[1000], s2[1000];
    printf("Enter a string: ");
    gets(str);
    printf("Enter a substring: ");
    gets(s1);
    printf("Enter the replacement: ");
    gets(s2);

    if(REPLACE(str, s1, s2)){
        printf("%s\n", str);
    }
    else printf("This substing is not found!\n");


}

