#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef int element;
typedef struct Heap {
	int capacity;	// total size of array
	int size;		// index for the room for saving element
	element* ary;	// pointer that points the room for saving element
}Heap;

// ADT
Heap* heapInitialize();
void heapAdd(Heap* heap, element value);
element heapRemove(Heap* heap);
void heapSort(element* arr, int size);
void heapFree(Heap** heap);
void printHeap(Heap* heap);
void arrDisplay(element* arr, int size);

int main() {
	element arr[] = { 12, 15, 21, 6, 30, 3, 24, 27, 9, 18 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Heap* heap = heapInitialize();
	printf("Original Array:	");
	arrDisplay(arr, size);
	for (int i = 0; i < size; i++) {
		heapAdd(heap, arr[i]);
	}
	printf("Heap Array: ");
	arrDisplay(heap->ary, heap->size);
	printHeap(heap);
	heapSort(arr, size);
	printf("Sort Array: ");
	arrDisplay(arr, size);
	heapFree(&heap);

	return 0;
}

Heap* heapInitialize() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	if (heap == NULL) return NULL;
	heap->capacity = 2;
	heap->size = 1;	//array start from 1 instead of 0
	heap->ary = (element*)calloc(heap->capacity, sizeof(element));
	if (heap->ary == NULL) return NULL;
	return heap;
}
void heapAdd(Heap* heap, element value) {
	/*
	1. Check if there is enough space. If not, extend array
	2. Compare new value with parent and swap if needed
	*/
	if (heap->size == heap->capacity) {	// resizing heap
		heap->capacity = heap->capacity * 2;
		element* oldarray = heap->ary;
		heap->ary = (element*)realloc(heap->ary, heap->capacity * sizeof(element));
		if (heap->ary == NULL) { free(oldarray); exit(1); }
	}
	int input = heap->size++;
	while (input != 1 && value > heap->ary[input / 2]) {	// comparing with parent
		heap->ary[input] = heap->ary[input / 2];	// swap parent with new value
		input = input / 2;
	}
	heap->ary[input] = value;
}
element heapRemove(Heap* heap) {
	/*
	1. Save root value to a new variable
	2. Move the value in the last node to the root
	3. Resort the heap
	*/
	if (heap->size <= 1) return 0;
	element root = heap->ary[1];
	element insert = heap->ary[--heap->size];

	if (2 < heap->capacity && heap->size < heap->capacity / 2) {	// resizeing heap
		heap->capacity = heap->capacity / 2;
		element* oldarray = heap->ary;
		heap->ary = (element*)realloc(heap->ary, heap->capacity * sizeof(element));
		if (heap->ary == NULL) { free(oldarray); exit(1); }
	}

	int parent = 1, child = 2;
	while (child < heap->size) {	// shift down
		if (child + 1 < heap->size && heap->ary[child] < heap->ary[child + 1]) child++;	// compare left and right child
		if (insert >= heap->ary[child]) break;	// compare child and parent
		heap->ary[parent] = heap->ary[child];	// insert child into parent
		parent = child;	// parnet -> child
		child = child * 2;	//child -> grandchild
	}
	heap->ary[parent] = insert;	// final destination 

	return root;
}
void heapSort(element* arr, int size) {
	Heap* heap = heapInitialize();
	for (int i = 0; i < size; i++) {
		heapAdd(heap, arr[i]);
	}
	for (int i = 0; i < size; i++) {
		arr[i] = heapRemove(heap);
	}
	heapFree(&heap);
}
void heapFree(Heap** heap) {
	free((*heap)->ary);
	free(*heap);
	*heap = NULL;
	printf("Free Heap\n");
}
void printHeap(Heap* heap) {
	if (heap->size <= 1) return;
	printf("\n");
	for (int i = 1, level = 1; i < heap->size; i++) {
		printf("%3d", heap->ary[i]);
		if (i == (int)pow(2, level) - 1) {
			printf("\n");
			level++;
		}
	}
	printf("\n\n");
}
void arrDisplay(element* arr, int size) {
	for (int i = 0; i < size; i++) printf("%5d", arr[i]);
	printf("\n");
}
