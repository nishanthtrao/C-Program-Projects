#include <stdio.h>
#include "reader.h"

// Declare a file pointer
FILE *file;

int read_int(char *line, int option, int *var)
{
    int id;             // Database ID field
    int salary;         // Database salary
    char fname[64];     // First name
    char lname[64];     // Last name

    if(option == 1)
    {
        sscanf(line, "%d %s %s %d", var, fname, lname, &salary);
    }
    else
    {
        sscanf(line, "%d %s %s %d", &id, fname, lname, var);
    }
    return 0;
}

int read_float(char *line)
{
    return 1;
}

int read_string(char *line, int option, char *str)
{
    int id;             // Database ID field
    int salary;         // Database salary
    char fname[64];     // First name
    char lname[64];     // Last name

    if(option == 1)
    {
        sscanf(line, "%d %s %s %d", &id, str, lname, &salary);
    }
    else
    {
        sscanf(line, "%d %s %s %d", &id, fname, str, &salary);
    }
    return 0;
}

int open_file(char *filename)
{
    file = fopen(filename, "r");
    if(file == 0)
        return -1;
    else
        return 0;
}

int close_file()
{
    fclose(file);
}
