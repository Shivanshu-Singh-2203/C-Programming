#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

void displayEmployees(Employee *emps, int n)
{
	if(emps == NULL)
	{
		printf("Please create employees records.\n");
		return;
	}

	for(int j = 0; j < n ; j ++)
	{
		printf("----------Employee %d----------\n",j+1);
		printf("Name : %s\n",(emps+j)->name);
		printf("ID : %d\n", (emps+j)->employeeID );
		printf("Salary : %d\n", (emps + j)->salary);
		printf("\n");
	}
}

Employee* createEmployees(int n)
{
	Employee* emps;
	emps = malloc(sizeof(Employee)*n);
	printf("Employee record created successfully!\n");
	return emps;
}

void inputEmployees(Employee *emps, int n)
{
	if(emps == NULL)
	{
		printf("Please create employees records.\n");
		return;
	}
	for(int j = 0; j < n; j ++)
	{
		printf("----------Employee %d----------\n",j+1);
		printf("Enter the employee ID : ");
		scanf("%d",&(emps+j)->employeeID);

		printf("Enter the employee name : ");
		scanf("%s", (emps+j)->name);

		printf("Enter the employee salary : ");
		scanf("%d", &(emps+j)->salary);
	}
	printf("Employees added successfully!\n");
	return;
}

void freeEmployee(Employee *emps, int n)
{
	if(emps == NULL)
	{
		printf("Please create employees records.\n");
		return;
	}

	printf("Deleting records ...\n");
	free(emps);
	emps = NULL;
	return ;
}	

void updateSalary(Employee *emps, int n)
{
	if(emps == NULL)
	{
		printf("Please create employees records.\n");
		return;
	}
	int id;
	printf("Enter the employee's id : ");
	scanf("%d",&id);
	
	int newSalary;
	printf("Enter the employee's new salary : ");
	scanf("%d",&newSalary);
	for(int j = 0; j < n; j ++)
	{
		if((emps+j)->employeeID == id)
		{
			(emps + j)->employeeID = newSalary;
			printf("Employee salary updated successfull!\n");
			return;
		}
	}
	printf("Employee with not found.\n");
	return ;
}
