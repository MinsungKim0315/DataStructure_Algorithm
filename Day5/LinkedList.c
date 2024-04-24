#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
	return pNode;	//main함수에 head가 있으므로 pNode를 리턴하면 head가 자동으로 pNode와 연결됨
}


ListNode* insert_last(ListNode* head, list_element value) {	//맨 뒤 노드 생성
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = value;
	newNode->link = NULL;

	if (head == NULL) return newNode;
	ListNode* pNode = head;
	while (pNode->link != NULL) {	//traverse to the last node
		pNode = pNode->link;
	}
	pNode->link = newNode;
	return head;
}

ListNode* delete_last(ListNode* head) {	//맨 뒤 노드 삭제
	if (head == NULL) return NULL;
	ListNode* pNode = head;
	ListNode* prevNode = NULL;

	while (pNode->link != NULL) {
		prevNode = pNode;
		pNode = pNode->link;
	}
	free(pNode);
	prevNode->link = NULL;

	return head;
}

int delete_search(ListNode* head, list_element value) {	// 검색된 노드 삭제
	if (head == NULL) return NULL;

	ListNode* pNode = head;
	ListNode* prevNode = NULL;

	if (pNode->data == value) {	//첫번 째 노드가 검색된 노드인 경우
		ListNode* newHead = pNode->link;
		free(pNode);
		return newHead;
	}

	while (pNode != NULL && pNode->data != value) {
		prevNode = pNode;
		pNode = pNode->link;	//keep track of the previous node
	}

	if (pNode == NULL) return head;	//if the node was not found

	if (prevNode != NULL) {	//prevNode가 NULL인 경우는 첫 번째 노드를 제거하는 경우임
		prevNode->link = pNode->link;
	}
	free(pNode);	//찾은 노드 제거
	return head;
}


ListNode* insert_sort(ListNode* head, list_element value) {	// 정렬된 노드 생성
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->data = value;
	NewNode->link = NULL;

	if (head == NULL) return NewNode; // Node 없음

	ListNode* forward = head, * rear = NULL; //NewNode 기준 앞, 뒤 노드 위치 찾기

	while (forward != NULL) {
		if (forward->data > value)break;
		rear = forward;
		forward = forward->link;
	}
	if (forward == head) { // 새 노드 위치가 맨 앞
		NewNode->link = forward;
		return NewNode;
	}
	else { // 새 노드 위치가 중간, 맨 뒤
		NewNode->link = forward;
		rear->link = NewNode;
	}
	return head;

}

void swap(ListNode* a, ListNode* b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

ListNode* list_sort(ListNode* head) {	//노드 정렬
	ListNode* pNode;
	ListNode* lastNode = NULL;
	int swapped;

	do {
		swapped = 0;
		pNode = head;
		while (pNode->link != lastNode) {
			if (pNode->data > pNode->link->data) {
				swap(pNode, pNode->link);
				swapped = 1;
			}
			pNode = pNode->link;
		}
		lastNode = pNode;
	} while (swapped);
	/*
 	for (ListNode* pNode = head; pNode != NULL; pNode = pNode->link) {
	for (ListNode* nextNode = pNode->link; nextNode != NULL; nextNode = nextNode->link) {
		if (pNode->data > nextNode->data) swap(pNode, nextNode);
		}
	}
 	*/
	return head;
}

void freelist(ListNode** head) {	//메인에 있는 리스트 메모리 해제
	ListNode* DeleteNode = NULL;
	while (*head) {
		DeleteNode = *head;
		*head = (*head)->link;
		free(DeleteNode);	//Free the memory allocated for the node pointed to by DeleteNode
	}
	*head = NULL;	//헤드를 NULL로 초기화
}

void print_list(ListNode* head) {
	ListNode* pNode = head;
	while (pNode != NULL)
	{
		printf("%3d -> ", pNode->data);
		pNode = pNode->link;
	}printf("\n");
}


int main() {
	srand((unsigned)time(NULL));
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;

	//맨 앞에 노드 추가, 연결 리스트 생성
	//1 2 5 10
	head1 = insertHead(head1, 10);
	head1 = insertHead(head1, 5);
	head1 = insertHead(head1, 2);
	head1 = insertHead(head1, 1);

	//2 4 10 20 
	head2 = insertHead(head2, 20);
	head2 = insertHead(head2, 10);
	head2 = insertHead(head2, 4);
	head2 = insertHead(head2, 2);
	insert_sort(head2, rand() % 100);

	//2 1 4 3
	head3 = insertHead(head3, 3);
	head3 = insertHead(head3, 4);
	head3 = insertHead(head3, 1);
	head3 = insertHead(head3, 2);


	//맨 앞 노드 제거
	//head1 = deleteFirst(head1);

	//concat
	// concat(head1, head2);

	//끝에 노드 추가
	//insert_last(head1, 100);

	//끝 노드 제거
	//delete_last(head1);

	//검색한 노드 삭제
	//delete_search(head2, 10);

	//리스트 전체 메모리서 제거
	//freelist(&head2);

	//출력
	print_list(head1);
	print_list(head2);
	print_list(head3);
	//list_sort(head3);
	//print_list(head3);
}





/* Notes
while(pNode != NULL)
	pNode 가 마지막 NULL을 가리키고 있으며 마지막 n번째 노드까지 커버한다
while(pNode->link != NULL)
	pNode 가 마지막 노드들 가리키고 있으며 n - 1번 째 노드까지만 커버한다
*/
