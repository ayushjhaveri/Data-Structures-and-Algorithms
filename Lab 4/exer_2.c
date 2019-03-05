	#include<stdio.h>
#include<stdlib.h>

int space;

void *myalloc(int size){
	space+=size;
	return malloc(size);
}

void myfree(void *ptr, int size){
	free(ptr);
	space-=size;
}

int main(){
	srand(time(0));
	space=0;
	
	while(1){
		int random = rand()%(15001) + 10000;
		printf("%d ",random);
		int *x = (int*)myalloc(sizeof(int)*random);
		if(x==NULL){
			printf("Failure\n");
			break;
		}
		
		
		printf("%d: %p %p\n",random,x,&(x[random-1]));
		myfree(x,sizeof(int)*random);
		
	}

}
