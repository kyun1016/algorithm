#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, a, b, c;
int cost[101][101];
int route[101][101];
const int INF = 987654321;
vector<int> V;

void find_route(const int& start, const int& end) {
	if (route[start][end] == 0) {
		V.push_back(start);
		V.push_back(end);
		return;
	}
	find_route(start, route[start][end]);
	V.pop_back();
	find_route(route[start][end], end);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//input
	cin >> N >> M;
	//초기화
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			cost[i][j] = INF;
	//for (int i = 0; i <= N; i++)
	//	cost[i][i] = 0;
	//input
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}

	//floyd_warshall 알고리즘 적용
	for(int mid = 1;mid <= N; mid++)
		for(int start = 1; start<= N; start++)
			for (int end = 1; end <= N; end++) {
				if (start == end) continue;
				if (cost[start][end] > cost[start][mid] + cost[mid][end]) {
					cost[start][end] = cost[start][mid] + cost[mid][end];
					route[start][end] = mid;
				}
			}
				
	for (int start = 1; start <= N; start++) {
		for (int end = 1; end <= N; end++) {
			if (cost[start][end] == INF)
				cout << "0 ";
			else
				cout << cost[start][end] << " ";
		}
		cout << '\n';
	}
	for (int start = 1; start <= N; start++) {
		for (int end = 1; end <= N; end++) {
			if (cost[start][end] == INF)
				cout << "0";
			else {
				V.clear();
				find_route(start, end);
				cout << V.size() << " ";
				for (auto a : V)
					cout << a << " ";
			}
			cout << '\n';
		}
	}
			
	return 0;
}