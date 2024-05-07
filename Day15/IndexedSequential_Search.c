#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INDEX_SIZE 5

typedef struct itable {
	int index;
	int key;
}itable;
itable indexTable[INDEX_SIZE];

void quick(int* arr, int st, int end) {
	int left = st, right = end, pivot = arr[(st + end) / 2];
	while (left <= right) {
		while (arr[left] < pivot)  left++;
		while (pivot < arr[right])  right--;
		if (left <= right) {
			int temp = arr[left]; arr[left] = arr[right]; arr[right] = temp;
			left++, right--;
		}
	}
	if (st < right) quick(arr, st, right);
	if (left < end)  quick(arr, left, end);
}
void display(int* arr, int size) {
	for (int i = 0; i < size; i++) printf("%3d ", arr[i]);
	printf("\n");
}
int linear_search(int* arr, int key, int low, int high) {
	for (int i = low; i <= high; i++) {
		if (arr[i] == key) return i;
	}
	return -1;
}

void makeIndexTable(int MainTable[], int size) {
	int gap = size / INDEX_SIZE;
	for (int i = 0; i < INDEX_SIZE; i++) {
		indexTable[i].index = i * gap;
		indexTable[i].key = MainTable[i * gap];
	}
}
int indexSearch(int MainTable[], int key, int low, int high) {
	int begin = low, end = high;
	if (key < MainTable[begin] || key > MainTable[end]) return -1;
	for (int i = 1; i < INDEX_SIZE; i++) {
		if (indexTable[i - 1].key <= key && indexTable[i].key > key) {
			begin = indexTable[i - 1].index;
			end = indexTable[i].index;
			break;
		}
		else {
			begin = indexTable[i].index;
			end = high;
		}
	}
	return linear_search(MainTable, key, begin, end);
}
int main() {
	srand(time(NULL));
	int n = 20;
	int range = 20;
	int key;
	int* a = (int*)calloc(n, sizeof(int));
	printf("\n\t<< 색인 순차 검색 >>\n");
	for (int i = 0; i < n; i++) a[i] = rand() % range;
	quick(a, 0, n - 1);
	display(a, n);

	makeIndexTable(a, n);
	while (1)
	{
		printf("Select a number to find(0~20): ");
		scanf_s("%d", &key);
		printf("%d\n", indexSearch(a, key, 0, n-1));
	}
	return 0;
}