#include <stdio.h>

int getOddOccurence(int* arr, int size){
        int res = 0;
        for (int i = 0; i < size; i ++) {
                res = res ^ arr[i];
        }
        return res;
}

int main(){
        int arr[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2}; 
        printf("Odd occuring element : %d", getOddOccurence(arr, 13));
        return 0;
}
