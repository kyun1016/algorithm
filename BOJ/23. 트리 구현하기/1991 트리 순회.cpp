//#include<iostream>
//
//using namespace std;
//
//class TreeNode {
//private:
//	char data;
//	TreeNode* left;
//	TreeNode* right;
//public:
//	TreeNode(char data) {
//		this->data = data;
//
//	}
//
//	//TreeNode makeBT(char bt1, char data, char bt2) {
//	//	/*TreeNode root = new TreeNode();*/
//	//	root.data = data;
//	//	root.left = bt1;
//	//	root.right = bt2;
//	//	return root;
//	//}
//
//	void preorder(TreeNode root) {
//		if (root.data != NULL) {
//			cin << root.data;
//			preorder(root.left);
//			preorder(root.right);
//		}
//	}
//
//	void inorder(TreeNode root) {
//		if (root != null) {
//			inorder(root.left);
//			cin << root.data
//			inorder(root.right);
//		}
//	}
//
//	void postorder(TreeNode root) {
//		if (root != null) {
//			postorder(root.left);
//			postorder(root.right);
//			System.out.printf("%c", root.data);
//		}
//	}
//};


//#include<iostream>
//
//using namespace std;
//
//char treeNode[26][3];
//int N;
//
//void preorder(char rootID) {
//	cout << rootID;
//	int key;
//	//rootID가 몇번째 순서에 있는지 찾는다.
//	for (int i = 0; i < N; i++) {
//		if (treeNode[i][0] == rootID) {
//			key = i;
//			break;
//		}
//	}
//	if (treeNode[key][1] != '.') 
//		preorder(treeNode[key][1]);
//
//	if (treeNode[key][2] != '.')
//		preorder(treeNode[key][2]);
//}
//void inorder(char rootID) {
//	
//	int key;
//	//rootID가 몇번째 순서에 있는지 찾는다.
//	for (int i = 0; i < N; i++) {
//		if (treeNode[i][0] == rootID) {
//			key = i;
//			break;
//		}
//	}
//	if (treeNode[key][1] != '.')
//		inorder(treeNode[key][1]);
//
//	cout << rootID;
//
//	if (treeNode[key][2] != '.')
//		inorder(treeNode[key][2]);
//}
//void postorder(char rootID) {
//	int key;
//	//rootID가 몇번째 순서에 있는지 찾는다.
//	for (int i = 0; i < N; i++) {
//		if (treeNode[i][0] == rootID) {
//			key = i;
//			break;
//		}
//	}
//	if (treeNode[key][1] != '.')
//		postorder(treeNode[key][1]);
//
//	if (treeNode[key][2] != '.')
//		postorder(treeNode[key][2]);
//
//	cout << rootID;
//}

#include<iostream>

using namespace std;

char treeNode[26][3];
int key[26];
int N;

void preorder(int root) {
	//우선 root를 출력한다.
	cout << treeNode[root][0];
	//좌측 가지를 확인한다.
	if (treeNode[root][1] != '.')
		preorder(key[treeNode[root][1] - 'A']);
	//우측 가지를 확인한다.
	if (treeNode[root][2] != '.')
		preorder(key[treeNode[root][2] - 'A']);
}

void inorder(int root) {
	if (treeNode[root][1] != '.')
		inorder(key[treeNode[root][1] - 'A']);
	cout << treeNode[root][0];
	if (treeNode[root][2] != '.')
		inorder(key[treeNode[root][2] - 'A']);
}
void postorder(int root) {
	if (treeNode[root][1] != '.')
		postorder(key[treeNode[root][1] - 'A']);
	if (treeNode[root][2] != '.')
		postorder(key[treeNode[root][2] - 'A']);
	cout << treeNode[root][0];
}

int main() {
	
	char temp_root, temp_left, temp_right;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int t = 0; t < 3; t++) {
			cin >> treeNode[i][t];
		}
		key[treeNode[i][0] - 'A'] = i;
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
}
