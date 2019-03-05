#include"cycle.h"

int main(){
	srand((unsigned) time(0));
	
	LinkedList ls = createList(10000);
	printf("first");
	createCycle(ls);
	printf("before");
	printf("%d",testCyclic(ls));

}
