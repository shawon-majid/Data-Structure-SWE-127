#include <stdio.h>
#include <string.h>

char* concat(char *str1, char* str2, char*newstr)
{
    int len1 = strlen(str1), len2 = strlen(str2);
    for(int i = 0; i < len1; i++){
        newstr[i] = str1[i];
    }
    |//printf("%s\n", newstr);
    for(int i = len1, k = 0; i < len1+len2; i++, k++){
        newstr[i] = str2[k];
    }

    newstr[len1+len2] = '\0';

    return newstr;
}

int main(){
    char str1[1000], str2[1000], str[1000];
    printf("Insert 2 strings:\n");
    printf("str 1: ");
    gets(str1);
    printf("str 2: ");
    gets(str2);

    concat(str1, str2, str);
    printf("%s\n", str);

}

