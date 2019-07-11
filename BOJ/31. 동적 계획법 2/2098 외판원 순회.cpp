
////시간초과에 걸리는 brute force형식
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int dist[16][16];
//bool visited[16];
//int N;
//int INF = 1000000007;
//
//int dp(vector<int>& path, int adj = 0) {
//	if (path.size() == N)
//		return adj + dist[path.back()][path[0]];
//
//	int ret = INF;
//	for (int i = 0; i < N; i++) {
//		if (visited[i])
//			continue;
//		int here = path.back();
//		if (dist[here][i] == 0)
//			continue;
//		visited[i] = true;
//		path.push_back(i);
//		ret = min(ret , dp(path, adj + dist[here][i]));
//		visited[i] = false;
//		path.pop_back();
//	}
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> dist[i][j];
//		}
//	}
//	vector<int> a;
//	int ret = INF;
//	for (int i = 0; i < N; i++) {
//		a.push_back(i);
//		visited[i] = true;
//		ret = min(dp(a), ret);
//		a.pop_back();
//		visited[i] = false;
//	}
//	cout << ret << endl;
//
//	return 0;
//}


//동적계획법을 활용한 외판원 순회
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dist[16][16];
int cache[16][1<<16];
int N;
int INF = 1000000007;

int dp(int here, int start, int visited) {
	
	if (visited == (1 << N) - 1) {
		if (dist[here][start] != 0)
			return dist[here][start];
		else
			return INF;
	}
		
	
	int& ret = cache[here][visited];
	if (ret > 0)
		return ret;

	ret = INF;
	for (int next = 0; next < N; next++) {
		if (visited & (1<<next) || dist[here][next] == 0)
			continue;
		ret = min(ret, dist[here][next] + dp(next, start, visited + (1<<next)));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}
	int ret = INF;
	/*for (int i = 0; i < N; i++) {
		ret = min(ret ,dp(i, i, (1<<i)));
		cout << ret << endl;
	}*/

	cout << dp(0,0,1) << endl;

	return 0;
}

