#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

Employee* createEmployees(int n) {
    Employee *emps = (Employee*)malloc(sizeof(Employee) * n);
    if (emps == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return emps;
}

void inputEmployees(Employee *emps, int n) {
    char temp[100];
    for (int i = 0; i < n; i++) {
        printf("============ Employee %d ============\n", i + 1);

        printf("Enter the employee name: ");
        getchar(); // consume leftover newline from previous input
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0; // remove trailing newline
        strcpy(emps[i].name, temp);

        printf("Enter the employee ID: ");
        scanf("%d", &emps[i].employeeID);

        printf("Enter the salary of the employee: ");
        scanf("%d", &emps[i].salary);
    }
}

void displayEmployees(Employee *emps, int n) {
    for (int i = 0; i < n; i++) {
        printf("Employee ID: %d\n", emps[i].employeeID);
        printf("Name: %s\n", emps[i].name);
        printf("Salary: %d\n", emps[i].salary);
        printf("---------------------------\n");
    }
}

void updateSalary(Employee *emps, int n, int id, int newSalary) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (emps[i].employeeID == id) {
            emps[i].salary = newSalary;
            flag = 1;
            printf("Salary updated successfully!\n");
            break;
        }
    }
    if (!flag) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void freeEmployees(Employee *emps, int n) {
    free(emps);
}

