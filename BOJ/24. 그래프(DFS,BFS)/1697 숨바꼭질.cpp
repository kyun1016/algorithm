//#include<iostream>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//
//deque<pair<int, int> > V;
//bool visited[200001];
//int N, K;
//
//int bfs() {
//	while (!V.empty()) {
//		pair<int, int> here = V.front();
//		V.pop_front();
//
//		if (here.first == K)
//			return here.second;
//
//		if (here.first * 2 <= K * 2 && !visited[here.first * 2]) {
//			V.push_back({ here.first * 2, here.second + 1 });
//			visited[here.first * 2] = true;
//		}
//		if (here.first + 1 <= K * 2 && !visited[here.first + 1]) {
//			V.push_back({ here.first + 1, here.second + 1 });
//			visited[here.first + 1] = true;
//		}
//		if (here.first > 0 && !visited[here.first - 1]) {
//			V.push_back({ here.first - 1, here.second + 1 });
//			visited[here.first - 1] = true;
//		}
//	}
//}
//
//int main() {
//	cin >> N >> K;
//
//	memset(visited, false, sizeof(visited));
//	V.push_back({ N,0 });
//
//	cout << bfs() << endl;
//}