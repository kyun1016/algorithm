//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////인접한 자식 노드를 담는 배열을 만들자.
//vector<pair<int, int> > adj;
//
//int i = 1;
////순서와 깊이를 저장한다.
////bool order[10001][10001];
//pair<int, int> MinMax[10001];
//
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//
//int findRoot(int N) {
//	vector<bool> isRoot(N + 1, true);
//	for (int i = 1; i <= N; i++) {
//		if (adj[i].first != -1)
//			isRoot[adj[i].first] = false;
//		if (adj[i].second != -1)
//			isRoot[adj[i].second] = false;
//	}
//	for (int i = 1; i <= N; i++)
//		if (isRoot[i])
//			return i;
//}
//
//void findLargeNum(int here = 1, int depth = 1) {
//	bool check = true;
//	if (adj[here].first == -1) {
//		if (MinMax[depth].first > i || MinMax[depth].first == 0)
//			MinMax[depth].first = i;
//		if (MinMax[depth].second < i || MinMax[depth].second == 0)
//			MinMax[depth].second = i;
//		//order[depth][i++] = true;
//		i++;
//		check = false;
//	}
//	else {
//		findLargeNum(adj[here].first, depth + 1);
//	}
//
//
//	if (check) {
//		if (MinMax[depth].first > i || MinMax[depth].first == 0)
//			MinMax[depth].first = i;
//		if (MinMax[depth].second < i || MinMax[depth].second == 0)
//			MinMax[depth].second = i;
//		i++;
//		//order[depth][i++] = true;
//	}
//
//
//	if (adj[here].second != -1)
//		findLargeNum(adj[here].second, depth + 1);
//
//}
//
//int main() {
//	int N, a, b, c;
//	int maxLength = 0, maxDepth;
//	cin >> N;
//	//빈 공간을 하나 넣어준다.
//	adj.push_back({ 0,0 });
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b >> c;
//		adj.push_back({ b,c });
//	}
//
//	int root;
//
//	root = findRoot(N);
//
//	findLargeNum(root, 1);
//
//	for (int i = 1; i <= N; i++) {
//		if (maxLength < MinMax[i].second - MinMax[i].first + 1) {
//			maxLength = MinMax[i].second - MinMax[i].first + 1;
//			maxDepth = i;
//		}
//	}
//	cout << maxDepth << " " << maxLength;
//}