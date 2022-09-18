#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
	int index;
	struct Node* next;
} Node;

Node** a;
int n, m, c[MAX_SIZE];  //����, ����, �湮�ߴ����� Ȯ���ϴ� ����

void addFront(Node* root, int index) {   //���Ḯ��Ʈ ���� �Լ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {   //���� �켱Ž��
	if (c[x]) return;  //�湮�� ���� �ִٸ� �ٷ� ����
	c[x] = 1;          //�湮Ȯ�� ������ 1 �Է�
	printf("%d ", x);
	Node* cur = a[x]->next;
	while (cur != NULL) {
		int next = cur->index;
		dfs(next);
		cur = cur->next;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);   //������ ������ �Է¹���
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);    //x ���� ����Ʈ�� y�� �߰� -> x���� y�� �� �� ����
		addFront(a[y], x);    //y ���� ����Ʈ�� x�� �߰�
	}
	dfs(1);   //���� 1�������� ���� �켱Ž��
	system("pause");
}