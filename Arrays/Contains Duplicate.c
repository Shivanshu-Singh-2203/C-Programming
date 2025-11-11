#include <stdio.h>

int containsDuplicate(int* arr, int size){
        int flag = 0;
        for (int i = 0 ; i < size && flag == 0; i ++) {
                for(int j = i + 1; j < size; j ++){
                        if(arr[j] == arr[i]){
                                flag = 1;
                                break;
                        }
                }
        }
        return flag;
}

int main(){
        int arr[5] = {1,2,3,5,1};
        int size = sizeof(arr)/sizeof(arr[0]);

        if(containsDuplicate(arr,size)){
                printf("Contains duplicate\n");
        }
        else {
                printf("Does not contain duplicate\n");
        }
        return 0;
}
