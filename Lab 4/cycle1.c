#include"cycle.h"

int testCyclic(LinkedList ls){

	if(!ls->head)return 0;

	Node hare=ls->head;
	Node tort=ls->head;
	
	do{
		if(!(hare=hare->next) || !(hare=hare->next))return 0;
		tort=tort->next;
		
	
	}while(tort!=hare);
	
	return 1;
	

}
