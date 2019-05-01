////#include<iostream>
////#include<vector>
////#include<algorithm>
////
////using namespace std;
////
////vector<int> postorder, inorder;
////
////
//////struct TreeNode {
//////	string label;	//������ �ڷ� (���� �� ���ڿ��� �ʿ�� ����.)
//////	TreeNode* parent;	//�θ� ��带 ����Ű�� ������
//////	vector<TreeNode*> children;	//�ڼ� ������ ����Ű�� �������� �迭
//////};
////
////////�־��� Ʈ���� �� ��忡 ����� ���� ��� ����Ѵ�.
//////void printLabels(TreeNode* root) {
//////	//��Ʈ�� ����� ���� ����Ѵ�.
//////	cout << root->label << endl;
//////	//�� �ڼյ��� ��Ʈ�� �ϴ� ����Ʈ���� ���Ե� ������ ��������� ȣ���Ѵ�.
//////	for (int i = 0; i < root->children.size(); i++)
//////		printLabels(root->children[i]);
//////}
////
////////root�� ��Ʈ�� �ϴ� Ʈ���� ���̸� ���Ѵ�.
//////int height(TreeNode* root) {
//////	int h = 0;
//////	for (int i = 0; i < root->children.size(); i++)
//////		h = max(h, 1 + height(root->children[i]));
//////	return h;
//////}
////
////vector<int> slice(const vector<int>& v, int a, int b) {
////	return vector<int>(v.begin() + a, v.begin() + b);
////}
////
////////Ʈ���� ����Ž�� ����� ����Ž�� ����� �־��� �� ����Ž�� ����� ����Ѵ�.
//////void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
//////	//Ʈ���� ���Ե� ����� ��
//////	const int N = preorder.size();
//////	//���� ���:�� �� Ʈ���� ���� ����
//////	if (preorder.empty()) return;
//////	//�� Ʈ���� ��Ʈ�� ���� Ž�� ����κ��� ���� �� �� �ִ�.
//////	const int root = preorder[0];
//////	//�� Ʈ���� ���� ����Ʈ���� ũ��� ���� Ž�� ������� ��Ʈ�� ��ġ�� ã�Ƽ� �� �� �ִ�.
//////	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
//////	//������ ����Ʈ���� ũ��� N���� ���� ����Ʈ���� ��Ʈ�� ���� �� �� �ִ�.
//////	const int R = N - 1 - L;
//////	//���ʰ� ������ ����Ʈ���� ��ȸ ����� ���
//////	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
//////	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
//////	//���� ��ȸ�̹Ƿ� ��Ʈ�� ���� �������� ����Ѵ�.
//////	cout << root << ' ';
//////}
////
//////Ʈ���� ����Ž�� ����� ����Ž�� ����� �־��� �� ����Ž�� ����� ����Ѵ�.
////void printPreOrder(const int inorderStart, const int inorderEnd, const int postorderStart, const int postorderEnd) {
////	////Ʈ���� ���Ե� ����� ��
////	const int N = postorderEnd - postorderStart;
////	const int inN = inorderEnd- inorderStart;
////	////���� ���:�� �� Ʈ���� ���� ����
////	
////	//�� Ʈ���� ��Ʈ�� ���� Ž�� ����κ��� ���� �� �� �ִ�.
////	const int root = postorder[postorderEnd-1];
////	if (postorderEnd - postorderStart == 1) {
////		cout << root << ' ';
////		return;
////	}
////	/*const int root = postorder[N - 1];
////	if (N == 1) {
////		cout << root << ' ';
////		return;
////	}*/
////	//�� Ʈ���� ���� ����Ʈ���� ũ��� ���� Ž�� ������� ��Ʈ�� ��ġ�� ã�Ƽ� �� �� �ִ�.
////	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
////	//���� ��ȸ�̹Ƿ� ��Ʈ�� ���� ���� ����Ѵ�.
////	cout << root << ' ';
////	//���ʰ� ������ ����Ʈ���� ��ȸ ����� ���
////
////
////	printPreOrder(inorderStart, L, postorderStart, postorderStart + L);
////	printPreOrder(L+2, inorderEnd, postorderStart + L+1, postorderEnd-1);
////
////
////	//printPreOrder(slice(inorder, 0, L), slice(postorder, 0, R+1));
////	//printPreOrder(slice(inorder, L + 1, inN), slice(postorder, R+1, N-1));
////	
////}
////
////int main() {
////	int N,temp;
////	cin >> N;
////
////	for (int i = 0; i < N; i++) {
////		cin >> temp;
////		inorder.push_back(temp);
////	}
////	for (int i = 0; i < N; i++) {
////		cin >> temp;
////		postorder.push_back(temp);
////	}
////	printPreOrder(0,N, 0,N);
////}
//
//#include <iostream>
//using namespace std;
//
//int postOrder[100001];
//int inOrder[100001];
//int find_root[100001];
//int n;
//void func(int s, int e, int s2, int e2) {
//	if (s > e) return;
//	int root = postOrder[e2];
//	cout << root << " ";
//	int pos = find_root[root];
//	func(s, pos - 1, s2, s2 + (pos - 1 - s));
//	func(pos + 1, e, s2 + pos - s, e2 - 1);
//	return;
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		cin >> inOrder[i];
//		find_root[inOrder[i]] = i;
//	}
//	for (int i = 0; i < n; ++i) cin >> postOrder[i];
//	func(0, n - 1, 0, n - 1);
//}
//
