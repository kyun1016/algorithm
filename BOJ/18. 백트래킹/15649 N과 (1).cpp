//#include<iostream>
//
//using namespace std;
//
//int N, M;
//int arr[10];
//bool visited[10];
//
//void dfs(const int& length) {
//	if (length == M) {
//		for (int i = 0; i < M; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << "\n";
//		return;
//	}
//
//	for (int i = 1; i <= N; i++) {
//		if (visited[i])
//			continue;
//		visited[i] = true;
//		arr[length] = i;
//		dfs(length + 1);
//		visited[i] = false;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> M;
//
//	for (int i = 1; i <= N; i++) {
//		visited[i] = true;
//		arr[0] = i;
//		dfs(1);
//		visited[i] = false;
//	}
//
//	return 0;
//}