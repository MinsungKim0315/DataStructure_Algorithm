#include <stdio.h>
#include <stdlib.h>
///// Linked List Graph /////
typedef struct node {
  int dst;      //도착지
  struct node* next;  //다음 노드의 주소 저장
}node;
typedef struct graph {//간선을 저장하기 위한 그래프
  int count;  //정점의 개수
  node* arr;  //정점의 개수만큼 할당 된 node(출발지)
}graph;
graph* graphInitialize(int count);
void addDirectedEdge(graph* grp, int src, int dst);
void addUnDirectedEdge(graph* grp, int src, int dst);
void graphDisplay(graph* grp);
void memoryFree(graph* grp);
///// Stack /////
typedef struct stack {
  int top;    //저장하려는 위치
  int* arr;    //동적할당된 스택의 주소를 저장
  int capacity;  //스택의 최대 용량
}stack;
stack* stackInitialize(int count);
void push(stack* stk, int val);
int pop(stack* stk);
int isEmpty(stack* stk);
///// DFS : Depth First Search /////
void DFS(graph* grp, int source); // Recursion ver.
void DFSReculsive(graph* grp, int index, int* visited);  // Recursion ver.
void DFS_stack(graph* grp, int source); // Stack ver.
int main() {
  graph* grp = graphInitialize(9);
  addUnDirectedEdge(grp, 0, 1);
  addUnDirectedEdge(grp, 1, 2);
  addUnDirectedEdge(grp, 1, 4);
  addUnDirectedEdge(grp, 2, 5);
  addUnDirectedEdge(grp, 3, 4);
  addUnDirectedEdge(grp, 3, 6);
  addUnDirectedEdge(grp, 4, 5);
  addUnDirectedEdge(grp, 4, 7);
  addUnDirectedEdge(grp, 5, 8);
  addUnDirectedEdge(grp, 6, 7);
  graphDisplay(grp);
  DFS(grp, 0); //깊이(재귀호출) 우선 탐색
  printf("\n");
  DFS_stack(grp, 0); //깊이(스택) 우선 탐색
  memoryFree(grp);
}
///// Linked List Graph /////
graph* graphInitialize(int count) { // 그래프 구성 멤버 초기화
  graph* grp = (graph*)malloc(sizeof(graph));
  grp->count = count; // 정점 갯수 초기화
  grp->arr = (node*)calloc(count, sizeof(node)); // node arr[count]; 정점 개수 동적 할당
  return grp;
}
void addDirectedEdge(graph* grp, int src, int dst) { // 방향 간선 추가
  node* newNode = (node*)malloc(sizeof(node));
  newNode->dst = dst;
  newNode->next = grp->arr[src].next;
  grp->arr[src].next = newNode;
}
void addUnDirectedEdge(graph* grp, int src, int dst) { // 무방향 간선 추가
  addDirectedEdge(grp, src, dst);
  addDirectedEdge(grp, dst, src);
}
void graphDisplay(graph* grp) { // 출발 정점 -> 간선 연결 표 출력
  if (grp == NULL) return;
  for (int i = 0; i < grp->count; i++) { //정점의 개수만큼 반복
    printf("출발지 노드 : %d ==> ", i); // 출발지 정점 출력
    for (node* cur = grp->arr[i].next; cur; cur = cur->next)
      printf("%d ", cur->dst); // 인접 정점 출력
    printf("\n");
  }
}
void memoryFree(graph* grp) {
  for (int i = 0; i < grp->count; i++) {
    while (grp->arr[i].next) { // 인접 정점(노드) 삭제
      node* delNode = grp->arr[i].next;
      grp->arr[i].next = delNode->next; // 다음 노드 주소로 변경
      free(delNode);
    }
  }
  free(grp->arr); // 출발지 노드 삭제
  free(grp);
}
///// Stack /////
stack* stackInitialize(int count) { // stack 초기화 : 구성 멤버 초기화
  stack* stk = (stack*)malloc(sizeof(stack));
  stk->arr = (int*)calloc(count, sizeof(int));// int arr[count]; 스택 배열 공간 동적 할당
  stk->top = 0; // 보유 개수 0으로 초기화
  stk->capacity = count; // 총 용량 count 개 설정
  return stk;
}
void push(stack* stk, int val) {
  if (stk->top >= stk->capacity) { // 스택 용량 초과시 경고
    printf("\n\n\t\tstack overflow\n");
    return;
  }
  stk->arr[stk->top++] = val; // 스택 arr 배열에 목적지(dst) 삽입 후 top++
}
int pop(stack* stk) {
  if (stk->top <= 0) { // 공백 에러
    printf("\n\n\t\tstack underflow\n");
    return 0;
  }
  return stk->arr[--(stk->top)]; // dst를 arr배열에서 삭제 (pop)
}
int isEmpty(stack* stk) { // 스택 자료 개수 확인
  return stk->top == 0;
}
///// DFS : Depth First Search /////
void DFS(graph* grp, int source) { // 매개변수 : 그래프, 출발지
  int* visited = (int*)calloc(grp->count, sizeof(int)); //int visited[count]; boolean visited array 정점 방문 배열
  printf("%d ", source); //출발지 정점 출력 "0"
  DFSReculsive(grp, source, visited); //DFS재귀호출 (그래프, 출발지, 방문지)
  free(visited);
}
void DFSReculsive(graph* grp, int index, int* visited) {// 매개변수 : 그래프, 출발지, 방문지
  visited[index] = 1; // 방문지 체크
  for (node* curNode = grp->arr[index].next; curNode; curNode = curNode->next) { // 정점에 연결된 인접 정점 반복
    int destination = curNode->dst; // 인접 정점 확인
    if (visited[destination] == 0) { // 방문한 적이 없으면
      printf("%d ", destination); // 인접 정점 출력
      DFSReculsive(grp, destination, visited); // 인접 정점에서 다음 인접 정점으로 재귀 함수
    }
  }
}
void DFS_stack(graph* grp, int source) { // 매개변수 : 그래프, 출발지
  int* visited = (int*)calloc(grp->count, sizeof(int)); //int visited[count]; boolean visited array 정점 방문 배열
  stack* stk = stackInitialize(grp->count); // stack 초기화 총 용량 9개
  push(stk, source); //출발지 정점 스택에 삽입
  visited[source] = 1; // 방문지 체크
  while (!isEmpty(stk)) { // 스택의 정점을 모두 Pop 할 때까지 반복
    int traversal = pop(stk); // 방문한 정점 Pop
    printf("%d ", traversal); // 방문한 정점 출력
    for (node* curNode = grp->arr[traversal].next; curNode; curNode = curNode->next) { // 인접 정점 주소가 있을 때
      int dst = curNode->dst; // 인접 정점 목적지
      if (visited[dst] == 0) { // 방문한 적이 없으면
        push(stk, dst); // 스택에 넣기
        visited[dst] = 1; // 방문지 체크
      }
    }
  }
  printf("\n");
  free(visited);
  free(stk->arr);
  free(stk);
}
