#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<pair<int, int> > adj[801];
const int INF =987654321;
//bool Possible;

int Distance[5];

//벨만-포드 방식
vector<int> shortestLength(int N, int viaA, int viaB, int src) {
	/*if (!Possible)
		return;*/
	vector<int> upper(N + 1, INF);
	bool updated = false;
	upper[src] = 0;
	for (int iter = 0; iter < N; iter++) {
		updated = false;
		for (int here = 1; here <= N; here++) 
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				//더 짧은 거리로 수정한다.
				if (upper[there] > upper[here] + cost) {
					updated = true;
					upper[there] = upper[here] + cost;
				}
			}
		//만일 이번 차례에 단축이 되지 않았다면, 반복을 종료
		if (!updated)
			break;
		
	}

	//if (src == 1) {
	//	Distance[0] = upper[viaA];
	//	Distance[1] = upper[viaB];
	//}
	//else if (src == viaA) {
	//	Distance[4] = upper[viaB];
	//}
	//else if(src == N){
	//	Distance[2] = upper[viaA];
	//	Distance[3] = upper[viaB];
	//}
	return upper;
}



//다익스트라
bool visited[20001];


vector<int> dijkstra(int N, int src) {
	vector<int> dist(N+1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
		if (dist[here] < cost) continue;
		//인접한 정점들을 모두 검사한다.
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			//더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}



int main() {
	int N, E;
	int a, b, cost;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> cost;
		adj[a].push_back({ b,cost });
		adj[b].push_back({ a,cost });
	}
	
	/*int node1, node2;

	cin >> node1 >> node2;



	vector<int> result = dijkstra(N, 1);

	vector<int> temp1 = dijkstra(N, node1);

	vector<int> temp2 = dijkstra(N, node2);*/

	////두 가지 경우

	////1. 1 -> node1 -> node2 -> N

	////2. 1 -> node2 -> node1 -> N

	//int answer = min({ result[node1] + temp1[node2] + temp2[N], result[node2] + temp2[node1] + temp1[N] });

	//if (answer >= INF || answer < 0)

	//	cout << -1 << "\n";

	//else

	//	cout << answer << "\n";

	//return 0;

	int viaA, viaB;
	cin >> viaA >> viaB;

	vector<int> v1 = shortestLength(N, viaA, viaB, 1);
	vector<int> v2 = shortestLength(N, viaA, viaB, viaA);
	vector<int> v3 = shortestLength(N, viaA, viaB, viaB);

	int ret = 0;
	ret = min(v1[viaA] + v2[viaB] + v3[N], v1[viaB] + v3[viaA] + v2[N]);
	if (ret >= INF || ret < 0)
		cout << -1 << endl;
	else
		cout << ret << endl;
	

	return 0;
}