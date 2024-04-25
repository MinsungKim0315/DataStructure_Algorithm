#include<stdio.h>
#include<stdlib.h>

typedef int DoubleListElement;
typedef struct DoubleListNode {
	DoubleListElement data;
	struct DoubleListNode* Llink;
	struct DoubleListNode* Rlink;
}DoubleListNode;

DoubleListNode* DoubleInitial(); // �ʱ�ȭ (��� ��� ����)
DoubleListNode* DoubleInsertFirst(DoubleListNode* head, DoubleListElement item);// ���� �� ��� ����
DoubleListNode* DoubleDeleteFirst(DoubleListNode* head); // ���� �� ��� ���� 
DoubleListNode* DoubleConcat(DoubleListNode* head1, DoubleListNode* head2);//����Ʈ ���� list1 + list2
void DoubleDisplay(DoubleListNode* head); // ����Ʈ ������ ���
void DoubleDisplayReverse(DoubleListNode* head); // ����Ʈ ������ ���
void FreeDoubleList(DoubleListNode* head); // ����Ʈ ��ü ����

DoubleListNode* DoubleInitial() {
	DoubleListNode* node = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	node->Rlink = node->Llink = node;
	node->data = 0;
	return node;
}
DoubleListNode* DoubleInsertFirst(DoubleListNode* head, DoubleListElement item) {
	DoubleListNode* node = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	node->data = item;
	node->Rlink = head->Rlink;	//��带 �����ϱ� �� ��Ȳ���� head->Rlink
	node->Llink = head;	//head �� ��� ���

	head->Rlink->Llink = node;	//head->Rlink->Llink�� ù ��°(����) ������ ����� Llink
	head->Rlink = node;

	return head;
}
DoubleListNode* DoubleDeleteFirst(DoubleListNode* head) {
	if (head == NULL || head == head->Rlink) return NULL;
	DoubleListNode* deleteNode = head->Rlink;

	deleteNode->Llink->Rlink = deleteNode->Rlink;
	deleteNode->Rlink->Llink = deleteNode->Llink;

	free(deleteNode);

	return head;
}
DoubleListNode* DoubleConcat(DoubleListNode* head1, DoubleListNode* head2) {
	if (head1 == NULL || head1 == head1->Rlink) return head2;
	else if (head2 == NULL || head2 == head2->Rlink) return head1;
	else{
		head1->Llink->Rlink = head2->Rlink;
		head2->Rlink->Llink = head1->Rlink;
		head2->Llink->Rlink = head1;
		head1->Llink = head2->Llink;
		head2->Llink = head2;
		head2->Rlink = head2;
	}
	return head1;
}
void DoubleDisplay(DoubleListNode* head) {
	printf("Display: ");
	for (DoubleListNode* pNode = head->Rlink; pNode != head; pNode = pNode->Rlink) {
		printf("%d ->", pNode->data);
	}printf("\n");
}
void DoubleDisplayReverse(DoubleListNode* head) {
	printf("Reversed Display: ");
	for (DoubleListNode* pNode = head->Llink; pNode != head; pNode = pNode->Llink) {
		printf("%d ->", pNode->data);
	}printf("\n");
}
void FreeDoubleList(DoubleListNode* head) {
	for (DoubleListNode* pNode = head->Rlink, *deleteNode = NULL; pNode != head; ) {
		deleteNode = pNode;
		pNode = pNode->Rlink;
		free(deleteNode);
	}
	free(head);
}
int main() {
	DoubleListNode* head1 = DoubleInitial();
	DoubleListNode* head2 = DoubleInitial();

	/*DoubleListNode headNode;
	headNode.Rlink = &headNode;
	headNode.Llink = &headNode;
	headNode.data = 0;

	head = &headNode;*/

	DoubleInsertFirst(head1, 1);
	/*DoubleListNode n1;
	n1.data = 1;
	n1.Rlink = &headNode;
	n1.Llink = &headNode;
	headNode.Rlink = &n1;
	headNode.Llink = &n1;

	head = &headNode;*/

	DoubleInsertFirst(head1, 2);
	/*DoubleListNode n2;
	n2.data = 2;
	n2.Rlink = &n1;
	n2.Llink = &headNode;
	headNode.Rlink = &n2;
	n1.Llink = &n2;
	
	head = &headNode;*/
	DoubleInsertFirst(head1, 3);
	DoubleInsertFirst(head1, 4);
	DoubleInsertFirst(head1, 5);

	DoubleInsertFirst(head2, 2);
	DoubleInsertFirst(head2, 4);
	DoubleInsertFirst(head2, 6);
	DoubleInsertFirst(head2, 8);
	DoubleInsertFirst(head2, 10);
	/*DoubleListNode* pNode = head->Rlink;
	while (pNode != head)
	{
		printf("%d ->", pNode->data);
		pNode = pNode->Rlink;
	}*/

	//DoubleDeleteFirst(head);
	//DoubleConcat(head1, head2);
	DoubleDisplay(head1);
	DoubleDisplay(head2);
}