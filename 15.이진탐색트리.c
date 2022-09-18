#include <stdio.h>
#include <stdlib.h>

typedef struct {     //이진 탐색트리 정의
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

Node* insertNode(Node* root, int data) {   //이진 탐색트리의 삽입
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->data = data;
		return root;
	}
	else {
		if (root->data > data) {
			root->leftChild = insertNode(root->leftChild, data);
		}
		else {
			root->rightChild = insertNode(root->rightChild, data);
		}
	}
	return root;
}

Node* searchNode(Node* root, int data) {    //이진 탐색트리의 탐색
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	else if (root->data > data) searchNode(root->leftChild, data);
	else return searchNode(root->rightChild, data);
}

void preorder(Node* root) {     //이진 탐색 트리의 순회
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

Node* findMinNode(Node* root) {    //이진 탐색 트리의 가장 작은 원소 찾기
	Node* node = root;
	while (node->leftChild != NULL) {
		node = node->leftChild;
	}
	return node;
}

Node* deleteNode(Node* root, int data) {   //이진 탐색 트리의 원소 제거 함수
	Node* node = NULL;
	if (root == NULL) return NULL;
	if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);
	else if (root->data < data) root->rightChild = deleteNode(root->rightChild, data);
	else {
		if (root->leftChild != NULL && root->rightChild != NULL) {
			node = findMinNode(root->rightChild);
			root->data = node->data;
			root->rightChild = deleteNode(root->rightChild, node->data);
		}
		else {
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
			free(root);
			return node;
		}
	}
	return root;
}

int main(void) {
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	root = deleteNode(root, 30);
	preorder(root);
	system("pause");
}