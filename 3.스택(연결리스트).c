#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node* next;
} Node;

typedef struct {    //Stack노드: 최상단을 변수로 갖는 노드
	Node* top;
} Stack;

void push(Stack* stack, int data) {    //스택 삽입
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

void pop(Stack* stack) {    //스택의 포인터를 받으므로 메모리 주소를 받아야지 작동
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack* stack) {
	Node* cur = stack->top;
	printf("---스택의 최상단---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---스택의 최하단---\n");
}

int main(void) {
	Stack s;
	s.top = NULL;  //스택의 오류를 확인하기 위해서 NULL을 처음에 넣어준다.
	push(&s, 7);
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 6);
	pop(&s);
	show(&s);
	system("pause");
	return 0;
}