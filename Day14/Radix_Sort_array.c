#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <time.h>
#define swap(type, x, y) {type t = x; x = y; y = t;}
void display(int* arr, int size) {
  for (int i = 0; i < size; i++) printf("%7d ", arr[i]);
  printf("\n");
}
void randomize(int* arr, int size, int st, int end) {
  if (st > end) swap(int, st, end);
  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; i++) arr[i] = rand() % (end - st + 1) + st;
}
void bucket(int* arr, int size, int radix) {
  //정렬할 최대 값의 자리수, 반복횟수 찾기
  int digit = 0; // 반복횟수
  for (int i = 0; i < size; i++)
    while (arr[i] / (int)pow(radix, digit))
      digit++;
  // 자리수 분할한 값을 저장할 임시 배열
  int* temp = (int*)malloc(size * sizeof(int));
  if (temp == NULL) exit(1);
  // 자리수 분할한 값의 수량 파악 == 임시 배열에 저장할 위치 파악
  int* counts = (int*)malloc(radix * sizeof(int));
  if (counts == NULL) exit(1);
  // 자리수 만큼 반복
  for (int repeat = 0; repeat < digit; repeat++) {
    // counts 배열 비우기
    for (int i = 0; i < radix; i++)
      counts[i] = 0;
    // 정렬 할 값의 자리수 분할 & 수량 파악
    for (int i = 0; i < size; i++)
      counts[(arr[i] / (int)pow(radix, repeat)) % radix]++;
    // 수량 파악으로 임시 배열에 저장할 인덱스 계산
    for (int i = 1; i < radix; i++)
      counts[i] += counts[i - 1];
    // 임시 배열의 앞부터 값 저장
    for (int i = size - 1; i >= 0; i--)
      temp[--counts[(arr[i] / (int)pow(radix, repeat)) % radix]] = arr[i];
    // 자리수 별 값 저장
    for (int i = 0; i < size; i++) arr[i] = temp[i];
    display(arr, size);
  }
  free(temp);
  free(counts);
}
int main() {
  int size, st, end;
  int* arr;
  printf("배열 크기 입력 : ");
  scanf_s("%d", &size);
  arr = (int*)calloc(size, sizeof(int));
  printf("시작 수 / 끝 수 입력 : ");
  scanf_s("%d %d", &st, &end);
  randomize(arr, size, st, end);
  printf("\n\n*** 정렬 전 자료 출력 ***\n");
  display(arr, size);
  bucket(arr, size, 10);
  printf("\n\n*** 정렬 후 자료 출력 ***\n");
  display(arr, size);
  free(arr);
  return 0;
}
