#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getDuplicates(char* string){
        int count[256] = {0};

        for(int i = 0; string[i] != '\0'; i ++){
                count[(int) string[i]] ++;
        }
        
        int length = strlen(string);
        char* result = malloc(sizeof(char)*length);
        char* head = result;

        for(int i = 0; string[i] != '\0'; i++){
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
        char* result = getDuplicates(s);
        printf("%s has following as duplicates : %s.\n",s, result);
        free(result);
        return 0;

}
