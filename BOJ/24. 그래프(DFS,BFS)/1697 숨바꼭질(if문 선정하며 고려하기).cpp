//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int N, K, visited[200005];
//queue<pair<int, int> > pq;
//
//int main() {
//	cin >> N >> K;
//
//	if (N == K) {
//		cout << 0 << '\n';
//		return 0;
//	}
//	visited[N] = 1;
//	pq.push({ 0,N });
//
//	while (!pq.empty()) {
//		if (visited[K] != 0) {
//			cout << visited[K] << '\n';
//			return 0;
//		}
//		int depth = -pq.front().first + 1, here = pq.front().second;
//		pq.pop();
//
//		if (here > 0 && visited[here - 1] == 0) {
//			visited[here - 1] = depth;
//			pq.push({ -depth,here - 1 });
//		}
//
//		if (here < K && visited[here + 1] == 0) {
//			visited[here + 1] = depth;
//			pq.push({ -depth,here + 1 });
//		}
//		if (here < K && visited[here * 2] == 0) {
//			visited[here * 2] = depth;
//			pq.push({ -depth,here * 2 });
//		}
//	}
//
//	return 0;
//}