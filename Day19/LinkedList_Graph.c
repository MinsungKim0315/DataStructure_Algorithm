// 연결 리스트 그래프, Kruskal MST
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
int main() {
	graph* grp = graphInitialize(4); //그래프, 정점의 개수
	addUnDirectedEdge(grp, 0, 1);
	addUnDirectedEdge(grp, 0, 2);
	addUnDirectedEdge(grp, 1, 2);
	addUnDirectedEdge(grp, 2, 3);
	graphDisplay(grp);
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
