#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int testAppend(){
	List* l = malloc(sizeof(List));
	l->array = NULL;
	l->max_count = 0;
	l->curr_count = 0;

	int ret1 = append(l, 1);
	int ret2 = append(l, 2);

	int check3 = !((l->array[0] == 1) && (l->array[1] == 2));

        freeList(l);        
	return (ret1 || ret2 || check3) ;
}

int testInsert(){
	List* l = malloc(sizeof(List));
	l->array = NULL;
	l->max_count = 0;
	l->curr_count = 0;

	int ret1 = append(l, 1);
	int ret2 = insert(l, 0, 2);
	int ret3 = insert(l, 1, 3);

	int check3 = !( l->array[0] == 2  &&  l->array[1] == 3  && l->array[2] == 1 && l->curr_count == 3 && l->max_count == 4);

        freeList(l); 
	return (ret1 || ret2 || ret3 || check3) ;
}

int testDelete(){
	List* l = malloc(sizeof(List));
	l->array = NULL;
	l->max_count = 0;
	l->curr_count = 0;

	int ret1 = append(l, 1);
	int ret2 = append(l, 2);
	int ret3 = append(l, 3);
	int ret4 = deleteAt(l, 0);
	int check1 = !((l->array[0] == 2) && (l->array[1] == 3) && (l->curr_count == 2) );
	int ret5 = deleteAt(l, 0);
	int check2 = !((l->array[0] == 3) && (l->curr_count == 1) && (l->max_count == 2));
	int ret6 = deleteAt(l, 0);
	int check3 = !((l->array == NULL) && (l->curr_count == 0) && (l->max_count == 0));

        freeList(l);
	return (ret1 || ret2 || ret3 || ret4 || ret5 || ret6 || check1 || check2 || check3) ;
}

int testUpdate(){
	List* l = malloc(sizeof(List));
	l->array = NULL;
	l->max_count = 0;
	l->curr_count = 0;

	int ret1 = append(l, 1);
	int ret2 = update(l, 0, 2);
	int ret3 = insert(l, 1, 4);
	int check1 = !((l->array[0] == 2) && (l->curr_count == 2) && (l->max_count == 2));

        freeList(l);

	return (ret1 || ret2 || ret3 || check1)  ;
}

int test(){
	int result = 1;

	if(testAppend()){
		printf("\tappend() failed\n");
		result = 0;
	}else{
		printf("append() passed\n");
	}

	if(testInsert()){
		printf("\tinsert() failed\n");
		result = 0;
	}else{
		printf("insert() passed\n");
	}

	if(testDelete()){
		printf("\tdeleteAt() failed\n");
		result = 0;
	}else{
		printf("deleteAt() passed\n");
	}

	if(testUpdate()){
		printf("\tupdate() failed\n");
		result = 0;
	}else{
		printf("update() passed\n");
	}

	return result;
}



int main(){

	printf("Running all test cases\n\n");
	if(test()){
		printf("\nAll test cases passed\n");
	}else{
		printf("\nSome test cases did not pass\n");
	}

	return 0;
}

