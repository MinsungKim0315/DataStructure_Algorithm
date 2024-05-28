#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) {type t = x; x = y; y = t;}
void radomize(int* arr, int size, int st, int end) {
    if (st > end) swap(int, st, end);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) arr[i] = rand() % (end - st + 1) + st;
}
void display(int* arr, int size) {
    for (int i = 0; i < size; i++) printf("%7d ", arr[i]);
    printf("\n");
}
void display_sort(int* arr, int st, int end) {
    for (int i = 0; i < st; i++) printf("        ");
    for (int i = st; i <= end; i++) printf("%7d ", arr[i]);
    printf("\n");
}
void quick(int* arr, int st, int end) {
    int left = st, right = end, pivot = arr[(st + end) / 2];
    while (left <= right) {
        while (arr[left] < pivot)  left++;
        while (pivot < arr[right])  right--;
        if (left <= right) {
            swap(int, arr[left], arr[right]);
            left++;
            right--;
        }
    }
    display_sort(arr, st, end);
    if (st < right) quick(arr, st, right);
    if (left < end)  quick(arr, left, end);
}
int main() {
    int size, st, end;
    int* arr;
    printf("배열의 크기 입력 : ");
    scanf_s("%d", &size);
    arr = (int*)calloc(size, sizeof(int));
    printf("시작 수 / 끝 수 입력 : ");
    scanf_s("%d %d", &st, &end);
    radomize(arr, size, st, end);
    printf("\n\n정렬 전 자료 출력 ***\n\n");
    display(arr, size);
    quick(arr, 0, size - 1);
    printf("\n\n정렬 후 자료 출력 ***\n\n");
    display(arr, size);
    free(arr);
    return 0;
}
