//#include<iostream>
//#include<vector>
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