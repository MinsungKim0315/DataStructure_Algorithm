#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int seq_search(int* arr, int low, int high, int key) {
	for (int i = low; i <= high; i++) if (arr[i] == key) return i;
	return -1;
}
#define INDEX_SIZE 5
typedef struct itable {
	int index;
	int key;
}itable;
itable indexTable[INDEX_SIZE];
void makeIndexTable(int MainTable[], int size) {
	int gap = size / INDEX_SIZE;
	for (int i = 0; i < INDEX_SIZE; i++) {
		indexTable[i].index = i * gap;
		indexTable[i].key = MainTable[i * gap];
	}
}
int indexSearch(int MainTable[], int low, int high, int key) {
	int begin = low, end = high;
	if (key < MainTable[begin] || key > MainTable[end]) return -1;
	for (int i = 1; i < INDEX_SIZE; i++) {
		if ((indexTable[i - 1].key <= key) && (indexTable[i].key > key)) {	//find the range between two index points 
			begin = indexTable[i - 1].index;
			end = indexTable[i].index;
			break;
		}
		else {
			begin = indexTable[i].index;
			end = high;
		}
	}
	return seq_search(MainTable, begin, end, key);
}
void display(int* arr, int size) {
	for (int i = 0; i < size; i++) printf("%3d ", arr[i]);
	printf("\n");
}
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
int main() {
	srand(time(NULL));
	int n = 20;
	int range = 20;
	int* a = (int*)calloc(n, sizeof(int));
	printf("\n\t<< 색인 순차 검색 >>\n");
	for (int i = 0; i < n; i++) a[i] = rand() % range;
	quick(a, 0, n - 1);
	display(a, n);
	makeIndexTable(a, n);
	for (int i = 0; i < range; i++)
		printf(" %3d 의 위치는 a[%3d] 칸 \n", i, indexSearch(a, 0, n - 1, i));
	return 0;
}
