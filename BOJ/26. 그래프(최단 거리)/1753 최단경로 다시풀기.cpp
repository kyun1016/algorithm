//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//const int MAX_V = 20001;
//const int INF = 1000000007;
//
//int V, E, start;
//
//vector<pair<int, int> > adj[MAX_V];
//priority_queue<pair<int, int> > pq;
//
//vector<int> dijkstra(const int& start) {
//	vector<int> dist(V + 1, INF);
//	dist[start] = 0;
//	pq.push(make_pair(0, start));
//
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int here = pq.top().second;
//		pq.pop();
//		//만일 이번 정점의 코스트가 최소가 아니라면 생략
//		if (dist[here] < cost) continue;
//		//인접한 정점들을 모두 검사한다.
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			int nextDist = cost + adj[here][i].second;
//			if (dist[there] > nextDist) {
//				dist[there] = nextDist;
//				pq.push(make_pair(-nextDist, there));
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
//	cin >> V >> E >> start;
//
//	int a, b, c;
//
//	for (int i = 0; i < E; i++) {
//		cin >> a >> b >> c;
//		adj[a].push_back({ b,c });
//	}
//	vector<int> ret = dijkstra(start);
//	for (int i = 1; i <= V; i++) {
//		if (ret[i] == INF)
//			cout << "INF" << endl;
//		else
//			cout << ret[i] << endl;
//	}
//}