#include<stdio.h>
#include<stdlib.h>

typedef int ListElement;
typedef struct ListNode {
	ListElement data;
	struct ListNode* link;
}ListNode;

typedef ListNode StackElement;
typedef struct StackType {
	StackElement* StackHead;
	int Size;
}StackType;

StackType* init_stack() {
	StackType* stack = (StackType*)malloc(sizeof(StackType));
	if (stack == NULL) return NULL;
	stack->StackHead = NULL;
	stack->Size = 0;

	return stack;
}

int is_empty(StackType* stack) {
	return(stack->Size == 0);
}

int push(StackType* stack, ListElement value) {
	StackElement* newNode = (StackElement*)malloc(sizeof(StackElement));
	newNode->data = value;
	newNode->link = stack->StackHead;
	stack->StackHead = newNode;
	stack->Size++;

	return 1;
}

ListElement pop(StackType* stack) {
	if (is_empty(stack)) return 0;
	stack->Size--;
	StackElement* delNode = stack->StackHead;
	stack->StackHead = delNode->link;
	ListElement temp = delNode->data;
	free(delNode);
	return temp;
}

ListElement peek(StackType* stack) {
	if (is_empty(stack)) return 0;
	return stack->StackHead->data;
}

void print(StackType* stack) {
	if (is_empty(stack)) return 0;
	printf("-> ");
	for (StackElement* pNode = stack->StackHead; pNode != NULL; pNode = pNode->link) {
		printf("%4d -> ", pNode->data);
	}printf("\n");
}

void free_stack(StackType** stack) {
	for (StackElement* pNode = (*stack)->StackHead, *DeleteNode = NULL; pNode != NULL;) {
		DeleteNode = pNode;
		pNode = pNode->link;
		free(DeleteNode);
	}
	free(*stack);
	*stack = NULL;
}

int main() {
	StackType* s = init_stack();

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);

	print(s);

	free_stack(s);
}
