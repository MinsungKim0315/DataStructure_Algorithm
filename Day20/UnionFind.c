#include <stdio.h>
#include <stdlib.h>
int* UnionFindInitialize(int count) { // 배열 초기화
  int* arr = (int*)malloc(count * sizeof(int));
  for (int i = 0; i < count; i++) arr[i] = i;
  return arr;
}
void unionParent(int* parent, int count, int x, int y) { // 집합 합치기
  int posX = parent[x], posY = parent[y];
  int big = (posX > posY) ? posX : posY;
  int small = (posX < posY) ? posX : posY;
  for (int i = 0; i < count; i++)
    if (parent[i] == big)
      parent[i] = small;
}
int findParent(int* parent, int x, int y) { // 같은 집합인지 확인
  return parent[x] == parent[y];
}
void display(int* arr, int num) {
  printf(" 합집합 구성 : ");
  for (int i = 0; i < num; i++) printf("%d ", arr[i]);
  printf("\n");
}
int main() {
  int* group = UnionFindInitialize(10); // Union Find 초기화
  display(group, 10);
  unionParent(group, 10, 0, 1);
  display(group, 10);
  unionParent(group, 10, 0, 2);
  unionParent(group, 10, 0, 3);
  unionParent(group, 10, 4, 5);
  unionParent(group, 10, 4, 6);
  unionParent(group, 10, 4, 7);
  display(group, 10);
  if (findParent(group, 2, 6)) printf("2와 6은 연결 OK\n");
  else printf("2와 6은 fail\n");
  unionParent(group, 10, 3, 7);
  display(group, 10);
  if (findParent(group, 2, 6)) printf("2와 6은 연결 OK\n");
  else printf("2와 6은 fail\n");
  return 0;
}
