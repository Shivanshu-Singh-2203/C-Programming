/* Array of Pointers to Functions */ 

#include <stdio.h>

/* prototypes */ 
void function1(int a);
void function2(int b);
void function3(int c);

/* main */
int main(void)
{   
    /* f is an array of 3 pointers to functions that
     * take an int argument and return void
     */
    void (*f[3])(int) = {function1, function2, function3};
    unsigned int choice;

    printf("Enter a number between 0 and 2, 3 to end : ");
    scanf("%u", &choice);
    
    while (choice < 3) {
        (*f[choice])(choice);
        printf("Enter a number between 0 and 2, 3 to end : ");
        scanf("%u", &choice);
    }

    puts("Program terminated ...");
    return 0; 
}

/* function definitions */
void function1(int a)
{
    printf("You entered %d so function1 is executed.\n", a);
}

void function2(int b)
{
    printf("You entered %d so function2 is executed.\n", b);
}

void function3(int c)
{
    printf("You entered %d so function3 is executed.\n", c);
}

