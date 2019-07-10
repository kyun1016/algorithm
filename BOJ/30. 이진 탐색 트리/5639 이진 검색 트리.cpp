////#include<iostream>
////#include<algorithm>
////
////using namespace std;
////
////struct Node {
////	int value, depth;
////	//�� �ڽ� ����� ������
////	Node* left, *right;
////	Node(const int& _value) : value(_value), depth(0), left(NULL), right(NULL) { }
////	void setLeft(Node* newLeft) { left = newLeft;}
////	void setRight(Node* newRight) { right = newRight;}
////};
////
////Node* insert(Node* root, Node* node) {
////	if (root == NULL) return node;
////	if (node->value < root->value)
////		root->setLeft(insert(root->left, node));
////	else
////		root->setRight(insert(root->right, node));
////	return root;
////}
////
////void printNode(Node* node) {
////	if (node->left != NULL)
////		printNode(node->left);
////	if (node->right != NULL)
////		printNode(node->right);
////	printf("%d\n", node->value);
////	
////}
////
////int main() {
////	int temp;
////	Node* Nodes = NULL;
////	while(scanf("%d", &temp) != EOF) {
////		Nodes = insert(Nodes, new Node(temp));
////	}
////	printNode(Nodes);
////
////}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int Arr[10002];
//
//void printNode(const int& left, const int& right) {
//	if (left > right) return;
//	
//	int root = Arr[left];
//	int last = right;
//	while (Arr[last] > root) last--;
//	//Arr[left]�� �θ� ���� �ϰ� �� ������ ������.
//	//���� ��尡 �ǰ�
//	printNode(left + 1, last);
//	//������ ��尡 �ȴ�.
//	printNode(last + 1, right);
//	//�ڽ��� ���������.
//	printf("%d\n", root);
//}
//
//int main() {
//	int temp;
//	int N = 0;
//	while (scanf("%d", &temp) != -1) Arr[N++] = temp;
//	printNode(0, N-1);
//
//	return 0;
//}
