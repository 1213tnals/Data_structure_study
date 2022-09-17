#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return node;
}

//1.이진트리의 전위 순회
void preorder(Node* root) {
	if (root) {   //루트가 널 값이 아니면 재귀적으로 작동
		printf("%d ", root->data); //출력하고 이동
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

//2.이진트리의 중위 순회
void inorder(Node* root) {
	if (root) {
		inorder(root->leftChild);
		printf("%d ", root->data); //왼쪽으로 이동하고 출력
		inorder(root->rightChild);
	}
}

//3.이진트리의 후위 순회
void postorder(Node* root) {
	if (root) {
		preorder(root->leftChild);
		preorder(root->rightChild);
		printf("%d ", root->data); //이동 다 하고 출력
	}
}

int main(void) {
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);
	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(30, n2, n3);
	preorder(n1);
	printf("\n");
	inorder(n1);
	printf("\n");
	postorder(n1);
	system("pause");
	return 0;
}