#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct {
	int index;            //���� int
	struct Node* next;    //���� struct Node*
} Node;

typedef struct {  //ť ����
	Node* front;
	Node* rear;
	int count;
} Queue;

Node** a;    //������ �����鿡 ���� ������ ����->2���� �����ͷ�
int n, m, c[MAX_SIZE];

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void queuePush(Queue* queue, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = NULL;

	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int queuePop(Queue* queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = queue->front;
	int index = node->index;
	queue->front = node->next;
	free(node);
	queue->count--;
	return index;
}

void bfs(int start) {     //�ʺ� �켱 Ž�� �Լ�
	Queue q;
	q.front = q.rear = NULL;   //q�� �ʱ�ȭ
	q.count = 0;
	queuePush(&q, start);     //ť�� �����ε����� ����
	c[start] = 1;             //�湮������ �˸�
	while (q.count != 0) {    //ť�� �� ������
		int x = queuePop(&q); //ť�� �� ���Ҹ� ����(ť�̹Ƿ� �� �� ���Ұ� ��������)
		printf("%d ", x);     
		Node* cur = a[x]->next;  //���ҿ� ����� ��带 �ϳ��� Ȯ��
		while (cur != NULL) {
			int next = cur->index;
			if (!c[next]) {     //����� ��忡 ������ ������
				queuePush(&q, next);  //���Ҹ� �ϳ��� ���� �湮������ �˸�
				c[next] = 1;
			}
			cur = cur->next;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}
	bfs(1);
	system("pause");
	return 0;
}