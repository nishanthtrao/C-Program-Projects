#include <stdio.h>
#include <string.h>
#include "reader.h"
#include "employee.h"

void initializeDB(char *filename, struct employee *employees[])
{
    if(open_file(filename) == 0)
    {
        char buf[144];
        int size = 0;
        while(fgets(buf, sizeof(buf), file))
        {
            read_int(buf, 1, &employees[size].id);
            read_int(buf, 2, &employees[size].salary);
            read_string(buf, 1, employees[size].fname);
            read_string(buf, 2, employees[size].lname);
            size++;
        }
        if(feof(file))
            close_file(file);
    }
}

void printDB(struct employee employees[], int employee_count)
{
    printf("\nNAME\t\t\t\tSALARY\t   ID\n\n");
    for (int i = 0; i < employee_count; i++)
    {
        printf("%-15s\t%-15s\t%d\t%d\n", employees[i].fname, employees[i].lname, employees[i].salary, employees[i].id);
    }
    printf("Number of Employees (%d)\n", employee_count);
}

int lookupByID(struct employee employees[], int high, int low, int id)
{
    if (high >= low)
    {
        int mid = (high + low) / 2;
        if(employees[mid].id == id)
            return mid;
        else if (employees[mid].id < id)
            return lookupByID(employees, high, mid+1, id);
        else
            return lookupByID(employees, mid-1, low, id);
    }
    else
        return -1;
}

int lookupByLName(struct employee employees[], char lname[])
{
    for (int i = 0; i < sizeof(employees), i++)
    {
        if(strcmp(employees[i].lname, lname) == 0)
            return 0;
    }
    else
        return -1;
}

void sort(struct employee *employees, int n)
{
    int i, j;
    struct employee key;
    for (i = 1; i < n; i++)
    {
        key = employees[i];
        j = i - 1;
        while (j >= 0 && employees[j].id > key.id)
        {
            employees[j + 1] = employees[j];
            j--;
        }
        employees[j+1] = key;
    }
}

int addEmployee(struct employee *employees[])
{
    char employee_fname[MAXNAME];
    char employee_lname[MAXNAME];
    int employee_salary;
    int confirm;

    printf("\nEnter the first name of the employee: ");
    scanf("%s", employee_fname);

    int valid_fname = 1;                // parameter to check name validity for first name
    if (strlen(employee_fname) > 64)
    {
        valid_fname = 0;
    }
    else
    {
        for (int i = 0; i < strlen(employee_fname); ++i)
        {
            if (!(isalpha(employee_fname[i])))
            {
                valid_fname = 0;
                break;
            }
        }
    }

    if (!valid_fname)
    {
        printf("Invalid entry. Please try again.\n");
        return 0;
    }

    printf("Enter the last name of the employee: ");
    scanf("%s", employee_lname);

    int valid_lname = 1;                // parameter to check name validity for last name
    if (strlen(employee_lname) > 64)
    {
        valid_lname = 0;
    }
    else
    {
        for(int i = 0; i < strlen(employee_lname); ++i)
        {
            if(!(isalpha(employee_lname[i])))
            {
                valid_lname = 0;
                break;
            }
        }
    }
    if(!valid_lname)
    {
        printf("Invalid entry. Please try again.\n");
        return 0;
    }

    printf("Enter employee's salary (30000 to 150000): ");      // enter salary for the new employee
    scanf("%d", &employee_salary);

    if (employee_salary < 30000 || employee_salary > 150000)
    {
        printf("Invalid entry. Please try again.\n");
        return 0;
    }

    printf("\nDo you want to add the following employee to the DB?\n");
    printf("%s %s, \tSalary: %d\n", employee_fname, employee_lname, employee_salary);
    printf("\nEnter 1 for yes, 0 for no: ");
    scanf("%d", &confirm);

    if (confirm == 1)
    {
        strcpy(employeeDB[emp_count].fname, employee_fname);
        strcpy(employeeDB[emp_count].lname, employee_lname);
        employeeDB[emp_count].salary = employee_salary;
        employeeDB[emp_count].id = employeeDB[emp_count - 1].id + 1;
        emp_count++;
        printf("New employee %s %s added to the database\n", employee_fname, employee_lname);
    }

    return 1;
}
