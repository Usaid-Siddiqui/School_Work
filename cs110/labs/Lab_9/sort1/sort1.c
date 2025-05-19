#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef
struct _employee {
	char first[30];
	char last[30];
    double rate;
    int hours;
}
Employee;

Employee *readEmployee(FILE *fp)
{
    Employee *temp=malloc(sizeof(Employee));
    int i = fscanf(fp, "%s %s %lf %d", temp->first, temp->last, &(temp->rate), &(temp->hours));
    if (i<1) return NULL;
    else return temp;
}

void writeEmployee(FILE *fp, Employee *ptr)
{
	fprintf(fp, "%s\t%s\t%g\t%d\n", ptr->first, ptr->last, ptr->rate, ptr->hours);
}

void copyEmployee(Employee *pDest, Employee *pSrc)
{
    *pDest = *pSrc;
}

int cmpEmployeesByNames(const void *first, const void *second) {
	const Employee *emp1 = (const Employee *)first;
    const Employee *emp2 = (const Employee *)second;

    // Compare last names
    int lastNameComparison = strcmp(emp1->last, emp2->last);
    if (lastNameComparison != 0) {
        return lastNameComparison;
    }

    // If last names are the same, compare first names
    return strcmp(emp1->first, emp2->first);
}

int main(int argc, char *argv[])
{
    if (argc!=3) {
        printf("Usage: %s in_file our_file\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp==NULL) {
        printf("Unable to open the file %s for reading\n", argv[1]);
        return 2;
    }
    FILE *fpOut=fopen(argv[2], "w");
    if (fpOut==NULL) {
        printf("Unable to open the file %s for writing\n", argv[2]);
        return 3;
    }

	Employee emp_array[100];

	int count;
	for (count=0; count<100; count++) {
        Employee *ptr=readEmployee(fp);
        if (ptr==NULL) break;
		copyEmployee(emp_array+count, ptr);
		free(ptr);
    }
    fclose(fp);

	// printf("There are %d hourly employees\n", count);

	qsort(emp_array, count, sizeof(Employee), cmpEmployeesByNames);

	for (int i=0; i<count; i++) {
		writeEmployee(fpOut, emp_array+i);
	}
    fclose(fpOut);

    return 0;
}
