#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
	int index;
	struct Node* next;
} Node;

Node** a;
int n, m, c[MAX_SIZE];  //정점, 간선, 방문했는지를 확인하는 변수

void addFront(Node* root, int index) {   //연결리스트 삽입 함수
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {   //깊이 우선탐색
	if (c[x]) return;  //방문한 적이 있다면 바로 리턴
	c[x] = 1;          //방문확인 변수에 1 입력
	printf("%d ", x);
	Node* cur = a[x]->next;
	while (cur != NULL) {
		int next = cur->index;
		dfs(next);
		cur = cur->next;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);   //정점과 간선을 입력받음
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);    //x 정점 리스트에 y를 추가 -> x에서 y로 갈 수 있음
		addFront(a[y], x);    //y 정점 리스트에 x를 추가
	}
	dfs(1);   //원소 1에서부터 깊이 우선탐색
	system("pause");
}