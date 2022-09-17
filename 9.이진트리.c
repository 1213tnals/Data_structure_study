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

//1.����Ʈ���� ���� ��ȸ
void preorder(Node* root) {
	if (root) {   //��Ʈ�� �� ���� �ƴϸ� ��������� �۵�
		printf("%d ", root->data); //����ϰ� �̵�
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

//2.����Ʈ���� ���� ��ȸ
void inorder(Node* root) {
	if (root) {
		inorder(root->leftChild);
		printf("%d ", root->data); //�������� �̵��ϰ� ���
		inorder(root->rightChild);
	}
}

//3.����Ʈ���� ���� ��ȸ
void postorder(Node* root) {
	if (root) {
		preorder(root->leftChild);
		preorder(root->rightChild);
		printf("%d ", root->data); //�̵� �� �ϰ� ���
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