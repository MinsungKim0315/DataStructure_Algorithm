#include<stdio.h>
#include<stdlib.h>

typedef int DoubleListElement;
typedef struct  DoubleListNode {
	DoubleListElement data;
	struct DoubleListNode* Llink;
	struct DoubleListNode* Rlink;
}DoubleListNode;

DoubleListNode* DoubleInitial() {
	DoubleListNode* headNode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	headNode->data = 0;
	headNode->Rlink = headNode;
	headNode->Llink = headNode;

	return headNode;
}
DoubleListNode* DoubleInsertFirst(DoubleListNode* head, DoubleListElement item) {
	DoubleListNode* newNode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	newNode->data = item;
	if (head->Rlink == head) {
		newNode->Rlink = newNode;
		newNode->Llink = newNode;
	}
	else {
		newNode->Rlink = head->Llink;
		newNode->Llink = head->Rlink;
	}
	head->Rlink->Rlink = newNode;
	head->Llink->Llink = newNode;
	head->Llink = newNode;

	return head;
}

DoubleListNode* DoubleDeleteFirst(DoubleListNode* head) {
	DoubleListNode* deleteNode = head->Llink;
	if (deleteNode == deleteNode->Rlink) {
		head->Llink = head->Rlink = head;
	}
	deleteNode->Llink->Rlink = deleteNode->Rlink;
	deleteNode->Rlink->Llink = deleteNode->Llink;
	head->Llink = deleteNode->Rlink;

	free(deleteNode);

	return head;
}
DoubleListNode* DoubleConcat(DoubleListNode* head1, DoubleListNode* head2) {
	if (head1 == NULL || head1->Llink == head1) return head2;
	else if (head2 == NULL || head2->Llink == head2) return head1;
	else {
		head1->Rlink->Rlink = head2->Llink;
		head2->Llink->Llink = head1->Rlink;
		head1->Llink->Llink = head2->Rlink;
		head2->Rlink->Rlink = head1->Llink;
		head1->Rlink = head2->Rlink;
		return head1;
	}
}
void DoubleDisplay(DoubleListNode* head) {
	if (head == NULL || head->Llink == head) return;
	DoubleListNode* pNode = head->Llink;
	do {
		printf("%5d -> ", pNode->data);
		pNode = pNode->Rlink;
	} while (pNode != head->Llink);
	printf("\n");
}
void DoubleDisplayReversed(DoubleListNode* head) {
	if (head == NULL || head->Llink == head) return;
	DoubleListNode* pNode = head->Rlink;
	do {
		printf("%5d -> ", pNode->data);
		pNode = pNode->Llink;
	} while (pNode != head->Rlink);
	printf("\n");
}
void FreeDoubleList(DoubleListNode* head) {
	for (DoubleListNode* pNode = head->Llink, *deleteNode = NULL; pNode != head->Rlink; ) {
		deleteNode = pNode;
		pNode = pNode->Rlink;
		free(deleteNode);
	}free(head->Rlink);
	free(head);
}
int main() {
	DoubleListNode* head1 = DoubleInitial();
	DoubleListNode* head2 = DoubleInitial();

	DoubleInsertFirst(head1, 5);
	DoubleInsertFirst(head1, 4);
	DoubleInsertFirst(head1, 3);
	DoubleInsertFirst(head1, 2);
	DoubleInsertFirst(head1, 1);

	DoubleInsertFirst(head2, 10);
	DoubleInsertFirst(head2, 9);
	DoubleInsertFirst(head2, 8);
	DoubleInsertFirst(head2, 7);
	DoubleInsertFirst(head2, 6);

	//DoubleDeleteFirst(head1);

	DoubleDisplay(head1);
	DoubleDisplay(head2);
	DoubleConcat(head1, head2);
	DoubleDisplay(head1);
	DoubleDisplayReversed(head1);
	FreeDoubleList(head1);
	DoubleDisplay(head1);
}