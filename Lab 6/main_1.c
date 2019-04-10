#include"merge.h"
#include<sys/time.h>
int main(){

	Element *Ls;
	Ls= (Element *)malloc(sizeof(Element)*1024);
	int capacity=1024;
	int count=0;
	
	struct timeval t1, t2;
	double elapsedTime;
	
	FILE *fptr;
	if ((fptr = fopen("1024.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   
   Ls[0] = (Element)malloc(sizeof(struct element));
   
   printf("Hey");
   while(fscanf(fptr,"%[^,]\ %d\n",Ls[count]->name,&Ls[count]->cgpa) != EOF){
		count++;
		if(count>capacity){
			capacity*=2;
			Ls = (Element *)realloc(Ls,sizeof(Element)*capacity);
		}
		Ls[count]=(Element)malloc(sizeof(struct element));
		printf("%d: ",count);
		printf("%f\n", Ls[count-1]->cgpa);
		
	}
	
	gettimeofday(&t1, NULL);
	mergeSort(Ls,0,1023);
	gettimeofday(&t2, NULL);
	
	for(int i=0;i<count;i++){
		printf("%d: %f\n",i,Ls[i]->cgpa);
	
	}
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %lf ms.\n",elapsedTime);
	
	
	

}
