#include<stdio.h>
#include<stdlib.h>

typedef struct element{
	char name[10];
	float cgpa;
}*Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);

void mergeSort(Element Ls[],int p, int r);

void iterMergeSort(Element Ls[],int p, int r);
