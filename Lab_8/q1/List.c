#include "List.h"


List createList(Student studArray, int arraySize){

	List list = (List)myalloc(sizeof(struct list));
	list->count=0;
	list->first=NULL;
	list->last=NULL;

	if(arraySize==0)return list;
	
	
	Student student = (Student)myalloc(sizeof(struct student));
	student = &studArray[0];
	Node temp = (Node)myalloc(sizeof(struct node));
	temp->record = student;
	temp->next = NULL;
	 
	list->first = temp;
	list->count++;
	
	for(int i=1;i<arraySize;i++){
		Student student = (Student)myalloc(sizeof(struct student));
		student = &studArray[i];
		Node node =(Node)myalloc(sizeof(struct node));
		node->record = student;
		node->next = NULL;
		temp->next=node;
		temp = temp->next;
		list->count++;
	}	
	list->last=temp;
	
	return list;

}

void insertInOrder(List list, Node newNode){
	
	//if node is null
	if(newNode==NULL)return;
	
	//if list is empty
	if(list->count==0){
		list->first=newNode;
		list->last=newNode;
		list->count++;
		return;
	}
	
	float marks = newNode->record->marks;
	
	//if marks less than head
	if(marks< list->first->record->marks){
		newNode->next = list->first;
		list->first = newNode;
		list->count++;
		return;
	}
	
	Node temp = list->first;
	
	//if size of list is 1 (has to be greater than head after previous case)
	if(list->count == 1){
		newNode->next = NULL;
		temp->next = newNode;
		list->last=newNode;
		list->count++;
		return;
	}
	
	//else
	for(int i=1;i<list->count;i++){
		if(marks < temp->next->record->marks){
			newNode->next = temp->next;
			temp->next = newNode;
			list->count++;
			return;
		}
		temp = temp->next;
	}
	//if greater than all
	newNode->next=NULL;
	temp->next = newNode;
	list->last = newNode;
	list->count++;
	return;
}


List insertionSort(List list){
	
	if(list->count ==0 || list->count ==1)return list;
	
	List newList = malloc(sizeof(struct list));
	newList->first = list->first;
	newList->last = list->first;
	newList->count=1;

	Node temp;
	Node next = list->first->next;
	
	for(int i=1;i<list->count;i++){
		temp=next;
		next = temp->next;
		insertInOrder(newList,temp);
	}
	
	free(list);
	return newList;
}

double measureSortingTime(List list){

	struct timeval t1,t2;
	double elapsedTime;
	
	gettimeofday(&t1,NULL);
	
	insertionSort(list);	
	
	gettimeofday(&t2,NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;
	
	return elapsedTime;
}

void *myalloc(int size){
	globalCounter+=size;
	return malloc(size);
}

void myfree(void* ptr){
	globalCounter -= sizeof(ptr);
	free(ptr);
}
