#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(type, x, y){type t = x; x = y;y = t;}

typedef int QueueElement;
typedef struct QueueNode {
	QueueElement data;
	struct QueueNode* link;
}QueueNode;
typedef struct Queue {
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
void FreeQueue(LinkedQueueType* queue) {
	for (QueueNode* pNode = queue->front; pNode != NULL;) {
		QueueNode* deleteNode = pNode;
		pNode = pNode->link;
		free(deleteNode);
	}
	free(queue);
}

void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%7d ", arr[i]);
	}printf("\n");
}
void randomize(int* arr, int str, int end, int size) {
	if (str > end) swap(int, str, end);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (end - str + 1) + str;
}
void bucket(int* arr, int size) {
	LinkedQueueType* bucket1[10];
	LinkedQueueType* bucket2[10];
	for (int i = 0; i < 10; i++) {
		bucket1[i] = QueueInit();
		bucket2[i] = QueueInit();
	}

	for (int i = 0; i < size; i++) {	//1의 자리 수 맞게 버켓1에 dequeue
		Enqueue(bucket1[arr[i] % 10], arr[i]);
	}

	for (int i = 0; i < 10; i++) {	//10의 자리 수 맞게 버켓1에서 dequeue 후 bucket2에 enqueue
		while (QueueIsEmpty(bucket1[i]) != 1) {
			int temp = Dequeue(bucket1[i]);
			Enqueue(bucket2[(temp / 10) % 10], temp);
		}
	}
	
	for (int i = 0, j = 0; i < size; i++) {	//bucket2 순서대로 arr 정렬
	while(QueueIsEmpty(bucket2[j]))j++;	//빈칸인 인댁스 지나기
	arr[i] = Dequeue(bucket2[j]);
	}
	
	for (int i = 0; i < 10; i++) {
		FreeQueue(bucket1[i]);
		FreeQueue(bucket2[i]);
	}

}
