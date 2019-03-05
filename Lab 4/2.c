#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int free1 ;

void* myalloc(int size)
{
  free1 += size ;
  return malloc(size) ;
}

void free_mem(void* ptr,int size)
{
  free1 -= size ;
  free(ptr) ;
}

int main()
{
  free1 = 0 ;
  srand(time(0));
  while(1)
  {
        int randnum = rand()%(15001) + 10000 ;
        int* x = (int*) myalloc(sizeof(int)*randnum) ;
        if(x==NULL){
          printf("Failure\n") ;
          break;
        }
        printf("%p , %p \n",x,&(x[randnum-1])) ;
        free_mem(x,sizeof(int)*randnum);
  }
  return 0;
}
