#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#define MAXNAME 64

// Creating an employee structure
struct employee
{
    char fname[MAXNAME];        // Employee first name
    char lname[MAXNAME];        // Employee last name
    int id;                     // Employee ID
    int salary;                 // Employee salary
};

// Print the details of the employee database
void printDB();

// Search the employee database by ID
int lookupByID();

// Search the employee database by name
int lookupByLName();

// Add an employee to the database
int addEmployee();

// Remove an employee from the database
int removeEmployee();

// Update Employee details in the database
int updateEmployee();

// Print highest salary employees
void printHighestSalaryEmployees();

// Find employees with last name
void findAllWithLastName();

// Initialize Database
void initializeDB();

// Sort the employee database
void sort();

#endif // EMPLOYEE_H_INCLUDED
