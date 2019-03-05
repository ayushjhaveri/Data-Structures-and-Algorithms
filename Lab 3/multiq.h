#include"que.h"



typedef struct multiq{
	Queue *q;
	int no_priority;
	int no_tasks;
}*MultiQ;

MultiQ createMQ(int num);

MultiQ addMQ(MultiQ mq, Element t);

Element nextMQ(MultiQ mq);

MultiQ delNextMQ(MultiQ mq);

int isEmptyMQ(MultiQ mq);

int sizeMQ(MultiQ mq);

int sizeMQbyPriority(MultiQ mq, Priority p);

Queue getQueueFromMQ(MultiQ, Priority p);
