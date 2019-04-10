#include<stdio.h>
#include<stdlib.h>

typedef struct employee{
	char name[10];
	int empID;
}*Employee;

void QuickSort(Employee *e,int l, int h, int S);

int partition(Employee e[], int l, int h);

void InsertionSort(Employee *e, int l, int h);

double testRun(Employee e[], int size);

int estimateCutoff(Employee e[], int size);
