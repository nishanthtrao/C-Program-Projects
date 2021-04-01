#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

struct employee employeeDB[1024];

int main(int argc, char *argv[])
{
    if (argc != 2)
        printf( "usage: %s filename\n", argv[0]);
    else
    {
        struct employee *employees[1024];
        employees = &employeeDB[1024];

        initializeDB(argv[1], employees);  // create the database with the input file
        sort(employeeDB, sizeof(employees));    // sort the database by ID

        int choice;
        int pos = 0;

        // display menu
        while (1)
        {
            printf("\nEmployee DB Menu:\n\n");
            printf("1. Print the Database\n");
            printf("2. Lookup by ID\n");
            printf("3. Lookup by Last Name\n");
            printf("4. Add an Employee\n");
            printf("5. Quit\n\n");
            printf("Enter your choice: ");

            scanf("%d", &choice);

            //Select the appropriate function based on user selection.
            switch (choice)
            {
            case 1:
                printDB(employeeDB, emp_count);
                break;
            case 2:
                ;
                int lookupID; //target employee ID to search

                printf("\nEnter a 6 digit employee ID: ");
                scanf("%d", &lookupID);

                pos = lookupByID(employeeDB, 0, emp_count, lookupID);

                if (pos == -1)
                {
                    printf("\nUser with employee ID '%d' not found\n", lookupID);
                }
                else
                {
                    printf("\nNAME\t\t\t\tSALARY\t   ID\n");
                    printf("%-15s\t%-15s\t%d\t%d\n", employeeDB[pos].fname, employeeDB[pos].lname, employeeDB[pos].salary, employeeDB[pos].id);
                }
                break;
            case 3:
                ;
                char lookupName[MAXNAME]; //target name to search
                printf("\nPlease enter an employee's last name: ");
                scanf("%s", lookupName);
                pos = lookupByLName(employeeDB, emp_count, lookupName);
                if (pos == -1)
                {
                    printf("\nUser with last name '%s' not found\n", lookupName);
                }
                else
                {
                    printf("\nNAME\t\t\t\tSALARY\t   ID\n");
                    printf("%-15s\t%-15s\t%d\t%d\n", employeeDB[pos].fname, employeeDB[pos].lname, employeeDB[pos].salary, employeeDB[pos].id);
                }
                break;
            case 4:
                addEmployee(employeeDB);
                break;
            case 5:
                printf("\ngoodbye!\n");
                return 0;
                break;
            default:
                printf( "\nHey, %d is not between 1 and 5. Try again.\n", choice);
                break;
            }
        }
    }
}
