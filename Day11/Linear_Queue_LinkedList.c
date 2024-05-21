#include<stdio.h>
#include<stdlib.h>

typedef int QueueElement;
typedef struct QueueNode {
	QueueElement data;
	struct QueueNode* link;
}QueueNode;
typedef struct Queue{
	QueueNode* front, * rear;
}LinkedQueueType;
//ADT
LinkedQueueType* QueueInit();
int QueueIsEmpty(LinkedQueueType* queue);
void Enqueue(LinkedQueueType* queue, QueueElement data);
QueueElement Dequeue(LinkedQueueType* queue);
void PrintQueue(LinkedQueueType* queue);
void FreeQueue(LinkedQueueType* queue);

LinkedQueueType* QueueInit() {
	LinkedQueueType* newQueue = (LinkedQueueType*)malloc(sizeof(LinkedQueueType));
	if (newQueue == NULL) exit(1);
	newQueue->front = newQueue->rear = NULL;

	return newQueue;
}
int QueueIsEmpty(LinkedQueueType* queue) {
	return (queue->front == NULL);
}
void Enqueue(LinkedQueueType* queue, QueueElement data) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) exit(1);
	newNode->data = data;
	newNode->link = NULL;
	if (QueueIsEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->link = newNode;
		queue->rear = newNode;
	}
}
QueueElement Dequeue(LinkedQueueType* queue) {
	if (QueueIsEmpty(queue)) return 0;
	QueueNode* deleteNode = queue->front;
	QueueElement data = deleteNode->data;
	queue->front = deleteNode->link;
	if (queue->front == NULL) queue->rear = NULL;
	free(deleteNode);

	return data;
}
void PrintQueue(LinkedQueueType* queue) {
	printf("queue: ");
	for (QueueNode* pNode = queue->front; pNode != NULL; pNode = pNode->link) {
		printf("%4d --> ", pNode->data);
	}printf("\n");
}
void FreeQueue(LinkedQueueType* queue) {
	for (QueueNode* pNode = queue->front; pNode != NULL;) {
		QueueNode* deleteNode = pNode;
		pNode = pNode->link;
		free(deleteNode);
	}
	free(queue);
}
//Deque ADT
void Endeque(LinkedQueueType* queue, QueueElement data, int derection);
QueueElement Dedeque(LinkedQueueType* queue, int direction);

void Endeque(LinkedQueueType* queue, QueueElement data, int direction) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) exit(1);
	newNode->data = data;
	newNode->link = NULL;
	if (QueueIsEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else if (direction == 1) {	//insert data in the front(deque)
		newNode->link = queue->front;
		queue->front = newNode;
	}
	else {	//insert data in the rear
		queue->rear->link = newNode;
		queue->rear = newNode;
	}
}
QueueElement Dedeque(LinkedQueueType* queue, int direction) {
	if (QueueIsEmpty(queue)) return 0;
	QueueNode* delNode =NULL;
	QueueElement data = 0;
	if (direction == 1) {	//get data in the rear
		delNode = queue->rear;
		QueueNode* pNode = queue->front;
		while (pNode->link != queue->rear) {
			pNode = pNode->link;
		}
		pNode->link = NULL;
		queue->rear = pNode;
	}
	else {	//get data in the front
		delNode = queue->front;
		queue->front = delNode->link;
	}
	data = delNode->data;
	free(delNode);

	return data;
}

int main() {
	LinkedQueueType* queue1 = QueueInit();
	Enqueue(queue1, 6);
	Enqueue(queue1, 1);
	Enqueue(queue1, 2);
	Enqueue(queue1, 3);
	Enqueue(queue1, 4);
	Enqueue(queue1, 5);
	Enqueue(queue1, 7);
	PrintQueue(queue1);

	Dequeue(queue1);
	PrintQueue(queue1);

	Endeque(queue1, 0, 1);
	PrintQueue(queue1);

	Dedeque(queue1, 1);
	PrintQueue(queue1);

	FreeQueue(queue1);
}
