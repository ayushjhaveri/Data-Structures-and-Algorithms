#include<stdio.h>
#include<stdlib.h>

typedef struct priority{
	int value;
}*Priority;

typedef struct element{
	int value;
	Priority p;
}*Element;


typedef struct node{
	Element ele;
	struct node *next;
}*Node;


typedef struct queue{
	Node head;
	Node tail;
	int count;
}*Queue;

//typedef enum{
	//false,true
//}Boolean;



Queue newQ();

int isEmptyQ(Queue q);

Queue delQ(Queue q);

Element front(Queue q);

Queue addQ(Queue q, Element e);

int lengthQ(Queue q);
