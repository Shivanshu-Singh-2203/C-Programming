#include <stdio.h>
#include <stdlib.h>

int scoreOfString(char* s) {
    char* head = s;
    int score = 0;
    while(*(head) != '\0'){
        int temp = *(head + 1) - *(head);
        if(temp < 0){
            score = score - temp;
        }
        score += temp;
        head ++;
    }

    return score;
}
int main(){
    char* s = "hello";
    printf("Score of the string : %d", scoreOfString(s));
    return 0;
}