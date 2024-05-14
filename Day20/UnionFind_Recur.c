#include <stdio.h>
#include <stdlib.h>
int* UnionFindInitialize(int count) { // 배열 초기화
  int* arr = (int*)malloc(count * sizeof(int));
  for (int i = 0; i < count; i++) arr[i] = i;
  return arr;
}
int getParent(int* parent, int index) { //부모 노드 확인
  if (parent[index] == index)  return index;
  return getParent(parent, parent[index]);
}
int findParent(int* parent, int x, int y) { //같은 부모 노드 비교 확인
  x = getParent(parent, x);
  y = getParent(parent, y);
  return (x == y);
}
void unionParent(int* parent, int x, int y) {//부모 노드 합치기
  x = getParent(parent, x);
  y = getParent(parent, y);
  if (x < y) parent[y] = x;
  else parent[x] = y;
}
void display(int* arr, int num) {
  for (int i = 0; i < num; i++) printf("%d ", arr[i]);
  printf("\n");
}
int main() {
  int* group = UnionFindInitialize(10); // Union Find 초기화
  display(group, 10);
  unionParent(group, 0, 1);
  display(group, 10);
  unionParent(group, 0, 2);
  unionParent(group, 0, 3);
  unionParent(group, 4, 5);
  unionParent(group, 4, 6);
  unionParent(group, 4, 7);
  display(group, 10);
  if (findParent(group, 2, 6)) printf("2와 6은 연결 OK\n");
  else printf("2와 6은 fail\n");
  unionParent(group, 3, 6);
  display(group, 10);
  if (findParent(group, 0, 4)) printf("0과 4는 연결 OK\n");
  else printf("0와 4은 fail\n");
  if (findParent(group, 1, 5)) printf("1과 5는 연결 OK\n");
  else printf("1와 5은 fail\n");
  if (findParent(group, 2, 6)) printf("2과 6는 연결 OK\n");
  else printf("2와 6은 fail\n");
  if (findParent(group, 3, 7)) printf("3과 7는 연결 OK\n");
  else printf("3와 7은 fail\n");
  return 0;
}
