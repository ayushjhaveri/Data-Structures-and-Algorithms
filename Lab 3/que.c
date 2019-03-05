#include"que.h"

Queue newQ(){
	Queue q = (Queue)malloc(sizeof (struct queue));
	q->count=0;
	q->head =(Node)malloc(sizeof(struct node));
	q->tail =(Node)malloc(sizeof(struct node));	
	q->head=NULL;
	q->tail=NULL;
	
	return q;
}

int isEmptyQ(Queue q){
	if(q->count==0)return 1;
	else return 0;
}

Queue delQ(Queue q){
	if(!isEmptyQ(q)){
		q->head = q->head->next;
		q->count--;
	}
	return q;
}

Element front(Queue q){
	return q->head->ele;
}

Queue addQ(Queue q, Element e){
	Node node1 = (Node)malloc(sizeof(struct node));
	//node1->ele = malloc(sizeof(struct element));
	node1->ele = e;
	node1->next=NULL;	
	if(q->count==0){
		q->head=node1;
		q->tail=node1;
		q->count=1;	
	}else{
		q->tail->next=node1;
		q->tail=node1;	
		q->count++;	
	}
	return q;
}

int lengthQ(Queue q){
	return q->count;
}
