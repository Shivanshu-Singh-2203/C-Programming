#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* string){
        int count[256] = {0};
        for(int i = 0; string[i] != '\0'; i ++){
                count[(int)string[i]] ++;
        }
        
        unsigned int length = strlen(string);

        char* result = malloc(sizeof(char)*length);
        char* head = result;

        for(int i = 0 ; string[i] != '\0'; i++){
                if(count[(int) string[i]] > 0){
                        *head = string[i];
                        head ++;
                        count[(int) string[i]] = 0;
                }
        }
        *head = '\0';
        return result;
}

int main(){
        char s[] = "Shivanshu Singh";
        char* result = removeDuplicates(s);
        printf("%s after removing the duplicates : %s.\n",s, result);
        free(result);
        return 0;

}
