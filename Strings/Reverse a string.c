#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* str){
        size_t len = strlen(str);
        char* res = malloc(sizeof(char)*len);
        
        for(size_t i = 0; str[i] != '\0'; i ++){
                res[i] = str[len - i - 1];
        }
        res[len-1] = '\0';
        return res;
}

int main(){
        char str[] = "Hi, I am shivam!";
        char* ans = reverseString(str);
        printf("The reverse of the string : %s", ans);
        free(ans);
        return 0;
}
