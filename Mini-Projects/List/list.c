#include "list.h"
#include <stdlib.h>

void freeList(List* l){
        if(l->array){
                free(l->array);
                l->array = NULL;
        }
        free(l);
}

int grow(List* l){
        if(l->array == NULL){
                int* newArr = malloc(sizeof(int));
                if(newArr == NULL){
                        return 1;
                }
                l->array = newArr;
                l->max_count = 1;

        }

        else if(l->curr_count == l->max_count){
                unsigned int newsize = l->max_count * 2;
                int* newArr = realloc(l->array, sizeof(int)*newsize);
                if(newArr == NULL){
                        return 1;
                }
                l->array = newArr;
                l->max_count = newsize;
        }
        return 0;
}


int shrink(List *l){
        if(l->curr_count == 0){
                free(l->array);
                l->array = NULL;
                l->max_count = 0;
                l->curr_count = 0;
        }
        else if(l->curr_count < l->max_count /2){
                int newsize = l->max_count/2;
                int* newArr = realloc(l->array, sizeof(int)*newsize);
                if(newArr == NULL){
                        return 1;
                }
                l->array = newArr;
                l->max_count = newsize;                
        }
        return 0;
}

int update(List* l, int loc, int data){
        if(loc + 1 > l->curr_count){
                return 1;
        }

        l->array[loc] = data;
        return 0;
}

int deleteAt(List* l, int loc){
        if(loc + 1 > l->curr_count){
                return 1;
        }

        for(int i = loc; i < l->curr_count - 1; i ++){
                l->array[i] = l->array[i+1];
        }
        l->curr_count --;

        return shrink(l);
}

int append(List *s, int data){
        if(grow(s)){
                return 1;
        }

        s->array[s->curr_count] = data;
        s->curr_count ++;
        return 0;
}

int insert(List* l, int loc, int data){
        if(grow(l)){
                return 1;
        }

        for(int i = l->curr_count; i > loc; i --){
                l->array[i] = l->array[i-1]; 
        }
        l->curr_count ++;
        return update(l, loc, data);
} 
