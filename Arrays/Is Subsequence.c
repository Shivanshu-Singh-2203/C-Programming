#include <stdio.h>
#include <stdbool.h>

int countChar(char* string, char c){
        int count = 0;
        char* temp = string;
        while(*temp != '\0'){
                if(*temp == c){
                        count ++;
                }
                temp ++;
        }
        return count;
}

int isSequence(char* string, char* substring){
        int temp[256] = {0};
        
        char* head = substring;

        while(*head != '\0'){
                temp[*head] ++;
                head ++;
        }

        char* sub = substring;
        while(*sub != '\0'){
                temp[*sub] --;
                if(temp[*sub] < 0){
                        return 1;
                }
                sub ++;
        }
        return 0;
}

bool isSubsequence(char*s , char* t){
        while(*s && *t){
                if(*s == *t){
                        s ++;
                }
                t ++;
        }
        return *s == '\0';
}
int main(){
        char* test = "NODE";
        char* string = "NEETCODE";

        if(isSequence(test, string)){
                printf("The given test string is not a substring of the string.\n");
        }
        else {

                printf("The given test string is a substring of the string.\n");
        }

        if(isSubsequence(test, string)){
                printf("The given test string is not a substring of the string.\n");
        }
        else {

                printf("The given test string is a substring of the string.\n");

        }return 0;
}

