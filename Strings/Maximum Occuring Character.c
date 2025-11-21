#include <stdio.h>
#include <string.h>

int countOccurences(char chars, char* string){
        char* head = string;
        int count = 0;
        while(*head != '\0'){
                if(*head == chars){
                        count ++;
                }
                head ++;
        }
        return count ;
}

char bruteForce(char* string){
        if(strlen(string) == 0){
                return '\0';
        }

        char currchar = '\0' ;
        int currentCount = 0;
        
        for(int i = 0; string[i] != '\0'; i ++){
                int pcount = countOccurences(string[i], string);        
        
                if(currentCount < pcount){
                        currentCount = pcount;
                        currchar = string[i];
                }
        }
        return currchar;
}

char hashing(char* string){
        int count[256] = {0};
        for(int i = 0; string[i] != '\0'; i ++){
                count[(int) string[i]] ++;
        }
        
        char currchar = '\0';
        int currcount = 0;

        for(int  i = 0; string[i] != '\0' ;  i ++){
                if(count[(int) string[i]] > currcount){
                        currchar = string[i];
                        currcount = count[(int) string[i]];
                }
        }

        return  currchar;
}
int main()
{
        char str[] = "sample string";
        printf("Max occurring character is: %c\n", bruteForce(str));
    
        char string[] = "Hello guys  I am shivam from varanasi."; 
        printf("Max occurring character is: %c\n", hashing(string));
        return 0;
}
