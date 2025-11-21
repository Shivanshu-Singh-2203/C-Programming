#ifndef LIST_H

#include <stdio.h>
#include <stdlib.h>

struct list {
        int* array;
        int curr_count;
        int max_count;
} ;

typedef struct list List ;

int grow(List *l);
int shrink(List* l);
int update(List* l, int loc, int data);
int deleteAt(List* l, int loc);
int append(List* s, int data);
int insert(List* l, int loc, int data);
void freeList(List* l);
#endif
