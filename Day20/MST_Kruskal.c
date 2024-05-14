#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_VERTEX 10 // 그래프 정점의 수

typedef struct EDGE {  // 간선과 연결된 정점 데이터와 가중치를 저장하기 위한 구조체
  int v1; // 정점 1
  int v2; // 정점 2
  int key;// 정점 1과 정점 2의 가중치
}Edge;

typedef struct HEAP {  //가장 적은 가중치을 가진 간선부터 차례로 그래프 포함하기 위해서 사용
  int n;
  Edge* heap[MAX_VERTEX * MAX_VERTEX];
}Heap;

int* UnionFindInitialize(int count);
int getParent(int* parent, int index);
int findParent(int* parent, int x, int y);
void unionParent(int* parent, int x, int y);

void Init_Graph(Heap* h, int n);//--------------간선과 가중치를 랜덤으로 생성, 최소 힙에 저장 (n:가중치의 최대값)
void Insert_Edge(int v1, int v2, int key, Heap* h); //생성된 간선을 힙에 저장

Heap* Init_Heap(void);//----------------------최소 힙 트리를 구성하기 위한 구조체를 초기화
void Input_Heap(Edge* e, Heap* h);//-----------랜덤으로 생성된 간선을 최소 힙 트리에 저장하고 정렬
Edge* Delete_Heap(Heap* h);//-----------------트리에서 가장 작은 가중치를 가진 간선 주소를 반환한다.
void Print_Heap(Heap* h);    // 최소 힙 확인하기 위한 함수

void Start_Kruskal(Heap* h);//----------------가중치가 최소이고 현재 그래프의 정점들과 사이클을 이루지 않는 정점부터 그래프를 구성
int Link_Vertex_gm(int s1, int s2, int key, int* parent); //---------------------------------s1, s2의 합집합 여부를 검사한 뒤 그래프에 추가

int main() {
  Heap* h = Init_Heap();
  Init_Graph(h, 300);
  Print_Heap(h);
  Start_Kruskal(h);
  return 0;
}

/////////////////////union_find//////////////////////
int* UnionFindInitialize(int count) { // 집합 초기화
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
/////////////////////graph//////////////////////
void Init_Graph(Heap* h, int n) {//-------------간선과 가중치를 랜덤으로 생성, 최소 힙에 저장 (n:가중치의 최대값)
  srand((unsigned int)time(NULL));
  int ran_num;
  for (int i = 0; i < MAX_VERTEX; i++) { // 출발지
    for (int j = 0; j < MAX_VERTEX; j++) { // 도착지
      ran_num = (rand() % n) + 1; // 출발지 -> 도착지 까지 가중치
      printf("n = %3d  ", h->n + 1); // 간선 번호(수량)
      printf("  Random number: %d\n", ran_num);
      Insert_Edge(i, j, ran_num, h); //    만들어진 간선을 구조체 Edge로 묶어준다.
    }
  }
}
/////////////////////Edge 생성//////////////////////
void Insert_Edge(int v1, int v2, int key, Heap* h) {//생성된 변수와 간선을 구조체로 묶고, 최소 힙 추가
  Edge* e = (Edge*)malloc(sizeof(Edge));
  e->v1 = v1;
  e->v2 = v2;
  e->key = key;
  Input_Heap(e, h);
}
/////////////////////Heap//////////////////////
Heap* Init_Heap(void) {
  Heap* h = (Heap*)malloc(sizeof(Heap));
  h->n = 0;  //    힙 트리 내에 저장된 데이터의 갯수를 초기화해준다.
  return h;
}
void Input_Heap(Edge* e, Heap* h) { // 최소 힙 추가
  int i = ++(h->n); // 마지막 힙 번호 & 힙의 원소 수
  while (i != 1 && e->key < h->heap[i / 2]->key) {// 부모노드와 비교 후 교환
    h->heap[i] = h->heap[i / 2];
    i /= 2;
  }
  h->heap[i] = e;
}
Edge* Delete_Heap(Heap* h) { //힙의 정점에 있는 최소 가중치 간선 정보를 반환
  Edge* re = h->heap[1]; // 가중치 가장 낮은 root 간선
  Edge* tmp = h->heap[(h->n)--]; // 마지막 힙 원소 저장 & 원소 수 1 감소
  int pr = 1, ch = 2;
  while (ch <= h->n) { // shift down 반복문
    if (ch + 1 <= h->n && h->heap[ch]->key > h->heap[ch + 1]->key) ch++; // 자식 노드 왼쪽 & 오른쪽 비교
    if (tmp->key <= h->heap[ch]->key) break; // 부모 노드와 자식 노드 중 작은값 비교
    h->heap[pr] = h->heap[ch]; //부모 & 자식 교환
    pr = ch; // 자식 - > 부모 인덱스로 변경
    ch *= 2; // 자식 - > 더 아래 자식 인덱스로 변경
  }
  h->heap[pr] = tmp; // 마지막 노드 최종 위치 삽입
  return re; // 루트 노드 반환
}
void Print_Heap(Heap* h) { // 완전 이진 트리 레벨에 따라 출력 pow(2, n)
  if (h->n != 0) {
    printf("\n");
    int n = 1;
    for (int i = 1; i <= h->n; i++) {
      printf("%3d   ", h->heap[i]->key);
      if (i == (int)pow(2, n) - 1) {
        printf("\n");
        n++;
      }
    }
    printf("\n\n");
  }
}
/////////////////////최소 신장 트리(MST, Minimum Spanning Tree)//////////////////////
void Start_Kruskal(Heap* h) {
  int end = 0; // 채택한 간선의 수
  int n = h->n;
  int* group = UnionFindInitialize(MAX_VERTEX);
  for (int i = 0; i < n; i++) {
    Edge* tmp = Delete_Heap(h); // 최소 가중치 간선 추출 (최소 힙 루트 노드)
    end += Link_Vertex_gm(tmp->v1, tmp->v2, tmp->key, group);
    if (end == MAX_VERTEX - 1) break; // 노드의 수 - 1 == 간선의 수
  }
}
int Link_Vertex_gm(int s1, int s2, int key, int* parent) {//s1, s2의 합집합 여부를 검사한 뒤 그래프에 추가
  if (!findParent(parent, s1, s2)) {//두 노드의 부모노드가 같이 않음 == 합집합이 아님 == 사이클을 형성하지 않음
    unionParent(parent, s1, s2);
    printf("Success Link(key=%d): [%d] and [%d]\n\n", key, s1, s2);
    return 1;
  }
  else { // s1, s2 사이클을 형성
    printf("Fail Link(key=%d): [%d] and [%d]\n\n", key, s1, s2); return 0;
  }
}
