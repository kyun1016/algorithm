//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//
//const int MAX_V = 20001;
//const int INF = 1000000007;
////������ ����
//int V;
////�׷����� ���� ����Ʈ. (����� ���� ��ȣ, ���� ����ġ)���� ��´�.
//vector<pair<int, int> > adj[MAX_V];
//bool visited[20001];
//
//
//vector<int> dijkstra(int src) {
//	vector<int> dist(V+1, INF);
//	dist[src] = 0;
//	priority_queue<pair<int, int> > pq;
//	pq.push(make_pair(0, src));
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int here = pq.top().second;
//		pq.pop();
//		//���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� ���� ���� �����Ѵ�.
//		if (dist[here] < cost) continue;
//		//������ �������� ��� �˻��Ѵ�.
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			int nextDist = cost + adj[here][i].second;
//			//�� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
//			if (dist[there] > nextDist) {
//				dist[there] = nextDist;
//				pq.push(make_pair(-nextDist, there));
//			}
//		}
//	}
//	return dist;
//}
//
//int main() {
//	//ios_base::sync_with_stdio(0);
//
//	//cin.tie(0);
//
//
//
//	int N,a,b, k,start;
//	cin >> V >> N;
//	cin >> start;
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b >> k;
//		adj[a].push_back({ b, k });
//	}
//	vector<int> ret = dijkstra(start);
//	for (int i = 1; i <= V;i++) {
//		if(ret[i] == INF)
//			cout << "INF" << endl;
//		else
//			cout << ret[i] << endl;
//	}
//
//}