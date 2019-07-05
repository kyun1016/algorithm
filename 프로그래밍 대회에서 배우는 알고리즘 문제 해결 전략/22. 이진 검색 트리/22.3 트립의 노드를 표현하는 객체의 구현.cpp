//#include<iostream>
//
//using namespace std;
//
//typedef int KeyType;
//
//struct Node {
//	//노드에 저장된 원소
//	KeyType key;
//	//이 노드의 우선순위(priority)
//	//이 노드를 루트로 하는 서브트리의 크기(size)
//	int priority, size;
//	//두 자식 노드의 포인터
//	Node* left, * right;
//	//생성자에서 난수 우선순위를 생성하고, size와 left/right를 초기화한다.(초기화 리스트 : initialize list
//	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) { }
//	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
//	void setRight(Node* newRight) { right = newRight; calcSize(); }
//	//size 멤버를 갱신한다.
//	void calcSize() {
//		size = 1;
//		if (left) size += left->size;
//		if (right) size += right->size;
//	}
//};
//
//
//
//////22.4 트립에서의 노드 추가와 트립 쪼개기 연산의 구현
//typedef pair<Node*, Node*> NodePair;
////root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는
////두 개의 트립으로 분리한다.
//NodePair split(Node* root, KeyType key) {
//	if (root == NULL) return NodePair(NULL, NULL);
//	//루트가 key 미만이면 오른쪽 서브트리를 쪼갠다.
//	if (root->key < key) {
//		NodePair rs = split(root->right, key);
//		root->setRight(rs.first);
//		return NodePair(root, rs.second);
//	}
//	//루트가 key 이상이면 왼쪽 서브트리를 쪼갠다.
//	NodePair ls = split(root->left, key);
//	root->setLeft(ls.second);
//	return NodePair(ls.first, root);
//}
////root를 루트로 하는 트립에 새 노드 node를 삽입한 뒤 결과 트립의
////루트를 반환한다.
//Node* insert(Node* root, Node* node) {
//	if (root == NULL) return node;
//	//node가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라
//	//각각 자손으로 한다.
//	if (root->priority < node->priority) {
//		NodePair splitted = split(root, node->key);
//		node->setLeft(splitted.first);
//		node->setRight(splitted.second);
//		return node;
//	}
//	else if (node->key < root->key)
//		root->setLeft(insert(root->left, node));
//	else
//		root->setRight(insert(root->right, node));
//	return root;
//}
//
//
//
//////22.5 트립에서 노드의 삭제와 합치기 연산의 구현
//
////a와 b가 두 개의 트립이고, max(a) < min(b)일 때 이 둘을 합친다.
//Node* merge(Node* a, Node* b) {
//	if (a == NULL) return b;
//	if (b == NULL) return a;
//	if (a->priority < b->priority) {
//		b->setLeft(merge(a, b->left));
//		return b;
//	}
//	a->setRight(merge(a->right, b));
//	return a;
//}
////root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다.
//Node* erase(Node* root, KeyType key) {
//	if (root == NULL) return root;
//	//root를 지우고 양 서브트리를 합친 뒤 반환한다.
//	if (root->key == key) {
//		Node* ret = merge(root->left, root->right);
//		delete root;
//		return ret;
//	}
//	if (key < root->key)
//		root->setLeft(erase(root->left, key));
//	else
//		root->setRight(erase(root->right, key));
//	return root;
//}
//
//
//
//////코드 22.6 트립에서 k번째 원소를 찾는 알고리즘의 구현
//
////root를 루트로 하는 트리 중에서 k번째 원소를 반환한다.
//Node* kth(Node* root, int k) {
//	//왼쪽 서브트리의 크기를 우선 계산한다.
//	int leftSize = 0;
//	if (root->left != NULL) leftSize = root->left->size;
//	if (k <= leftSize) return kth(root->left, k);
//	if (k == leftSize + 1) return root;
//	return kth(root->right, k - leftSize - 1);
//}
//
//
//////코드 22.7 트립에서 X보다 작은 원소의 수를 찾는 알고리즘의 구현
//
////key보다 작은 키값의 수를 반환한다.
//int countLessThan(Node* root, KeyType key) {
//	if (root == NULL) return 0;
//	if (root->key >= key)
//		return countLessThan(root->left, key);
//	int ls = (root->left ? root->left->size : 0);
//	return ls + 1 + countLessThan(root->right, key);
//}
//
//
//////코드 22.8 삽입 정렬 뒤집기 문제를 해결하는 알고리즘
//
////shifted[i]=A[i]가 왼쪽으로 몇 칸 움직이는가?
//int n, shifted[50000];
//int A[50000];
////n,shifted[]를 보고 A[]에 값을 저장한다.
//void solve() {
//	//1~N까지의 숫자를 모두 저장하는 트립을 만든다.
//	Node* candidates = NULL;
//	for (int i = 0; i < n; i++)
//		candidates = insert(candidates, new Node(i + 1));
//	//뒤에서부터 A[]를 채워나간다.
//	for (int i = n - 1; i >= 0; i--) {
//		//후보 중 이 수보다 큰 수가 larger개 있다.
//		int larger = shifted[i];
//		Node* k = kth(candidates, i + 1 - larger);
//		A[i] = k->key;
//		candidates = erase(candidates, k->key);
//	}
//
//	
//}
