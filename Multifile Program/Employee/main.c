#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main() {
    int n, choice;
    Employee *emps = NULL;

    while (1) {
        printf("\n--- Employee Management Menu ---\n");
        printf("1. Create employee records\n");
        printf("2. Input employee details\n");
        printf("3. Display all employees\n");
        printf("4. Update employee salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of employees: ");
                scanf("%d", &n);
                emps = createEmployees(n);
                printf("%d employee records created successfully!\n", n);
                break;

            case 2:
                if (emps == NULL) {
                    printf("Please create employee records first!\n");
                } else {
                    inputEmployees(emps, n);
                    printf("Employee details added successfully!\n");
                }
                break;

            case 3:
                if (emps == NULL) {
                    printf("No employee records available.\n");
                } else {
                    displayEmployees(emps, n);
                }
                break;

            case 4:
                if (emps == NULL) {
                    printf("No employee records available.\n");
                } else {
                    int id;
                    float newSalary;
                    printf("Enter employee ID to update salary: ");
                    scanf("%d", &id);
                    printf("Enter new salary: ");
                    scanf("%f", &newSalary);
                    updateSalary(emps, n, id, newSalary);
                    printf("Salary updated successfully!\n");
                }
                break;

            case 5:
                if (emps != NULL)
                    freeEmployees(emps, n);
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

