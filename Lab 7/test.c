#include<stdio.h>
#include<stdlib.h>

typedef struct employee{
	char name[10];
	int id;
}*Employee;

int main(){
	
	Employee *e1 = (Employee*)malloc(sizeof(Employee)*2);
	Employee *e2 = (Employee*)malloc(sizeof(Employee)*2);
	Employee emp1 = (Employee)malloc(sizeof(struct employee));
	emp1->id = 1;
	Employee emp2 = (Employee)malloc(sizeof(struct employee));
	emp2->id=2;
	
	e1[0]=emp1;
	e1[1]=emp2;		
	
	e2[0]=e1[0];
	e2[1]=e1[1];
	
	e1[0]=emp2;
	e1[1]=emp1;
	
	
	printf("%d\n",e1[0]->id);
	printf("%d\n",e1[1]->id);
	
	
	
	printf("%d\n",e2[0]->id);
	printf("%d\n",e2[1]->id);
	
}
