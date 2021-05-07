#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

vector<pair<int, pair<int, int> > > VPIPII[101];
int T, N, M, K, u, v, c, d;
int time_cost[101][10001];			//time_cost[현재위치, 자원비용] = 소요시간
const int INF = 987654321;

int main() {
	//input
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			cin >> u >> v >> c >> d;
			VPIPII[u].push_back({ v,{c,d} });
		}
		//초기화
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= M; j++)
				time_cost[i][j] = INF;			

		time_cost[1][0] = 0;
		//{비용,{시간, 위치}}
		priority_queue<pair<int, pair<int, int> > > pq;
		pq.push({ 0,{0, 1} });
		while (!pq.empty()) {
			auto temp = pq.top();
			int cost = -temp.first;
			int time = temp.second.first;
			int here = temp.second.second;
			pq.pop();
			//기저사례 : 더 적은 비용과 시간으로 도달이 가능한 경우 생략
			if (time_cost[here][cost] < time)
				continue;
			
			for (int i = 0; i < VPIPII[here].size(); i++) {
				//데이터 정리
				int next_cost = cost + VPIPII[here][i].second.first;
				int next_time = time + VPIPII[here][i].second.second;
				int there = VPIPII[here][i].first;
				
				if (next_cost > M)
					continue;

				// 더 적은 비용으로 갱신
				if (time_cost[there][next_cost] > next_time) {
					for (int i = next_cost; i <= M; i++)
						if (time_cost[there][i] > next_time)
							time_cost[there][i] = next_time;
					//갱신 이후 pq에 push
					pq.push({ -next_cost,{next_time, there} });
				}
			}
		}

		int ret = INF;
		for (int i = 1; i <= M; i++) 
			ret = min(time_cost[N][i], ret);
		
		if (ret == INF)
			cout << "Poor KCM\n";
		else
			cout << ret << '\n';
		
		for (int i = 0; i <= N; i++) {
			VPIPII[i].clear();
		}
	}

	return 0;
}