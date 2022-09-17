#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct {
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

Node* head, * tail;

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != tail) {  //오름차순으로 저장하기 위해서 현재 데이터가 더 크면 현재 노드를 뒤로
		cur = cur->next;
	}
	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

void removeFront() {
	Node* node = head->next;
	head->next = node->next;
	Node* next = head->next;
	head->prev = head;
	free(node);
}

void show() {
	Node* cur = head->next;
	while (cur != tail) {
		printf("%d번째 데이터는: ", count);
		printf("%d\n", cur->data);
		cur = cur->next;
		count++;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);
	removeFront();
	show();
	system("pause");
	return 0;
}