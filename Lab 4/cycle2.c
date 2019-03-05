#include"cycle.h"

int testCyclic(LinkedList ls){

	if(!ls->head)return 0;
	if(!ls->head->next)return 0;
	
	Node prev;
	Node current = ls->head->next;
	Node next;

	while(current){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		if(current==ls->head)return 1;
	}
	return 0;

	
}
