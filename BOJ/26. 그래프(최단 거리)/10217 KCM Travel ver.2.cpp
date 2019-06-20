#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>


using namespace std;

//�տ��� ���� ����, �ڴ� cost
vector<pair<int, pair<int, int> > > idx[101];
const int INF = 1000000007;
int timeDelay[101][10001];

void dijkstra(const int& N, const int& MAX_COST) {
	//memset(timeDelay, -1, sizeof(timeDelay));

	//Ȥ�� ó���� INF�� ������ �����Ѱ�?
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 10000; j++)
			timeDelay[i][j] = INF;
	}
	/*vector<int> dist(N + 1, INF);
	dist[1] = 0;*/
	timeDelay[1][0] = 0;
	//ó���� time, second.first=cost, second.second ���� ��ġ
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
			
			//���� �ִ� ����� �ʰ��ϴ� ������ ���´ٸ�, �н��Ѵ�.
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

	//T=�׽�Ʈ ���̽� ��, N=������ ��, M=���� ���, K=Ƽ�������� ��
	int T, N, M, K;
	//u=��߰���, v=��������, c=���, d=�ҿ�ð�
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