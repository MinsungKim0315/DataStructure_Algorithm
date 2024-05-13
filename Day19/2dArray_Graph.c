//2차원 배열로 표현한 그래프
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
///// Weighted Graph /////
typedef struct graph {
	int verCount; //정점의 개수
	int** arr; //동적 할당 된 2차원 배열의 주소 저장
}graph;
graph* graphInitialize(int count);
void addDirectedEdge(graph* p, int src, int dest, int weight);
void addUnDirectedEdge(graph* p, int src, int dest, int weight);
void graphDisplay(graph* p);
void memoryFree(graph* p);
int main() {
	graph* grp1 = graphInitialize(4); //구조체, 정점의 개수
	graph* grp2 = graphInitialize(4); 

	addUnDirectedEdge(grp1, 0, 1, 2); //구조체, 출발지, 도착지, 가중치
	addUnDirectedEdge(grp1, 0, 2, 3);
	addUnDirectedEdge(grp1, 1, 2, 4);
	addUnDirectedEdge(grp1, 2, 3, 5);

	addDirectedEdge(grp2, 0, 1, 2);
	addDirectedEdge(grp2, 0, 2, 3);
	addDirectedEdge(grp2, 1, 2, 4);
	addDirectedEdge(grp2, 2, 3, 5);

	graphDisplay(grp1);
	graphDisplay(grp2);

	memoryFree(grp1);
	memoryFree(grp2);
	return 0;
}

graph* graphInitialize(int count) {
	graph* pG = (graph*)malloc(sizeof(graph));
	pG->verCount = count;
	pG->arr = (int**)calloc(count, sizeof(int*));
	for (int i = 0; i < count; i++) {
		pG->arr[i] = (int*)calloc(count, sizeof(int));
	}

	return pG;
}

void addDirectedEdge(graph* p, int src, int dest, int weight) {  //방향 그래프
	p->arr[src][dest] = weight;
}
void addUnDirectedEdge(graph* p, int src, int dest, int weight) { //무방향 그래프
	addDirectedEdge(p, src, dest, weight);
	addDirectedEdge(p, dest, src, weight);
}
void graphDisplay(graph* p) {
	printf("\n\n *** Graph 인접 행렬 ***\n\n    │");
	for (int i = 0; i < p->verCount; i++) printf(" %3d", i);
	printf("\n────┼");
	for (int i = 0; i < p->verCount; i++) printf("────");
	printf("\n");
	for (int i = 0; i < p->verCount; i++) {  //vertex의 개수만큼 반복
		printf("%3d │ ", i);
		for (int j = 0; j < p->verCount; j++) {
			printf("%3d ", p->arr[i][j]);
		}
		printf("\n");
	}
}
void memoryFree(graph* p) {
	for (int i = 0; i < p->verCount; i++) free(p->arr[i]); //free(포인터); 포인터가 가리키는 메모리가 해제
	free(p->arr);
	free(p);
}
