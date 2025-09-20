#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
float divide(int a, int b) {
    if (b == 0) return 0; // Simple error handling
    return (float)a / b;
}
