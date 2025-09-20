#include "employee.h"
#include <stdio.h>
int choice;
Employee* emps = NULL;
int num_Employee;
int flag = 1;
int main()
{
	while(flag)
	{
		printf("----------Menu----------\n");
		printf("1. Create Employee records\n");
		printf("2. Input Employee details\n");
		printf("3. Display employee details\n");
		printf("4. Update Salary\n");
		printf("5. Free employees\n");
		printf("6. Exit\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter the number of employees in the records : ");
			scanf("%d", &num_Employee);
			emps = createEmployees(num_Employee);
			break;
		case 2:
			inputEmployees(emps, num_Employee);
			break;
		case 3: 
			displayEmployees(emps,num_Employee);
			break;
		case 4: 
			updateSalary(emps,num_Employee);
			break;
		case 5: 
			freeEmployee(emps, num_Employee);
			break;
		case 6:
			printf("Exiting...\n");
			flag = 0;
			break;
		default:
			printf("Please enter valid choice !\n");
			break;
		}
	}
}
