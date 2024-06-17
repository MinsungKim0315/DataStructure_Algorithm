#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	int value;
	struct treeNode* right;
	struct treeNode* left;
}treeNode;

treeNode* setBinTreeNode(int* arr, int count, int idx);
void displayPreOrder(treeNode* t);
void displayInOrder(treeNode* t);
void displayPostOrder(treeNode* t);
void freeTree(treeNode* t);

treeNode* setBinTreeNode(int* arr, int count, int idx) {
	treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	node->value = arr[idx];
	node->left = node->right = NULL;
	int LEFT = idx * 2 + 1, RIGHT = LEFT + 1;
	if (LEFT < count) node->left = setBinTreeNode(arr, count, LEFT);
	if (RIGHT < count) node->right = setBinTreeNode(arr, count, RIGHT);

	return node;
}
void displayPreOrder(treeNode* t) {	//parent -> left -> right
	if (t != NULL) {
		printf("%3d", t->value);
		displayPreOrder(t->left);
		displayPreOrder(t->right);
	}
}
void displayInOrder(treeNode* t) {	//left -> parent -> right
	if (t != NULL) {
		displayInOrder(t->left);
		printf("%3d", t->value);
		displayInOrder(t->right);
	}
}
void displayPostOrder(treeNode* t) {	//left -> right -> parent
	if (t != NULL) {
		displayPostOrder(t->left);
		displayPostOrder(t->right);
		printf("%3d", t->value);
	}
}
void freeTree(treeNode* t) {
	if (t != NULL) {
		freeTree(t->left);
		freeTree(t->right);
		free(t);
	}
}
int main() {
	int arr[] = { 8 , 4 , 12 , 2 , 6 , 10 , 14 , 1 , 3 , 5 , 7 , 9 , 11 , 13 , 15 };
	treeNode* root = setBinTreeNode(arr, sizeof(arr) / sizeof(arr[0]), 0);

	printf("Pre-Order\n");
	displayPreOrder(root);
	printf("\nIn-Order\n");
	displayInOrder(root);
	printf("\nPost-Order\n");
	displayPostOrder(root);

	freeTree(root);
}
