#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) {type t = x; x = y; y = t;}

void display(int* arr, int size) {
  for (int i = 0; i < size; i++) printf("%7d ", arr[i]);
  printf("\n");
}
void display_sort(int* arr, int st, int end) {
  for (int i = 0; i < st; i++) printf("        ");
  for (int i = st; i <= end; i++) printf("%7d ", arr[i]);
  printf("\n");
}
void randomize(int* arr, int st, int end, int size) {
  if (st > end) swap(int, st, end);
  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; i++) arr[i] = rand() % (end - st + 1) + st;
}
void merge(int* arr, int* temp, int st, int mid, int end) {
  for (int i = st; i <= end; i++)  temp[i] = arr[i];
  int Left = st, Right = mid + 1, Sort = st;
  while (Left <= mid && Right <= end) {
    if (temp[Left] < temp[Right]) arr[Sort++] = temp[Left++];
    else arr[Sort++] = temp[Right++];
  }
  while (Left <= mid) arr[Sort++] = temp[Left++];
  while (Right <= end) arr[Sort++] = temp[Right++];
}
void divide(int* arr, int* temp, int st, int end) {
  if (st < end) {
    int mid = (st + end) / 2;
    divide(arr, temp, st, mid);
    divide(arr, temp, mid + 1, end);
    merge(arr, temp, st, mid, end);
    display_sort(arr, st, end);
  }
}
void mergeSort(int* arr, int size) {
  int* temp = (int*)malloc(sizeof(int) * size);
  divide(arr, temp, 0, size - 1);
  free(temp);
}
int main() {
  int size, st, end;
  int* arr;
  printf("배열의 크기 입력 : ");
  scanf_s("%d", &size);
  arr = (int*)malloc(sizeof(int) * size);
  printf("시작 수 / 끝 수 입력 : ");
  scanf_s("%d %d", &st, &end);
  randomize(arr, st, end, size);
  printf("\n\n **** 정렬 전 자료 출력 ***\n\n");
  display(arr, size);
  mergeSort(arr, size);
  printf("\n\n **** 정렬 후 자료 출력 ***\n\n");
  display(arr, size);
  free(arr);
  return 0;
}
