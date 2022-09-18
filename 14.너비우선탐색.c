#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct {
	int index;            //형이 int
	struct Node* next;    //형이 struct Node*
} Node;

typedef struct {  //큐 생성
	Node* front;
	Node* rear;
	int count;
} Queue;

Node** a;    //인접한 정점들에 대한 정보를 담음->2차원 포인터로
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
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* node = queue->front;
	int index = node->index;
	queue->front = node->next;
	free(node);
	queue->count--;
	return index;
}

void bfs(int start) {     //너비 우선 탐색 함수
	Queue q;
	q.front = q.rear = NULL;   //q를 초기화
	q.count = 0;
	queuePush(&q, start);     //큐에 시작인덱스를 넣음
	c[start] = 1;             //방문했음을 알림
	while (q.count != 0) {    //큐가 빌 때까지
		int x = queuePop(&q); //큐의 한 원소를 빼서(큐이므로 맨 앞 원소가 빠져나옴)
		printf("%d ", x);     
		Node* cur = a[x]->next;  //원소에 연결된 노드를 하나씩 확인
		while (cur != NULL) {
			int next = cur->index;
			if (!c[next]) {     //연결된 노드에 다음이 있으면
				queuePush(&q, next);  //원소를 하나씩 빼고 방문했음을 알림
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