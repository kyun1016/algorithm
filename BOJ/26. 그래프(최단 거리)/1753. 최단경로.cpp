//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//
//const int MAX_V = 20001;
//const int INF = 1000000007;
////정점의 개수
//int V;
////그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치)쌍을 담는다.
//vector<pair<int, int> > adj[MAX_V];
//bool visited[20001];
//
//
//vector<int> dijkstra(int src) {
//	vector<int> dist(V + 1, INF);
//	dist[src] = 0;
//	priority_queue<pair<int, int> > pq;
//	pq.push(make_pair(0, src));
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int here = pq.top().second;
//		pq.pop();
//		//만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
//		if (dist[here] < cost) continue;
//		//인접한 정점들을 모두 검사한다.
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			int nextDist = cost + adj[here][i].second;
//			//더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
//			if (dist[there] > nextDist) {
//				dist[there] = nextDist;
//				pq.push(make_pair(-nextDist, there));
//			}
//		}
//	}
//	return dist;
//}
//
//vector<int> dijkstra2(int src) {
//	vector<int> dist(V + 1, INF);
//	//각 정점을 방문했는지 여부를 저장한다,
//	vector<bool> visited(V, false);
//	dist[src] = 0; visited[src] = false;
//	while (true) {
//		//아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
//		int closest = INF, here;
//		for (int i = 0; i < V; i++)
//			if (dist[i] < closest && !visited[i]) {
//				here = i;
//				closest = dist[i];
//			}
//		if (closest == INF) break;
//		//가장 가까운 정점을 방문한다.
//		visited[here] = true;
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			if (visited[there]) continue;
//			int nextDist = dist[here] + adj[here][i].second;
//			dist[there] = min(dist[there], nextDist);
//		}
//	}
//	return dist;
//}
//
//
//
//
//int main() {
//	ios_base::sync_with_stdio(0);
//
//	cin.tie(0);
//
//
//
//	int N, a, b, k, start;
//	cin >> V >> N;
//	cin >> start;
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b >> k;
//		adj[a].push_back({ b, k });
//	}
//	vector<int> ret = dijkstra2(start);
//	for (int i = 1; i <= V; i++) {
//		if (ret[i] == INF)
//			cout << "INF" << endl;
//		else
//			cout << ret[i] << endl;
//	}
//
//}