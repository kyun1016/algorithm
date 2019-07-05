////ver 1
//
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//typedef int KeyType;
//int ret = 0;
//pair<int, int> helloNode[300001];
//
////struct Node {
////	int value, depth;
////	//두 자식 노드의 포인터
////	Node* left, *right;
////	Node(const int& _value) : value(_value), depth(0), left(NULL), right(NULL) { }
////	void setLeft(Node* newLeft) { left = newLeft;}
////	void setRight(Node* newRight) { right = newRight;}
////};
////
////typedef pair<Node*, Node*> NodePair;
////
////Node* insert(Node* root, Node* node) {
////	if (root == NULL) return node;
////	ret++;
////	if (node->value < root->value)
////		root->setLeft(insert(root->left, node));
////	else
////		root->setRight(insert(root->right, node));
////	return root;
////}
//
//void insert(const int& N) {
//	if (ret == 0) {
//		helloNode[N].first = 1;
//		helloNode[N].second = 0;
//	}
//	else {
//		int min = N, max = N;
//		while (helloNode[--min].first == 0&& min > 0);
//		while (helloNode[++max].first == 0 && max < 300001);
//		if()
//		
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N, temp;
//	cin >> N;
//	/*Node* Nodes = NULL;
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		Nodes = insert(Nodes, new Node(temp));
//		cout << ret << "\n";
//	}*/
//	for (int i = 0; i < N; i++) {
//		/*cin >> temp;*/
//		cout << helloNode[0].first << endl;
//	}
//
//
//}
//
////
//////ver 2
////#include <stdio.h>
////#include <map>
////#include <vector>
////#include <algorithm>
////#include <string>
////using namespace std;
////
////
////
////void insert(map<int, long long int>& v, vector<long long int>& sum, int x)
////{
////	map<int, long long int>::iterator lower_bound;
////	map<int, long long int>::iterator upper_bound;
////
////
////
////	lower_bound = --v.lower_bound(x);
////	upper_bound = v.upper_bound(x);
////	long long int count = 0;
////	count = max(lower_bound->second, upper_bound->second) + 1;
////	v.insert(pair<int, long long int>{x, count});
////	if (sum.size() > 1)
////	{
////		sum.push_back(sum[sum.size() - 1] + count);
////	}
////	else
////	{
////		sum.push_back(count);
////	}
////	return;
////}
////
////
////int main()
////{
////	map<int, long long int> tree;
////	tree.insert(pair<int, long long int>{0, -1});
////	tree.insert(pair<int, long long int>{300001, -1});
////	int n;
////	int m;
////	vector<long long int>sum;
////	scanf("%d", &n);
////	while (n--)
////	{
////		scanf("%d", &m);
////		insert(tree, sum, m);
////	}
////
////	for (long long int x : sum)
////	{
////		printf("%lld\n", x);
////	}
////
////
////}


#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, long long int> MapArr;
map<int, long long int>::iterator Lower_bound;
map<int, long long int>::iterator Upper_bound;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, temp;
	long long int ret = 0;

	MapArr.insert(pair<int, long long int>(0, -1));
	MapArr.insert(pair<int, long long int>(300001, -1));
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		long long int dep = 0;
		Lower_bound = (--MapArr.lower_bound(temp));
		Upper_bound = (MapArr.upper_bound(temp));
		dep = max(Lower_bound->second, Upper_bound->second) + 1;
		MapArr.insert(pair<int, long long int>(temp, dep));
		ret += dep;
		cout << ret << "\n";
	}

	return 0;
}