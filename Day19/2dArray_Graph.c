#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct graph {
	int verCount;	//num of vertex
	int** arr;		//address of allocated 2d array
}graph;

// ADT
graph* graphInitialize(int count);
void addDirectedEdge(graph* p, int src, int dest);
void addUnDirectedEdge(graph* p, int src, int dest);
void graphDisplay(graph* p);
void memoryFree(graph* p);

int main() {
	graph* grp = graphInitialize(4); 
	addUnDirectedEdge(grp, 0, 1);
	addUnDirectedEdge(grp, 0, 2);
	addUnDirectedEdge(grp, 1, 2);
	addUnDirectedEdge(grp, 2, 3);
	graphDisplay(grp);
	memoryFree(grp);
	return 0;
}

graph* graphInitialize(int count) {
	graph* pG = (graph*)malloc(sizeof(graph));
	pG->verCount = count;
	pG->arr = (int**)calloc(count, sizeof(int*));	//create rows
	for (int i = 0; i < count; i++) {	//create columns
		pG->arr[i] = (int*)calloc(count, sizeof(int));
	}
	return pG;
}
void addDirectedEdge(graph* p, int src, int dest) {
	p->arr[src][dest] = 1;
}
void addUnDirectedEdge(graph* p, int src, int dest) {
	addDirectedEdge(p, src, dest);
	addDirectedEdge(p, dest, src);
}
void graphDisplay(graph* p) {
	printf("\n\n *** Graph in 2d-array ***\n\n    │");
	for (int i = 0; i < p->verCount; i++) printf(" %3d", i);
	printf("\n────┼");
	for (int i = 0; i < p->verCount; i++) printf("────");
	printf("\n");
	for (int i = 0; i < p->verCount; i++) {
		printf("%3d │ ", i);
		for (int j = 0; j < p->verCount; j++) {
			printf("%3d ", p->arr[i][j]);
		}
		printf("\n");
	}
}
void memoryFree(graph* p) {
	for (int i = 0; i < p->verCount; i++) {
		free(p->arr[i]);
	}
	free(p->arr);
	free(p);
}
