#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int dst;
	struct node* next;
}node;
typedef struct graph {
	int count;
	node* arr;
}graph;

//ADT
graph* graphInitialize(int count);
void addDirectedEdge(graph* grp, int src, int dst);
void addUnDirectedEdge(graph* grp, int src, int dst);
void graphDisplay(graph* grp);
void memoryFree(graph* grp);

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
void graphDisplay(graph* grp) {
	if (grp == NULL) return;
	for (int i = 0; i < grp->count; i++) {
		printf("Start Node: %d ==> ", i);
		for (node* cur = grp->arr[i].next; cur; cur = cur->next) {
			printf("%d ", cur->dst);
		}
		printf("\n");
	}
}
void memoryFree(graph* grp) {
	for (int i = 0; i < grp->count; i++) {
		while (grp->arr[i].next) { 
			node* delNode = grp->arr[i].next;
			grp->arr[i].next = delNode->next; 
			free(delNode);
		}
	}
	free(grp->arr);
	free(grp);
}
