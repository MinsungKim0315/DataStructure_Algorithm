#include<stdio.h>
#include<stdlib.h>

typedef int QueueElement;
typedef struct QueueNode {
	QueueElement data;
	struct QueueNode* link;
}QueueNode;

typedef struct Queue {
	QueueNode* front, * rear;
}CircularLinkedQueueType;

CircularLinkedQueueType* QueueInit() {
	CircularLinkedQueueType* newQueue = (CircularLinkedQueueType*)malloc(sizeof(CircularLinkedQueueType));
	if (newQueue == NULL) exit(1);
	newQueue->front = newQueue->rear = NULL;

	return newQueue;
}

int QueueIsEmpty(CircularLinkedQueueType* queue) {
	return queue->front == NULL;
}

void Enqueue(CircularLinkedQueueType* queue, QueueElement data) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) exit(1);
	newNode->data = data;
	if (QueueIsEmpty(queue)) {
		newNode->link = newNode;
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->link = newNode;
		queue->rear = newNode;
		newNode->link = queue->front;
	}
}

QueueElement Dequeue(CircularLinkedQueueType* queue) {
	if (QueueIsEmpty(queue)) return 0;
	QueueNode* deleteNode = queue->front;
	QueueElement data = deleteNode->data;
	if (queue->front == queue->rear) queue->front = queue->rear = NULL;
	else {
		queue->rear->link = queue->front->link;
		queue->front = queue->rear->link;
	}
	free(deleteNode);
	return data;
}

void PrintQueue(CircularLinkedQueueType* queue) {
	if (QueueIsEmpty(queue)) printf("Empty Queue!\n");
	printf("Queue: ");
	QueueNode* pNode = queue->front;
	do {
		printf("%3d --> ", pNode->data);
		pNode = pNode->link;
	} while (pNode != queue->front);
	printf("%3d ... (back to front)\n", queue->front->data);
}

void FreeQueue(CircularLinkedQueueType* queue) {
	QueueNode* pNode = queue->front;
	QueueNode* delNode;
	do {
		delNode = pNode;
		pNode = pNode->link;
		free(delNode);
	} while (pNode != queue->front);
	free(queue);
}

int main() {
	CircularLinkedQueueType* queue1 = QueueInit();
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

	FreeQueue(queue1);
}
