#include<stdio.h>
#include<stdlib.h>

typedef int TreeElement;
typedef struct TreeNode {
	TreeElement value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//ADT
TreeNode* addNode(TreeNode* tree, TreeElement data);
TreeNode* removeNode(TreeNode* tree, TreeElement data);
TreeNode* searchNode(TreeNode* tree, TreeElement data);
void displayInOrder(TreeNode* tree);
TreeNode* findMax(TreeNode* tree);
TreeNode* findMin(TreeNode* tree);
void freeTree(TreeNode* tree);

TreeNode* addNode(TreeNode* tree, TreeElement data) {
	if (!tree) {
		tree = (TreeNode*)malloc(sizeof(TreeNode));
		tree->value = data;
		tree->right = NULL;
		tree->left = NULL;
	}
	else if (data == tree->value) printf("This value already exists!\n");
	else if (data < tree->value) tree->left = addNode(tree->left, data);
	else tree->right = addNode(tree->right, data);

	return tree;
}
TreeNode* removeNode(TreeNode* tree, TreeElement data) {
    TreeNode* temp = NULL;
    if (tree) {
        if (data == tree->value) {
			if (tree->left == NULL && tree->right == NULL) {	// Node is leaf
				free(tree);
				return NULL;
			}
			else {
				if(tree->left == NULL){	// Only have child in the right
					temp = tree->right;
					free(tree);
					return temp;
				}
				if (tree->right == NULL) {	// Only have child in the left
					temp = tree->left;
					free(temp);
					return temp;
				}
				// Node has both child
				temp = findMax(tree->left);
				tree->value = temp->value;
				tree->left = removeNode(tree->left, temp->value);
			}
        }
        else {
            if (data < tree->value) tree->left = removeNode(tree->left, data);
            else /* data > t->value */ tree->right = removeNode(tree->right, data);
        }
    }
    return tree;
}
TreeNode* searchNode(TreeNode* tree, TreeElement data) {
	if (!tree) return NULL;
	if (data == tree->value) return tree;
	if (data < tree->value) return searchNode(tree->left, data);
	else return searchNode(tree->right, data);
}
TreeNode* findMax(TreeNode* tree) {
	if (tree) {
		while (tree->right) {
			tree = tree->right;
		}
	}
	return tree;
}
TreeNode* findMin(TreeNode* tree) {
	if (tree) {
		while (tree->left) {
			tree = tree->left;
		}
	}
	return tree;
}
void displayInOrder(TreeNode* tree) {
	if (tree != NULL) {
		displayInOrder(tree->left);
		printf("%3d", tree->value);
		displayInOrder(tree->right);
	}
}
void freeTree(TreeNode* tree) {
	if (tree != NULL) {
		freeTree(tree->left);
		freeTree(tree->right);
		free(tree);
	}
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	TreeNode* root = NULL;

	// Adding nodes to the tree
	root = addNode(root, 50);
	root = addNode(root, 30);
	root = addNode(root, 70);
	root = addNode(root, 20);
	root = addNode(root, 40);
	root = addNode(root, 60);
	root = addNode(root, 80);

	printf("In-order display of the tree:\n");
	displayInOrder(root);
	printf("\n");

	// Searching for a node
	TreeElement searchValue = 40;
	TreeNode* searchResult = searchNode(root, searchValue);
	if (searchResult != NULL) {
		printf("Found node with value: %d\n", searchResult->value);
	}
	else {
		printf("Node with value %d not found.\n", searchValue);
	}

	// Removing a node
	TreeElement removeValue = 30;
	printf("Removing node with value: %d\n", removeValue);
	root = removeNode(root, removeValue);
	printf("In-order display after removal:\n");
	displayInOrder(root);
	printf("\n");

	// Display the maximum and minimum value in the tree
	TreeNode* maxNode = findMax(root);
	TreeNode* minNode = findMin(root);
	if (maxNode != NULL && minNode != NULL) {
		printf("Maximum value in the tree: %d\n", maxNode->value);
		printf("Minimum value in the tree: %d\n", minNode->value);
	}

	// Free the tree
	freeTree(root);

	return 0;
}
