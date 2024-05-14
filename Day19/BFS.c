#include <stdio.h>
#include <stdlib.h>
///// Linked List Graph /////
typedef struct node {
  int dst;      //도착지
  struct node* next;  //다음 노드의 주소 저장
} node;
typedef struct graph {//간선을 저장하기 위한 그래프
  int count;  //정점의 개수
  node* arr;  //정점의 개수만큼 할당 된 node(출발지)
} graph;
graph* graphInitialize(int count);
void addDirectedEdge(graph* grp, int src, int dst);
void addUnDirectedEdge(graph* grp, int src, int dst);
void graphDisplay(graph* grp);
void memoryFree(graph* grp);

///// Circular Queue /////
typedef struct queue {
  int front;    // 데이터를 꺼내는 쪽
  int rear;     // 데이터를 넣는 쪽
  int* arr;     // 동적할당 된 메모리의 주소 저장
  int count;    // 요소 개수
  int capacity; // 큐의 최대 용량
} queue;
queue* queueInitialize(int size);
int isEmpty(queue* que);
int enqueue(queue* que, int value);
int dequeue(queue* que);

///// BFS : Breadth First Search /////
void BFS_queue(graph* grp, int source);
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
  BFS_queue(grp, 0); //너비(큐) 우선 탐색
  memoryFree(grp);
  return 0;
}
///// Linked List Graph /////
graph* graphInitialize(int count) {
  graph* grp = (graph*)malloc(sizeof(graph));
  grp->count = count;
  grp->arr = (node*)calloc(count, sizeof(node));
  return grp;
}
void addDirectedEdge(graph* grp, int src, int dst) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->dst = dst;
  newNode->next = grp->arr[src].next;
  grp->arr[src].next = newNode;
}
void addUnDirectedEdge(graph* grp, int src, int dst) {
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
///// Circular Queue /////
queue* queueInitialize(int size) {// 매개변수 : 큐, 원소 수 // 구성 요소 초기화
  queue* que = (queue*)malloc(sizeof(queue));
  que->count = que->front = que->rear = 0;
  que->arr = (int*)calloc(size, sizeof(int));
  que->capacity = size;
  return que;
}
int isEmpty(queue* que) {
  return que->count == 0;
}
int enqueue(queue* que, int value) { // 큐 후단에 데이터 삽입
  if (que->count >= que->capacity) return 0; //queue overflow
  que->arr[que->rear] = value;
  ++(que->rear);   //rear
  ++(que->count); //요소의 개수 증가
  if (que->rear == que->capacity)  que->rear = 0; // 원형 큐
  return 1; //enqueue 성공 시
}
int dequeue(queue* que) {
  if (que->count <= 0) return 0; //queue underflow
  --(que->count); //요소의 개수 감수
  int delVal = que->arr[que->front++]; //삭제
  if (que->front == que->capacity) que->front = 0; // 원형 큐
  return delVal; //dequeue에 성공 시
}
///// BFS : Breadth First Search /////
void BFS_queue(graph* grp, int source) { // 매개변수 : 그래프, 출발지
  int* visited = (int*)calloc(grp->count, sizeof(int)); //int visited[count];
  queue* que = queueInitialize(grp->count); // 큐 초기화
  enqueue(que, source); // 출발지 삽입 - > 탐색 시작
  visited[source] = 1; // 방문지 체크
  while (!isEmpty(que)) { // 큐의 정점을 모두 Pop 할 때까지 반복
    int traversal = dequeue(que);  // 방문한 정점
    printf("%d ", traversal); // 방문한 정점 출력
    for (node* curNode = grp->arr[traversal].next; curNode; curNode = curNode->next) { // 인접 정점 주소가 있을 때
      int dst = curNode->dst;
      if (visited[dst] == 0) { // 방문한 적이 없으면
        enqueue(que, dst); // 큐에 넣기
        visited[dst] = 1; // 방문지 체크
      }
    }
  }
  printf("\n");
  free(visited);
  free(que->arr); //큐 메모리 해제
  free(que);
}
