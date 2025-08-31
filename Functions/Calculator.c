/* Calculator Program */ 

#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    int choice, a, b;
    
    while (1) {
        printf("\n--- Calculator ---\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        switch (choice) {
            case 1: printf("Result: %d\n", add(a, b)); break;
            case 2: printf("Result: %d\n", subtract(a, b)); break;
            case 3: printf("Result: %d\n", multiply(a, b)); break;
            case 4: 
                if (b != 0) 
                    printf("Result: %.2f\n", divide(a, b));
                else 
                    printf("Error: Division by zero!\n");
                break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function definitions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
float divide(int a, int b) { return (float)a / b; }

