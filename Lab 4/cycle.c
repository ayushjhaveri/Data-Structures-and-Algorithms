#include"cycle.h"

LinkedList createList(int N){

	LinkedList ls=(LinkedList)malloc(sizeof(struct linkedList));
	int i=0;
	while(i<N){
		int random = rand();
		Node node = (Node)malloc(sizeof(struct node));
		node->value=random;
		node->next=NULL;
		ls->size++;
		if(i==0){
			ls->head=node;
		}else{
			Node temp=ls->head;
			while(temp->next){
				temp=temp->next;
			}
			temp->next=node;
		}
		i++;
	}
	
	return ls;
}

LinkedList createCycle(LinkedList ls){
	int random=11;
	//int random = rand();
	if(random%2==0){
		int r = rand();
		Node temp = ls->head;
		while(temp->next){
				temp=temp->next;
		}
		temp->next=ls->head;
	}
	return ls;	
}

//int testCyclic(LinkedList ls){
	
	//int i=1;
	//Node temp=ls->head;
	//while(i<ls->size){
	//	temp=temp->next;
//		i++;
	//}
	//if(temp->next)return 1;
	//return 0;

//}























