#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(type, x, y){type t = x;x=y;y=t;}

void display(int* pArr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%5d", pArr[i]);
	}printf("\n");
}

int* randomize(int size) {
	int* pArr = (int*)calloc(size, sizeof(int));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		pArr[i] = rand() % 100;
	}
	return pArr;
}

void bubble(int* pArr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (pArr[j] > pArr[j + 1]) swap(int, pArr[j], pArr[j + 1]);
		}
	}
}

void insertion(int* pArr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (pArr[j] > pArr[i]) swap(int, pArr[j], pArr[i]);
		}
	}
}
void insertion_shell(int* pArr, int first, int size, int gap) {
	for (int i = first + gap; i < size; i += gap) {
		for (int j = first; j < i; j += gap) {
			if (pArr[j] > pArr[i]) swap(int, pArr[j], pArr[i]);
		}
	}
}
void shell_sort(int* pArr, int size) {
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = 0; i < gap; i++) {
			insertion_shell(pArr, i, size, gap);
		}
	}
	
}

int main() {
	int size, * arr = NULL;
	printf("배열의 크기: ");
	scanf_s("%d", &size);
	arr = randomize(size);
	printf("\n\n*** 정렬 전 자료 출력 ***\n\n");
	display(arr, size);

	printf("\n\n*** 정렬 후 자료 출력 ***\n\n");
	printf("Bubble sort: ");
	bubble(arr, size);
	display(arr, size);

	printf("Insertion sort: ");
	insertion(arr, size);
	display(arr, size);

	printf("Shell sort: ");
	shell_sort(arr, size);
	display(arr, size);

	free(arr);

	return 0;
}
