#include <stdlib.h>
#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int size){
        int curr = 0;
        int max = 0;
        for(int i = 0; i < size; i ++){
                if(nums[i] == 0){
                        if(curr > max){
                                max = curr;
                        }
                        curr = 0;
                }
                else{
                        curr++;
                }
        }

        if(max < curr){
                max = curr;
        }
        return max;
}

int main(int argc, char *argv[])
{
        int nums[] = {1,1,0,1,1,1};
        int size = sizeof(nums)/sizeof(nums[0]);
        printf("Max consecutive ones : %d\n", findMaxConsecutiveOnes(nums,size));
        return EXIT_SUCCESS;
}
