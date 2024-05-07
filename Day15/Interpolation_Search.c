#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

int interpolation_search(int* arr, int key, int low, int high) {
	if (key < arr[low] || key>arr[high]) return -1;
	int pos = ((double)(high - low) * (key - arr[low])) / (arr[high] - arr[low]) + low;
	if (key == arr[pos]) return pos;
	else if (key < arr[pos]) return interpolation_search(arr, key, low, pos - 1);
	else return interpolation_search(arr, key, pos + 1, high);
}

int main() {
	srand(time(NULL));
	int n = 20;
	int range = 20;
	int key;
	int* a = (int*)calloc(n, sizeof(int));
	printf("\n\t<< 보간 검색 >>\n");
	for (int i = 0; i < n; i++) a[i] = rand() % range;
	quick(a, 0, n - 1);
	display(a, n);
	printf("Select a number to find(0~20): ");
	scanf_s("%d", &key);
	printf("%d", interpolation_search(a, key, 0, n-1));
	return 0;
}