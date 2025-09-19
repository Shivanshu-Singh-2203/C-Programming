#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct employee {
	int salary;
	char name[80];
	int employeeID;
} Employee;

Employee* createEmployees(int n);
void inputEmployees(Employee* emps, int n);
void displayEmployees(Employee* emps, int n );
void updateSalary(Employee* emps, int n, int id, int newSalary);
void freeEmployees(Employee* emps, int n);

#endif
