#include<stdio.h>
#include<stdlib.h>

typedef int list_element;
typedef struct ListNode {
	list_element data;
	struct ListNode* link;
}ListNode;

ListNode* insertHead(ListNode* head, list_element value) {	//맨 앞에 Node 추가
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->data = value;
	NewNode->link = head;
	return NewNode;
}

ListNode* deleteFirst(ListNode* head) {	//맨 앞에 Node 제거
	if (head == NULL) return NULL;
	ListNode* DeleteNode = head;
	head = head->link;
	free(DeleteNode);
	return head;
}

ListNode* search(ListNode* head, list_element value) {	//검색
	for (ListNode* pNode = head; pNode != NULL; pNode = pNode->link) {
		if (pNode->data == value) return pNode;
	}
	return NULL;
}

ListNode* concat(ListNode* head1, ListNode* head2) {	//list1 + list2
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* pNode = head1;
		while (pNode->link != NULL) pNode = pNode->link;
		pNode->link = head2;
		return head1;
	}
}

ListNode* reversed(ListNode* head) {	//연결 방향 바꾸기
	ListNode* foward = head, * pNode = NULL, * rear = NULL;
	while (foward != NULL) {
		rear = pNode;
		pNode = foward;
		foward = foward->link;
		pNode->link = rear;
	}
	return pNode;
}

ListNode* insert_last(ListNode* head, list_element value);// 맨 뒤 노드 생성
ListNode* insert_sort(ListNode* head, list_element value);// 정렬된 노드 생성
ListNode* delete_last(ListNode* head);// 맨 뒤 노드 삭제
int delete_search(ListNode** head, list_element value);// 검색된 노드 삭제
ListNode* ListSort(ListNode* head);// 노드 정렬
void freelist(ListNode** head);// 리스트 메모리 해제

void print_list(ListNode* head) {
	ListNode* pNode = head;
	while (pNode != NULL)
	{
		printf("%3d -> ", pNode->data);
		pNode = pNode->link;
	}printf("\n");
}


int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	/*ListNode n1;
	n1.data = 10;
	n1.link = NULL;

	head1 = &n1;
	
	ListNode n2;
	n2.data = 5;
	n2.link = &n1;

	head1 = &n2;

	ListNode n3;
	n3.data = 2;
	n3.link = &n2;

	head1 = &n3;

	ListNode n4;
	n4.data = 1;
	n4.link = &n3;

	head1 = &n4;*/
	//맨 앞에 노드 추가, 연결 리스트 생성
	head1 = insertHead(head1, 10);
	head1 = insertHead(head1, 5);
	head1 = insertHead(head1, 2);
	head1 = insertHead(head1, 1);

	head2 = insertHead(head2, 20);
	head2 = insertHead(head2, 10);
	head2 = insertHead(head2, 4);
	head2 = insertHead(head2, 2);

	//맨 앞 노드 제거
	//head1 = deleteFirst(head1);


	//탐색
	/*ListNode* find = search(head1, 1);
	if (find != NULL)
		printf("%d found\n", find->data);
	else
		printf("unfound");*/

	//출력
	print_list(head1);
	print_list(head2);
	concat(head1, head2);
	head1 = reversed(head1);
	print_list(head1);
}
