#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* string) {
    char* head = string;
    int len = strlen(string);

    char* getlast = head + len - 1;
    while(getlast >= head && *getlast == ' '){
        getlast --;
    } 

    int count = 0;
    while(getlast >= head && *getlast != ' '){
        count ++;
        getlast --;
    }
    return count;
}

int main() {
    char s1[] = "Hello World";
    char s2[] = "   fly me   to   the moon  ";
    char s3[] = "luffy is still joyboy";

    printf("Length of last word in \"%s\" = %d\n", s1, lengthOfLastWord(s1));
    printf("Length of last word in \"%s\" = %d\n", s2, lengthOfLastWord(s2));
    printf("Length of last word in \"%s\" = %d\n", s3, lengthOfLastWord(s3));

    return 0;
}
