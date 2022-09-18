#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

typedef struct {      //AVL트리 정의
	int data;
	int height;   //높이를 저장해야 시간 복잡도를 보장할 수 있음
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

int getHeight(Node* node) {   //회전을 수행한 이후에 높이를 다시 계산
	if (node == NULL) return 0;
	return node->height;
}

void setHeight(Node* node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

int getDifference(Node* node) {     //균형인수를 구하는 함수
	if (node == NULL) return 0;
	Node* leftChild = node->leftChild;
	Node* rightChild = node->rightChild;
	return (getHeight(leftChild) - getHeight(rightChild));   //균형인수
}

Node* rotateLL(Node* node) {    //LL회전
	Node* leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;
	leftChild->rightChild = node;
	setHeight(node);   //회전 이후에 높이를 다시 계산
	return leftChild;  //leftChild는 이후에 setHeight()를 수행
}

Node* rotateRR(Node* node) {    //RR회전
	Node* rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	rightChild->leftChild = node;
	setHeight(node);   //회전 이후에 높이를 다시 계산
	return rightChild;  //leftChild는 이후에 setHeight()를 수행
}

Node* rotateLR(Node* node) {    //RR회전
	Node* leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);  //해당 노드는 이후에 setHeight()를 수행
}

Node* rotateRL(Node* node) {    //RR회전
	Node* rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);  //해당 노드는 이후에 setHeight()를 수행
}

Node* balance(Node* node) {    //AVL트리의 균형잡기
	int difference = getDifference(node);
	if (difference >= 2) {
		if (getDifference(node->leftChild) >= 1) {
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);   //회전 이후에 높이를 다시 계산
	return node;
}

Node* insertNode(Node* node, int data) {    //AVL 트리의 삽입
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	else if (data < node->data) {
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);    //삽입을 할 때마다 균형을 맞춤
	}
	else if (data > node->data) {
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);	//삽입을 할 때마다 균형을 맞춤
	}
	else {
		printf("데이터 중복이 발생했습니다. \n");
	}
	return node;
}

Node* root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		display(node->rightChild, level + 1);
		printf("\n");
		if (node == root) {
			printf("Root: ");
		}
		for (int i = 0; i < level && node != root; i++) {
			printf("    ");
		}
		printf("%d(%d)", node->data, getHeight(node));
		display(node->leftChild, level + 1);
	}
}

int main(void) {
	root = insertNode(root, 7);
	root = insertNode(root, 6);
	root = insertNode(root, 5);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 9);
	root = insertNode(root, 8);
	root = insertNode(root, 12);
	root = insertNode(root, 16);
	root = insertNode(root, 18);
	root = insertNode(root, 23);
	root = insertNode(root, 21);
	root = insertNode(root, 14);
	root = insertNode(root, 15);
	root = insertNode(root, 19);
	root = insertNode(root, 20);
	display(root, 1);
	printf("\n");
	system("pause");
}