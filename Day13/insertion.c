#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define swap(type, x, y){type t = x;x = y;y = t;}

void randomize(int* arr, int st, int end, int size) {
	if (st > end) swap(int, st, end);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (end - st + 1) + st;
}
void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%7d ", arr[i]);
	}
	printf("\n");
}
void insertionSort(int* arr, int size) {
	int i, j;
	for (i = 1; i < size; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			swap(int, arr[j], arr[j - 1]);
			j--;
		}
	}
}

int main() {
	int size, st, end;
	int* arr;
	printf("insert size of array: ");
	scanf_s("%d", &size);
	arr = (int*)malloc(sizeof(int) * size);
	printf("insert starting and ending number: ");
	scanf_s("%d%d", &st, &end);
	randomize(arr, st, end, size);
	printf("\n\n ***Array before sort***\n\n");
	display(arr, size);
	insertionSort(arr, size);
	printf("\n\n ***Array after sort***\n\n");
	display(arr, size);
	free(arr);

	return 0;
}
