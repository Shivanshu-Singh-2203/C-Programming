#include <stdio.h>

int countSeniors(char** details, int detailsSize) {
    int count = 0; 
    for(int i = 0; i < detailsSize; i ++){
        int age = (details[i][11] - '0')*10 + (details[i][12] - '0');
        if(age > 60){
            count ++;
        }
    }
    return count;
}

int main() {
    char* details[] = {
        "7868190130M7522", // age = 75 -> senior
        "5303914400F9211", // age = 92 -> senior
        "9273338290F4010"  // age = 40 -> not senior
    };

    int result = countSeniors(details, 3);
    printf("Number of seniors: %d\n", result); // Expected: 2
    return 0;
}
