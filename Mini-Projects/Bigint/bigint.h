#ifndef BIGINT_H
#define BIGINT_H
#include "list.h"

struct bigint { 
        List* numbers;
        int sign;
};

typedef struct bigint Bigint;

void freeBigint(Bigint* ptr);
void initialize(Bigint* ptr);
int equal(Bigint* first, Bigint* second);
Bigint* add(Bigint* first, Bigint* second);
void print(Bigint* ptr);
int read(Bigint* ptr);

#endif
