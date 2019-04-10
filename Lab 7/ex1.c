#include"ex1.h"

void QuickSort(Employee e[],int l, int h, int S){

	int stack[h-l+1];
	int top = -1;

	stack[++top] = l;
	stack[++top] = h;
	
	if(h-l+1<=S)return;
	
	while(top >= 0){
	
		h = stack[top--];
		l = stack[top--];
		
		int p = partition(e,l,h);
		
		if(p-1>l && p-l+1>S){
			stack[++top]=l;
			stack[++top]=p-1;
		}else if(p-l+1<=S)InsertionSort(e,l,p);
		if(p+1<h && h-p>S){
			stack[++top]=p+1;
			stack[++top]=h;		
		}else if(h-p<=S)InsertionSort(e,p+1,h);
		
	
	}
}

int partition(Employee e[], int l, int h){

	int x = e[h]->empID;
	int i = l-1;
	
	for(int j=l; j<h; j++){
		if(e[j]->empID <= x){
			i++;
			Employee temp = e[i];
			e[i]=e[j];
			e[j]=temp;
		}
	
	}
	Employee temp = e[i+1];
	e[i+1]=e[h];
	e[h]=temp;
		
	return i+1;
}

void InsertionSort(Employee *e, int l, int h){

	Employee key;
	
	for(int j=l+1;j<h+1;j++){
		
		key = e[j];
		
		int i=j-1;
		while(i>=0 && e[i]->empID > key->empID){
			e[i+1]=e[i];
			i--;
		}		
		e[i+1]=key;
	}
}













