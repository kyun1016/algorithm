//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, E;
//const int INF = 987654321;
//const int MAX_V = 801;
//
//vector<pair<int,int> > V[MAX_V];
//
//vector<int> dijkstra(const int& start) {
//	vector<int> dist(N + 1, INF);
//	dist[start] = 0;
//
//	priority_queue<pair<int, int> > pq;
//	pq.push({ 0, start });
//
//	while (!pq.empty()) {
//		int here = pq.top().second;
//		int cost = -pq.top().first;
//		pq.pop();
//		//만일 이번 경로가 최단경로가 아니라면 생략한다.
//		if (dist[here] < cost) continue;
//		//인접한 정점들을 모두 검사한다.
//		for (int i = 0; i < V[here].size(); i++) {
//			int there = V[here][i].first;
//			int there_cost = V[here][i].second + cost;
//			if (there_cost < dist[there]) {
//				dist[there] = there_cost;
//				pq.push({ -there_cost, there });
//			}
//		}
//	}
//
//	return dist;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> E;
//	int a, b, c;
//	for (int i = 0; i < E; i++) {
//		cin >> a >> b >> c;
//		V[a].push_back({ b,c });
//		V[b].push_back({ a,c });
//	}
//
//	int node1, node2;
//	cin >> node1 >> node2;
//
//	vector<int> route = dijkstra(1);
//	vector<int> route1 = dijkstra(node1);
//	vector<int> route2 = dijkstra(node2);
//
//	int ret = min({route[node1] + route2[N], route[node2] + route1[N]});
//	ret += route1[node2];
//
//	if (ret >= INF || ret < 0)
//		cout << -1 << "\n";
//	else
//		cout << ret << "\n";
//
//	return 0;
//}