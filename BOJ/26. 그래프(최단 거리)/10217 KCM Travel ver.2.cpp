#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>


using namespace std;

//앞에는 다음 공항, 뒤는 cost
vector<pair<int, pair<int, int> > > idx[101];
const int INF = 1000000007;
int timeDelay[101][10001];

void dijkstra(const int& N, const int& MAX_COST) {
	//memset(timeDelay, -1, sizeof(timeDelay));

	//혹시 처음에 INF로 설정이 가능한가?
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 10000; j++)
			timeDelay[i][j] = INF;
	}
	/*vector<int> dist(N + 1, INF);
	dist[1] = 0;*/
	timeDelay[1][0] = 0;
	//처음은 time, second.first=cost, second.second 현재 위치
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({ 0, {0, 1} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int time = pq.top().second.first;
		int here = pq.top().second.second;
		pq.pop();
		if (timeDelay[here][cost] < time)
			continue;
		for (int i = 0; i < idx[here].size(); i++) {
			int nextCost = cost + idx[here][i].second.first;
			int there = idx[here][i].first;
			int nextTime = time + idx[here][i].second.second;
			
			//만일 최대 비용을 초과하는 가격이 나온다면, 패스한다.
			if (nextCost > MAX_COST)
				continue;

			//if (timeDelay[there][nextCost] == -1) {
			//	timeDelay[there][nextCost] = nextTime;
			//	//cout << there << " " << nextCost << " " << nextTime << endl;
			//	pq.push({ -nextCost, {nextTime, there} });
			//}
			//else 
			if (timeDelay[there][nextCost] > nextTime) {
				for (int i = nextCost; i <= MAX_COST; i++) {
					if (timeDelay[there][i] > nextTime)
						timeDelay[there][i] = nextTime;
				}
				//cout << there << " "<< nextCost << " " << nextTime << endl;
				pq.push({ -nextCost, {nextTime, there} });
			}

			/*if (nextCost > MAX_COST || dist[there] < nextTime)
				continue;
			else {
				dist[there] = nextTime;
				pq.push({ -nextCost, {nextTime, there} });
			}*/
		}
	}
	int ret = INF;
	for (int i = 1; i <= MAX_COST; i++) {
		if (timeDelay[N][i] == INF)
			continue;
		ret = min(ret, timeDelay[N][i]);
		//cout << "cost : " << i << "   : " <<ret << endl;
	}
	if (ret == INF)
		cout << "Poor KCM" << endl;
	else
		cout << ret << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//T=테스트 케이스 수, N=공항의 수, M=지원 비용, K=티켓정보의 수
	int T, N, M, K;
	//u=출발공항, v=도착공항, c=비용, d=소요시간
	int u, v, c, d;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) {
			while (!idx[i].empty())
				idx[i].pop_back();
		}
		for (int i = 0; i < K; i++) {
			cin >> u >> v >> c >> d;
			idx[u].push_back({ v, {c, d} });
		}
		dijkstra(N, M);
	}
	


	return 0;
}