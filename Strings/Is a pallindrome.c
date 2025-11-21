#include <stdio.h>

int isPallindrome(char* string){
        char* iter = string;
        while(*iter != '\0'){
                iter ++;
        }

        iter --;

        char* head = string;
        while(head < iter){
                if(*head != *iter){
                        return 1;
                }
                head ++;
                iter --;
        }
        return 0;
}

int main(){
        if(isPallindrome("MADAM")){
                printf("The string MADAM is not a pallindrome.\n");
        }
        else {
                printf("The string MADAM is a pallindrome.\n");
        }

        return 0;
}
