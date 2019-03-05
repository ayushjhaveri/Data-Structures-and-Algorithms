#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
	int value;
	struct node* next;
}*Node;

typedef struct linkedList{
	Node head;
	int size;
}*LinkedList;

LinkedList createList(int N);

LinkedList createCycle(LinkedList ls);

int testCyclic(LinkedList ls);
