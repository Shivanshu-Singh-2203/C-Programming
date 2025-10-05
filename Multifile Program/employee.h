#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct employee {
	int salary;
	int employeeID;
	char name[80];
} Employee;

Employee* createEmployees(int n);
void inputEmployees(Employee* emps, int n);
void displayEmployees(Employee* emps, int n);
void updateSalary(Employee* emps,int n);
void freeEmployee(Employee* emps, int n);

#endif
