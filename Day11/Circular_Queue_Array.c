#include<stdio.h>
#include<stdlib.h>
typedef int QueueElement;
typedef struct Queue {
	QueueElement* data;
	int capacity;
	int front, rear;
	int size;
}CircularQueueType;

//ADT
CircularQueueType* QueueInit();
int QueueIsEmpty(CircularQueueType* queue);
int QueueIsFull(CircularQueueType* queue);
void Enqueue(CircularQueueType** queue, QueueElement data);
QueueElement Dequeue(CircularQueueType* queue);
void QueueResize(CircularQueueType** queue);
void PrintQueueu(CircularQueueType* queue);
void FreeQueue(CircularQueueType* queue);

CircularQueueType* QueueInit() {
	CircularQueueType* newqueue = (CircularQueueType*)malloc(sizeof(CircularQueueType));
	if (newqueue == NULL) exit(1);
	newqueue->front = newqueue->rear = newqueue->size = 0;
	newqueue->capacity = 1;
	newqueue->data = (QueueElement*)malloc(newqueue->capacity * sizeof(QueueElement));
	return newqueue;
}
int QueueIsEmpty(CircularQueueType* queue) { return (queue->size == 0); }
int QueueIsFull(CircularQueueType* queue) { return (queue->size == queue->capacity); }
void Enqueue(CircularQueueType** queue, QueueElement data) {
	if (QueueIsFull(*queue)) QueueResize(queue);
	(*queue)->data[(*queue)->rear] = data;
	(*queue)->rear = ((*queue)->rear + 1) % (*queue)->capacity;  //Circular queue
	(*queue)->size++;
}
QueueElement Dequeue(CircularQueueType* queue) {
	if (QueueIsEmpty(queue)) { printf(" Queue is empty.\n"); return 0; }
	QueueElement data = queue->data[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;  //Circular queue
	queue->size--;
	return data;
}
void QueueResize(CircularQueueType** queue) {
	CircularQueueType* newqueue = QueueInit();
	newqueue->capacity = (*queue)->capacity * 2;
	newqueue->data = (CircularQueueType*)realloc(newqueue->data, newqueue->capacity * sizeof(QueueElement));
	if (newqueue->data == NULL) exit(1);
	while (!QueueIsEmpty(*queue))	//copy data from old queue and paste them in the new one in the exact same position as before
		Enqueue(&newqueue, Dequeue((*queue)));
	FreeQueue(*queue);
	*queue = newqueue;
}
void PrintQueue(CircularQueueType* queue) {
	printf(" Queue -> ");
	for (int i = 0, j = queue->front; i < queue->size; i++, j = (j + 1) % queue->capacity)
		printf("%4d -> ", queue->data[j]);
	printf(" End\n\n");
}
void FreeQueue(CircularQueueType* queue) {
	free(queue->data);
	free(queue);
}


int main() {
	// Initialize the queue
	CircularQueueType* queue = QueueInit();

	// Check if the queue is initially empty
	printf("Is the queue empty? %s\n", QueueIsEmpty(queue) ? "Yes" : "No");

	// Enqueue elements
	Enqueue(&queue, 10);
	Enqueue(&queue, 20);
	Enqueue(&queue, 30);
	Enqueue(&queue, 40);  // This should trigger a resize
	Enqueue(&queue, 50);  // Continue after resize

	// Print the queue content
	PrintQueue(queue);

	// Dequeue some elements
	printf("Dequeued: %d\n", Dequeue(queue));
	printf("Dequeued: %d\n", Dequeue(queue));

	// Print the queue content again
	PrintQueue(queue);

	// Enqueue more elements to test wrapping
	Enqueue(&queue, 60);
	Enqueue(&queue, 70);

	// Print the queue to see final state
	PrintQueue(queue);
	printf("Is the queue full? %s\n", QueueIsFull(queue) ? "Yes" : "No");

	// Free the queue
	FreeQueue(queue);

	return 0;
}
