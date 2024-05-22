#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define swap(type, x, y){type t = x;x = y;y = t;}

void randomize(int* arr, int st, int end, int size) {
	if (st > end) swap(int, st, end);
	for (int i = 0; i < size; i++) arr[i] = rand() % (end - st + 1) + st;
}
void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%7d ", arr[i]);
	}
	printf("\n");
}
void insertion_shell(int* arr, int first, int size, int gap) {
	int i, j;
	for (i = first + gap; i < size; i += gap) {
		j = i;
		while (j - gap > 0 && arr[j - gap] > arr[j]) {
			swap(int, arr[j], arr[j - gap]);
			j -= gap;
		}
	}
}
void shellSort(int* arr, int size) {
	int i, gap;
	for (gap = size / 2; gap > 0; gap /= 2) {
		if ((gap % 2) == 0) gap++;
		for (int i = 0; i < gap; i++) {
			insertion_shell(arr, i, size, gap);
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
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
	shellSort(arr, size);
	printf("\n\n ***Array after sort***\n\n");
	display(arr, size);
	free(arr);

	return 0;
}
