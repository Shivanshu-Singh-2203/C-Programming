#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * u val -> push val in the stack
 * p     -> peek
 * d     -> display
 * o     -> pop
 * q     -> quit
 */

int main() {
    char op;
    int val, status;

    printf("Stack operations:\n");
    printf("u <val> : push\n");
    printf("p       : peek\n");
    printf("d       : display\n");
    printf("o       : pop\n");
    printf("q       : quit\n");

    while (1) {
        printf("Enter operation: ");
        if (scanf(" %c", &op) != 1) break;

        switch (op) {
            case 'u': // push
                if (scanf("%d", &val) != 1) {
                    printf("Invalid value\n");
                    while (getchar() != '\n'); // clear buffer
                    break;
                }
                status = push(val);
                if (status == 0)
                    printf("Pushed %d\n", val);
                break;

            case 'p': // peek
                status = peek(&val);
                if (status == 0)
                    printf("Top element: %d\n", val);
                break;

            case 'd': // display
                display();
                break;

            case 'o': // pop
                status = pop(&val);
                if (status == 0)
                    printf("Popped: %d\n", val);
                break;

            case 'q': // quit
                printf("Exiting...\n");
                return EXIT_SUCCESS;

            default:
                printf("Invalid operation. Use: u <val>, p, d, o, q\n");
                break;
        }
    }

    return EXIT_SUCCESS;
}

