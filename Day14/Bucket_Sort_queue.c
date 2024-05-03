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

void Endeque(LinkedQueueType* queue, QueueElement data, int direction) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) exit(1);
	newNode->data = data;
	newNode->link = NULL;
	if (QueueIsEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else if (direction == 1) {
		newNode->link = queue->front;
		queue->front = newNode;
	}
	else {
		queue->rear->link = newNode;
		queue->rear = newNode;
	}

}

QueueElement Dedeque(LinkedQueueType* queue, int direction) {
	if (QueueIsEmpty(queue)) return 0;
	QueueNode* deleteNode = NULL;
	QueueElement data = NULL;
	if (queue->front->link == NULL) queue->front = queue->rear = NULL;
	if (direction == 1) {
		deleteNode = queue->rear;
		data = deleteNode->data;
		QueueNode* pNode = NULL;
		for (pNode = queue->front; pNode->link->link != NULL; ) {
			pNode = pNode->link;
		}
		pNode->link = NULL;
		queue->rear = pNode;
	}
	else {
		deleteNode = queue->front;
		data = deleteNode->data;
		queue->front = deleteNode->link;
	}

	free(deleteNode);

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
