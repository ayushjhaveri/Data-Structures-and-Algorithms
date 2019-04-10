#include"ex1.h"
#include<sys/time.h>


double testRun(Employee e[], int size){
	
	Employee *e1 = (Employee *)malloc(sizeof(Employee)*size);
	Employee *e2 = (Employee *)malloc(sizeof(Employee)*size);

	for(int i=0;i<size;i++){
		e1[i]=e[i];
		e2[i]=e[i];
	}

	double times[2];
	struct timeval t1,t2,t3;
	
	gettimeofday(&t1,NULL);
	
	InsertionSort(e1,0,size-1);
	
	gettimeofday(&t2,NULL);
	
	QuickSort(e2,0,size-1,0);
	
	gettimeofday(&t3,NULL);
	
	times[0] = (t2.tv_sec - t1.tv_sec) * 1000.0;
	times[0] += (t2.tv_usec - t1.tv_usec) / 1000.0;
	
	times[1] = (t3.tv_sec - t2.tv_sec) * 1000.0;
	times[1] += (t3.tv_usec - t2.tv_usec) / 1000.0;
	
	return times[1]-times[0];
}



int estimateCutoff(Employee e[], int size){

	int l=0,r=size-1, mid;
	double accuracy=0;
	double d1,d2,d3;
	
	while(l<r){
		
		mid=(l+r)/2;
		//d1 = testRun(e,l+1);
		//d2 = testRun(e,r+1);
		d3 = testRun(e,mid+1);
	
		if(d3<=accuracy && (d3>=accuracy*-1)) return mid+1;
		//if(d1<=accuracy && (d1>=accuracy*-1)) return l+1;
		//if(d2<=accuracy && (d2>=accuracy*-1)) return r+1;
		
		//if(d1<0)return l+1;
		//if(d2>0)return r+1;
		
		//now we know that d1>=0 && d2<=0
		if(d3>0)l=mid+1;
		else r=mid-1;
	
	}
	return mid+1;
	
}


