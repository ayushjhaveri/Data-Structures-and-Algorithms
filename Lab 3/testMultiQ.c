#include"multiq.h"
#include<sys/time.h>


MultiQ loadData(MultiQ mq){
	int ele=100, p=0;
	int i=10;
	 while ( i>0 )  
             { 
        ele=i*9;
        p=i;
		Priority prio= malloc(sizeof(struct priority));
		Element t = malloc(sizeof(struct element));
		prio->value = p;
		t->p=prio;
		t->value=ele;
		addMQ(mq,t);
		p++;
		ele++;
		i--;
             } 
}

MultiQ testDel(MultiQ mq,int num){
	for(int i=0;i<num;i++)
		printf("%d, %d\n",(nextMQ(mq))->value,(nextMQ(mq))->p->value);
		delNextMQ(mq);
	
}

int main(){
	
	struct timeval t1,t2;
	double elapsedTime;
	
	//start timer
	gettimeofday(&t1,NULL);
	
	MultiQ mq = malloc(sizeof(struct multiq)); 
	mq = createMQ(11000000);	
	
	//FILE *in_file  = fopen("input10.txt","r");
	loadData(mq);
	testDel(mq,40000);
	
	//stop timer
	gettimeofday(&t2,NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %lf ms.\n",elapsedTime);
	
return 0;
}
