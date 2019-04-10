#include"ex1.h"
#include<sys/time.h>

int main(){

	FILE *fptr;
	struct timeval t1,t2;
	
	if ((fptr = fopen("100000","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
	
	printf("Hey\n");
	int capacity=10;
	Employee *e =(Employee *)malloc(sizeof(Employee)*capacity) ;
	int count = 0;
	e[count] = (Employee)malloc(sizeof(struct employee));
	
	while(fscanf(fptr,"%[^ ] %d\n",e[count]->name,&e[count]->empID) != EOF){
		
		if(++count==capacity){
			capacity*=2;
			e =(Employee *)realloc(e,sizeof(Employee)*capacity);
		}
		
		printf("%d\n",e[count-1]->empID);
		
		e[count] = (Employee)malloc(sizeof(struct employee));	
	
	}
	int estimate = estimateCutoff(e,count);
	
		
	gettimeofday(&t1,NULL);
	QuickSort(e,0,count-1,estimate);
	
	//InsertionSort(e,count);
	gettimeofday(&t2,NULL);
	
	double elapsedTime;
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	
	printf("\n");
	for(int i=0;i<count;i++) printf("%d\n",e[i]->empID);
	
	printf("Time Taken: %lf\n",elapsedTime);
		printf("esitmate: %d\n",estimate);

}
