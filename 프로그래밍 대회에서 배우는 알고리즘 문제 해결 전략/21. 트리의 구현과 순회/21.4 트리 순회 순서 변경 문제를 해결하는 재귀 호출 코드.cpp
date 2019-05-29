//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//struct TreeNode {
//	string label;	//������ �ڷ� (���� �� ���ڿ��� �ʿ�� ����.)
//	TreeNode* parent;	//�θ� ��带 ����Ű�� ������
//	vector<TreeNode*> children;	//�ڼ� ������ ����Ű�� �������� �迭
//};
//
////�־��� Ʈ���� �� ��忡 ����� ���� ��� ����Ѵ�.
//void printLabels(TreeNode* root) {
//	//��Ʈ�� ����� ���� ����Ѵ�.
//	cout << root->label << endl;
//	//�� �ڼյ��� ��Ʈ�� �ϴ� ����Ʈ���� ���Ե� ������ ��������� ȣ���Ѵ�.
//	for (int i = 0; i < root->children.size(); i++)
//		printLabels(root->children[i]);
//}
//
////root�� ��Ʈ�� �ϴ� Ʈ���� ���̸� ���Ѵ�.
//int height(TreeNode* root) {
//	int h = 0;
//	for (int i = 0; i < root->children.size(); i++)
//		h = max(h, 1 + height(root->children[i]));
//	return h;
//}
//
//vector<int> slice(const vector<int>& v, int a, int b) {
//	return vector<int>(v.begin() + a, v.begin() + b);
//}
//
////Ʈ���� ����Ž�� ����� ����Ž�� ����� �־��� �� ����Ž�� ����� ����Ѵ�.
//void printpostOrder(const vector<int>& preorder, const vector<int>& inorder) {
//	//Ʈ���� ���Ե� ����� ��
//	const int N = preorder.size();
//	//���� ���:�� �� Ʈ���� ���� ����
//	if (preorder.empty()) return;
//	//�� Ʈ���� ��Ʈ�� ���� Ž�� ����κ��� ���� �� �� �ִ�.
//	const int root = preorder[0];
//	//�� Ʈ���� ���� ����Ʈ���� ũ��� ���� Ž�� ������� ��Ʈ�� ��ġ�� ã�Ƽ� �� �� �ִ�.
//	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
//	//������ ����Ʈ���� ũ��� N���� ���� ����Ʈ���� ��Ʈ�� ���� �� �� �ִ�.
//	const int R = N - 1 - L;
//	//���ʰ� ������ ����Ʈ���� ��ȸ ����� ���
//	printpostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
//	printpostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
//	//���� ��ȸ�̹Ƿ� ��Ʈ�� ���� �������� ����Ѵ�.
//	cout << root << ' ';
//}