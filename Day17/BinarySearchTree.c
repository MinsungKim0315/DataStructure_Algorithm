#include<stdio.h>
#include<stdlib.h>

typedef int TreeElement;
typedef struct TreeNode {
	TreeElement value;
	int level;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* addNode(TreeNode* tree, TreeElement data); // 트리 노드 추가 
TreeNode* removeNode(TreeNode* tree, TreeElement data); // 트리 노드 삭제
TreeNode* searchNode(TreeNode* tree, TreeElement data); // 트리 노드 탐색
void displayInOrder(TreeNode* tree); // 중위 순회
TreeNode* findMin(TreeNode* tree); // 최소값 탐색
TreeNode* findMax(TreeNode* tree); // 최대값 탐색
void freeTree(TreeNode* tree); // 트리 제거

int main() {
	int arr[] = { 8 , 4 , 12 , 2 , 6 , 10 , 14 , 1 , 3 , 5 , 7 , 9 , 11 , 13 , 15 };
	TreeNode* root = NULL;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		root = addNode(root, arr[i]);
	}
	displayInOrder(root);
	printf("\n");
	removeNode(root, 8);
	displayInOrder(root);
	printf("\n");
	root = addNode(root, 15);

	freeTree(root);
}
TreeNode* addNode(TreeNode* tree, TreeElement data) {
	if (!tree) {	//tree == NULL
		tree = (TreeNode*)malloc(sizeof(TreeNode));
		tree->value = data;
		tree->right = NULL;
		tree->left = NULL;
	}
	else if (data == tree->value) printf("\n\n\t\t%d는 이미 등록 된 값 입니다.\n", data);
	else if (data > tree->value) tree->right = addNode(tree->right, data);
	else tree->left = addNode(tree->left, data);

	return tree;
}

TreeNode* removeNode(TreeNode* tree, TreeElement data) {
	TreeNode* temp = NULL;
	if (tree) {
		if (data == tree->value) {	//Found
			if (tree->right == NULL && tree->left == NULL) {	//node is leaf
				free(tree);
				return NULL;
			}
			else {
				if (tree->right == NULL) {	//only have left child
					temp = tree->left;
					free(tree);
					return temp;
				}
				if (tree->left == NULL) {	//only have right child
					temp = tree->right;
					free(tree);
					return temp;
				}
				temp = findMax(tree->left);	//have both right and left child
				tree->value = temp->value;
				tree->left = removeNode(tree->left, temp->value);
			}
		}
		else {
			if (data > tree->value) tree->right = removeNode(tree->right, data);	//Searching
			else tree->left = removeNode(tree->left, data);	//Searching
		}
	}
	return tree;
}

TreeNode* searchNode(TreeNode* tree, TreeElement data) {
	static int level_search;
	if (!tree) return NULL;
	if (data == tree->value) return tree;
	if (data > tree->value)return searchNode(tree->right, data);
	else return searchNode(tree->left, data);
}
void displayInOrder(TreeNode* tree) {
	if (tree != NULL) {
		displayInOrder(tree->left);
		printf("%3d ->", tree->value);
		displayInOrder(tree->right);
	}
}
TreeNode* findMin(TreeNode* tree) { // 가장 왼쪽이 최소값
	if (tree && tree->left) return findMin(tree->left);
	return tree;
}
TreeNode* findMax(TreeNode* tree) { // 가장 오른쪽이 큰 값
	if (tree && tree->right) return findMax(tree->right);
	return tree;
}
void freeTree(TreeNode* tree) { // 후위 순회 : 왼쪽 - 오른쪽 - 부모
	if (tree) {
		freeTree(tree->left); // 왼쪽
		freeTree(tree->right); // 오른쪽
		printf("%d노드 삭제\n", tree->value); // 부모
		free(tree); // 메모리 해제 (루트 노드 가장 마지막에 해제)
	}
}
