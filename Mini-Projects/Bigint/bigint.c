#include "bigint.h"

#define POWNINE 1000000000

void freeBigint(Bigint *ptr){
        freeList(ptr->numbers);
        free(ptr);
}

void initialize(Bigint *ptr){
	if(ptr->numbers  != NULL){
		freeList(ptr->numbers);
	}
	
        List* newList = malloc(sizeof(List));
        newList->array = NULL;
        newList->curr_count = 0;
        newList->max_count = 0;
        ptr->numbers = newList;
        ptr->sign = 0;
}

int equal(Bigint* first, Bigint* second){
        if(first->sign != second->sign){
                return 1;
        }

        List* fList = first->numbers;
        List* sList = second->numbers;
        if(fList->curr_count != sList->curr_count){
                return 1;
        }

        int total = fList->curr_count;
        for(int i = 0; i < total;i ++){
                if(fList->array[i] != sList->array[i]){
                        return 1;
                }
        }
        return 0;
}

Bigint* add(Bigint* first, Bigint* second){
        if(first == NULL){
                return second;
        }

        if(second == NULL){
                return first;
        }

        Bigint* res = malloc(sizeof(Bigint));
        initialize(res);
        
        long carry = 0;
        List* a = first->numbers;
        List* b = second->numbers;
        int maxcurr = a->curr_count > b->curr_count ? a->curr_count : b->curr_count;

        for(int i = 0; i < maxcurr; i ++){
                long aval = i >= a->curr_count ? 0 : a->array[i];
                long bval = i >= b->curr_count ? 0 : b->array[i];
                long sum = aval + bval + carry;
                append(res->numbers, sum % POWNINE);
                carry = sum/POWNINE;
        }
        
        if(carry > 0){
                append(res->numbers, carry);
        }
        return res;
}

void print(Bigint* ptr){
        int* arr = ptr->numbers->array;
        int curr = ptr->numbers->curr_count;

        for(int i = curr - 1; i >= 0; i -- ){
                if (i == curr-1){
                        printf("%d", arr[i]);}
                else {
                        printf("%09d", arr[i]);
                }
        }
        printf("\n");
}

int read(Bigint* num){
	initialize(num);

        char op;
	int number;
	while(1){

		scanf("%d",&number);
	        insert(num->numbers, 0, number); 
		scanf("%c", &op);
		if(op == '\n'){
	                break;
                }
	}
	return 0;
}
