#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maskDirtyChars(char* str, char* dirtychars, char maskchar){
        int count[256] = {0};
        char* res = malloc(sizeof(char)*strlen(str));        

        for(int i= 0; dirtychars[i] != '\0'; i ++){
                count[(int)dirtychars[i]] ++;

        }

        for(int i = 0; str[i] != '\0'; i ++){
                if(count[(int)str[i]] > 0){
                        res[i] = maskchar;
                }
                else {
                        res[i] = str[i];
                }
        }
        return res; 
}

int main(){
        char str[] = "Life is bad.";
        char dirty[] = "bad";
        char mask = '*';
        char* res = maskDirtyChars(str, dirty, mask);
        printf("Masked string is : %s\n", res);
        return 0;
}       
