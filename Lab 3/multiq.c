#include"multiq.h"

MultiQ createMQ(int num){
	MultiQ mq = (MultiQ)malloc(sizeof(struct multiq));
	Queue *q = (Queue *)malloc(sizeof(Queue)*num);
	

	for(int i=0;i<num;i++){
		q[i] = newQ();
	}

	mq->q = q;
	mq->no_priority=num;
	mq->no_tasks = 0;

	return mq;
}

MultiQ addMQ(MultiQ mq, Element t){
	
	addQ((mq->q)[t->p->value], t);
}

Element nextMQ(MultiQ mq){
	for(int i=0;i<(mq->no_priority);i++){
		if(!isEmptyQ((mq->q)[i])){
			return front((mq->q)[i]);	
		}
		
	}
}

MultiQ delNextMQ(MultiQ mq){

	for(int i=0;i<(mq->no_priority);i++){
		if(!isEmptyQ((mq->q)[i])){
			delQ((mq->q)[i]);	
			return mq;
		}
		
	}
	return mq;	
}

int isEmptyMQ(MultiQ mq){
	for (int i=0;i<mq->no_priority;i++){
		if(!isEmptyQ((mq->q)[i])) 
			return 0;
	
	}
	return 1;
}

int sizeMQ(MultiQ mq){
	return mq->no_tasks;
}

int sizeMQbyPriority(MultiQ mq, Priority p){
	return lengthQ((mq->q)[p->value]);
}

Queue getQueueFromMQ(MultiQ mq, Priority p){
	return (mq->q)[p->value];

}


