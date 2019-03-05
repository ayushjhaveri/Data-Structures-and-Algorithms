#include"que.h"

int main(){

	//Queue q = malloc(sizeof(struct queue)); 
	Queue q=newQ();
	
	
	Element e[10];
	for(int i=0;i<10;i++){
		e[i]=malloc(sizeof(struct element));
		(e[i])->value=i*2;
		e[i]->p=malloc(sizeof(struct priority));
		(e[i])->p->value=i;			
		addQ(q,e[i]);	
		//printf("%d %d\n",q->count, front(q)->value);	
	}
	//printf("%d",q->count);
	//printf("%d",isEmptyQ(q));
	for(int i=0;i<10;i++){
		printf("%d,%d\n",front(q)->value, front(q)->p->value);
		delQ(q);
	}
	return 0;
	


}
