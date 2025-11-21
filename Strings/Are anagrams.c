#include <stdio.h>
#include <string.h>

int areAnagrams(char* first, char* second){
        if(strlen(first) != strlen(second)){
                return 1;
        }

        int count[256] = {0};

        for(int i = 0; first[i] != '\0'; i ++){
                count[(int) first[i]] ++;
        }

        for(int i = 0; second[i] != '\0'; i ++){
                count[(int) second[i]] -= 1;
                if(count[(int) second[i]] < 0){
                        return 1;
                }
        }

        for(int i = 0; first[i] != '\0'; i ++){
                if(count[(int)first[i]] != 0){
                        return 1;
                }
        }
        return 0;
}

int main(){
        char first[] = "cat";
        char second[] = "tac";
        if(areAnagrams(first, second)){
                printf("They are not anagrams.\n");
        }
        else{
                printf("They are anagrams.\n");
        }
        return 0;
}
