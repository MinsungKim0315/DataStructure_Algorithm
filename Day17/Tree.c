#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	int value;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* setBinTreeNode(int* arr, int count, int idx) {
	treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	node->value = arr[idx];
	node->left = node->right = NULL;
	int LEFT = idx * 2 + 1, RIGHT = LEFT + 1;
	if (LEFT < count) {
		node->left = setBinTreeNode(arr, count, LEFT);
	}
	if (RIGHT < count) {
		node->right = setBinTreeNode(arr, count, RIGHT);
	}

	return node;
}
void displayPreOrder(treeNode* t) {
	if (t != NULL) {
		printf("%3d->", t->value);	//parent
		displayPreOrder(t->left);
		displayPreOrder(t->right);
	}
}
void displayInOrder(treeNode* t) {
	if (t != NULL) {
		displayInOrder(t->left);
		printf("%3d->", t->value);
		displayInOrder(t->right);
	}
}
void displayPostOrder(treeNode* t) {
	if (t != NULL) {
		displayPostOrder(t->left);
		displayPostOrder(t->right);
		printf("%3d->", t->value);
	}
}
void freeTree(treeNode* t) {
	if (t != NULL) {
		freeTree(t->left);
		freeTree(t->right);
		freeTree(t);
	}
}
int main() {
	int arr[] = { 8 , 4 , 12 , 2 , 6 , 10 , 14 , 1 , 3 , 5 , 7 , 9 , 11 , 13 , 15 };
	treeNode* root = setBinTreeNode(arr, sizeof(arr) / sizeof(arr[0]), 0);
	printf("\n전위 순회\n");
	displayPreOrder(root);
	printf("\n중위 순회\n");
	displayInOrder(root);
	printf("\n후위 순회\n");
	displayPostOrder(root);
	printf("\n노드 삭제\n");
	freeTree(root);
	return 0;
}
