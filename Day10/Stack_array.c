#include<stdio.h>
#include<stdlib.h>

typedef char StackElement;
typedef struct StackType {
	StackElement* data;	//스택으로 사용할 배열의 주소
	int capacity;		//스택의 총 용량(배열의 칸 수)
	int top;				//저장할 자료의 위치(=자료개수)
}StackType;

StackType* init_stack(); //구성요소 초기화
int is_empty(StackType* stack); //텅 빈 상태 확인
int is_full(StackType* stack); //포화 상태 확인
int push(StackType* stack, StackElement item); //맨 위에 item 넣기
StackElement pop(StackType* stack); //맨 위 자료 꺼내기
StackElement peek(StackType* stack); //맨 위 값 확인
void print(StackType* stack); //자료 출력
void free_stack(StackType** stack); //스택 제거

StackType* init_stack() {
	StackType* stack = (StackType*)malloc(sizeof(StackType));
	if (stack == NULL) return NULL;
	stack->top = 0;
	stack->capacity = 1;
	stack->data = (StackElement*)malloc(sizeof(StackElement) * stack->capacity);
	if (stack->data == NULL) return NULL;
	
	return stack;
}

int is_empty(StackType* stack) {
	return (stack->top == 0);
}

int is_full(StackType* stack) {
	return (stack->top == stack->capacity);
}

int push(StackType* stack, StackElement item) {

	if (is_full(stack)) {
		stack->capacity *= 2;
		StackElement* temp = stack->data;	//realloc 이 제대로 작동하기 위한 작업, 기존의 배열 복사
		stack->data = (StackElement*)realloc(stack->data, sizeof(StackElement) * stack->capacity);
		if (stack->data == NULL)stack->data = temp;  return 0;
	}
	stack->data[(stack->top)++] = item;

	return 1;
}

StackElement pop(StackType* stack) {
	if (is_empty(stack))return 0;
	if (stack->top < stack->capacity / 2) {
		stack->capacity /= 2;
		StackElement* temp = stack->data;
		stack->data = (StackElement*)realloc(stack->data, sizeof(StackElement) * stack->capacity);
		if (stack->data == NULL) return 0;
	}
	return stack->data[--(stack->top)];
}

StackElement peek(StackType* stack) {
	if (is_empty(stack)) return 0;
	return stack->data[stack->top - 1];
}


void print(StackType* stack) {
	for (int i = stack->top - 1; i >= 0; i--) {
		printf("%2d: %7c\n", i, stack->data[i]);
	}
}

void free_stack(StackType** stack) {
	free((*stack)->data);
	free(*stack);
	*stack = NULL;
}

int main() {
	StackType* stack = init_stack();

	char str[256];
	gets_s(str, 256);
	for (int i = 0; str[i] != NULL; i++) {
		push(stack, str[i]);
	}
	for (int i = 0; !is_empty(stack); i++) {
		str[i] = pop(stack);
	}
	printf("%s", str);
	

	free(stack);
}
