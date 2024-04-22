#include<stdio.h>
#include<stdlib.h>

typedef int list_element;
typedef struct ListNode {
	list_element data;
	struct ListNode* link;
}ListNode;

ListNode* insertHead(ListNode* head, list_element value) {
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->data = value;
	NewNode->link = head;
	return NewNode;
}
int main() {
	ListNode* head = NULL;

	//10 : 1 2 5 10
	head = insertHead(head, 1);
	head = insertHead(head, 2);
	head = insertHead(head, 5);
	head = insertHead(head, 10);
	/*ListNode n1;
	n1.data = 1;
	n1.link = NULL;

	head = &n1;

	ListNode n2;
	n2.data = 2;
	n2.link = &n1;

	head = &n2;

	ListNode n3;
	n3.data = 5;
	n3.link = &n2;

	head = &n3;

	ListNode n4;
	n4.data = 10;
	n4.link = %n3;

	head = &n4;*/

	ListNode* pNode = head;
	while (pNode != NULL) {
		printf("%3d --> ", pNode->data);
		pNode = pNode->link;
	}
}