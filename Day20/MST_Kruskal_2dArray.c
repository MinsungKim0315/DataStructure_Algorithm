// 연결 리스트 그래프, Kruskal MST
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
///// Weighted Graph /////
typedef struct node {
  int vertex;        //정점
  int weight;        //가중치
  struct node* next; //다음 노드의 주소
}node;
typedef struct graph {
  int vertexCount;   //정점의 개수
  node* head;        //출발지 노드 배열 동적 할당
}graph;
graph* graphInitialize(int count);
void addDirectedEdge(graph* pGraph, int src, int dst, int weight);
void addUnDirectedEdge(graph* pGraph, int src, int dst, int weight);
void display(graph* pGraph);
void memoryFree(graph* pGraph);
///// Union & Find /////
int* UnionFindInitialize(int count);
int getParent(int* parent, int index);
int findParent(int* parent, int x, int y);
void unionParent(int* parent, int x, int y);
///// Heap /////
typedef struct EDGE {  // 간선으로 연결된 정점 데이터와 가중치를 저장하기 위한 구조체
  int v1; // 정점 1
  int v2; // 정점 2
  int key;// 정점 1과 정점 2의 가중치
}Edge;
typedef Edge* element;
typedef struct Heap {
  int capacity;    // 저장 가능한 원소의 최대 수량
  int size;        // 저장 할 칸 번호, size - 1 : 저장한 원소 개수
  element* ary;    // 원소를 저장하는 배열
}Heap;
Heap* heapInitialize();
void heapAdd(Heap* heap, element value);
element heapRemove(Heap* heap);
void heapSort(element* arr, int size);
void heapFree(Heap** heap);
void printHeap(Heap* heap);
///// Kruskal MST , Minimum Spanning Tree /////
graph* LinkedListGraphKruskalMST(graph* pGraph) { // Minimum Spanning Tree
  //간선 Heap 저장
  Heap* h = heapInitialize();
  for (int i = 0; i < pGraph->vertexCount; i++) {
    for (node* pNode = pGraph->head[i].next; pNode != NULL; pNode = pNode->next) {
      Edge* e = (Edge*)malloc(sizeof(Edge));
      e->v1 = pGraph->head[i].vertex;
      e->v2 = pNode->vertex;
      e->key = pNode->weight;
      heapAdd(h, e);
    }
  }
  printHeap(h);
  graph* kruskal = graphInitialize(pGraph->vertexCount);
  int* group = UnionFindInitialize(pGraph->vertexCount);
  for (int end = 0; end < pGraph->vertexCount - 1 && h->size > 1;) {
    Edge* e = heapRemove(h);
    if (findParent(group, e->v1, e->v2) != 1) {
      unionParent(group, e->v1, e->v2);
      printf("Success Link(key=%3d): [%3d] and [%3d]\n\n", e->key, e->v1, e->v2);
      addDirectedEdge(kruskal, e->v1, e->v2, e->key);
      end++;
    }
    else printf("   Fail Link(key=%3d): [%3d] and [%3d]\n\n", e->key, e->v1, e->v2);
    free(e);
  }
  heapFree(&h);
  free(group);
  return kruskal;
}
int main() {
  int vertex = 10;
  graph* grp = graphInitialize(vertex); //그래프, 정점의 개수
  for (int i = 0; i < vertex; i++)
    for (int j = 0; j < vertex; j++)
      addDirectedEdge(grp, i, j, rand() % 80 + 1);
  display(grp);

  graph* kruskalMST = LinkedListGraphKruskalMST(grp);
  display(kruskalMST);
  memoryFree(grp);
  memoryFree(kruskalMST);
  return 0;
}
///// Weighted Graph /////
graph* graphInitialize(int count) {
  graph* pGraph = (graph*)malloc(sizeof(graph));
  pGraph->vertexCount = count;
  pGraph->head = (node*)calloc(count, sizeof(node));
  for (int i = 0; i < count; i++) {
    pGraph->head[i].vertex = i;
    pGraph->head[i].next = NULL;
  }
  return pGraph;
}
void addDirectedEdge(graph* pGraph, int src, int dst, int weight) {//방향 그래프(단방향)
  node* newNode = (node*)malloc(sizeof(node));
  newNode->vertex = dst;
  newNode->weight = weight;
  newNode->next = pGraph->head[src].next;//맨 앞 추가
  pGraph->head[src].next = newNode;
}
void addUnDirectedEdge(graph* pGraph, int src, int dst, int weight) {//무방향 그래프(양방향) 
  addDirectedEdge(pGraph, src, dst, weight);
  addDirectedEdge(pGraph, dst, src, weight);
}
void display(graph* pGraph) {
  for (int i = 0; i < pGraph->vertexCount; i++) {
    printf("출발지[ %3d ] : ", pGraph->head[i].vertex);
    for (node* curNode = pGraph->head[i].next; curNode != NULL; curNode = curNode->next)
      printf("[ V : %3d , W : %3d ] ->", curNode->vertex, curNode->weight);
    printf("\n");
  }
}
void memoryFree(graph* pGraph) {
  for (int i = 0; i < pGraph->vertexCount; i++) {
    while (pGraph->head[i].next != NULL) {
      node* delNode = pGraph->head[i].next; // delNode변경
      pGraph->head[i].next = delNode->next; // 삭제 노드 제외하고 다음 연결
      printf("출발지[ %3d ]--- weight[ %3d ]--- 도착지[ %3d ] 제거\n", i, delNode->weight, delNode->vertex);
      free(delNode); // 노드 제거
    }
  }
  free(pGraph->head);
  free(pGraph);
}
///// Union & Find /////
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
///// Heap /////
Heap* heapInitialize() {//heap 초기화
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  heap->capacity = 2;  // capacity 멤버 초기화
  heap->size = 1;      // size 멤버 초기화
  heap->ary = (element*)calloc(heap->capacity, sizeof(element)); // ary 멤버 동적 할당
  return heap;
}
void heapAdd(Heap* heap, element value) {
  if (heap->size == heap->capacity) {
    heap->capacity = heap->capacity * 2;
    element* oldarray = heap->ary;
    heap->ary = (element*)realloc(heap->ary, heap->capacity * sizeof(element));
    if (heap->ary == NULL) { free(oldarray); exit(1); }
  }
  int input = heap->size++;
  while (input != 1 && value->key < heap->ary[input / 2]->key) {// 부모노드와 비교 후 교환
    heap->ary[input] = heap->ary[input / 2];
    input = input / 2;
  }
  heap->ary[input] = value;
}
element heapRemove(Heap* heap) {
  if (heap->size <= 1) return 0;
  element root = heap->ary[1];
  element insert = heap->ary[--heap->size]; // 마지막 힙 원소 저장 & 원소 수 1 감소
  int parent = 1, child = 2;
  while (child < heap->size) { // shift down 반복문
    if (child + 1 < heap->size && heap->ary[child]->key > heap->ary[child + 1]->key) child++; // 자식 왼쪽 & 오른쪽 비교
    if (insert->key <= heap->ary[child]->key) break; // 부모와 자식 노드 비교
    heap->ary[parent] = heap->ary[child]; //자식을 부모에 대입
    parent = child; // 기준 노드 변경 [ 부모 -> 자식 ]
    child = child * 2; // 기준 노드 변경 [ 자식 -> 손주 ]
  }
  heap->ary[parent] = insert; // 마지막 노드 최종 위치 삽입
  return root; // 루트 노드 반환
}
void heapSort(element* arr, int size) {
  Heap* heap = heapInitialize();
  for (int i = 0; i < size; i++)
    heapAdd(heap, arr[i]);
  for (int i = 0; i < size; i++)
    arr[i] = heapRemove(heap);
  heapFree(&heap);
}
void heapFree(Heap** heap) {
  for (int i = 0; i < (*heap)->size; i++) free((*heap)->ary[i]);
  free((*heap)->ary);//동적 할당 해제
  free(*heap);
  *heap = NULL; // prevent Dangling Pointer
  printf("Heap 할당 해제\n");
}
void printHeap(Heap* heap) { // 완전 이진 트리 레벨에 따라 출력 pow(2, level)
  if (heap->size <= 1) return;
  printf("\n");
  for (int i = 1, level = 1; i < heap->size; i++) {
    printf("%3d", heap->ary[i]->key);
    if (i == (int)pow(2, level) - 1) {
      printf("\n");
      level++;
    }
  }
  printf("\n\n");
}
