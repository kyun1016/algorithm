//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
////first = ���� ���, second = ����ġ
//const int INF = 1000000007;
////����� ��带 �����ϴ� �迭�̴�.
//vector<pair<int, int> > Node[20001];
//queue<pair<int, int> > qu;
//int visited[20001];
//
////�ٺ� ���� �� ������� �����Ҵ�.
//void srcCost(const int& startNode) {
//	//���� ��忡�� ������� ��� ������ �������.
//	for (int i = 0; i < Node[startNode].size(); i++) {
//		qu.push({ Node[startNode][i] });
//		visited[Node[startNode][i].first] = Node[startNode][i].second;
//	}
//
//	while (!qu.empty()) {
//		//���� �ִ� ��ġ�� ���������� ��������.
//		pair<int, int> hereNode = qu.front();
//		qu.pop();
//		for (int i = 0; i < Node[hereNode.first].size(); i++) {
//			int nextNode = Node[hereNode.first][i].first;
//			int nextCost = hereNode.second + Node[hereNode.first][i].second;
//			//���� ������ �湮�� ��尡 �̹� ť�� ����ְ�, �� ũ�Ⱑ ���� ���ϴ� ũ�⺸�� ������ �н��Ѵ�.
//			if (visited[nextNode] != 0 &&visited[nextNode] < nextCost)
//				continue;
//			qu.push({ nextNode, nextCost });
//			visited[nextNode] = nextCost;
//		}
//	}
//}
//
//
//////���ͽ�Ʈ�� Ȱ���ؼ� ������.
//////priority_queue�� Ȱ���ϴ� ���� Ư���� ���̴�.
//////Ȱ���ϴ� ���� ���� ���� �����ѵ�, ��.... visited�� ����ϰ� Ȱ���غ���?
////void dijkstra(const int& startNode) {
////	visited[startNode] = 0;
////	priority_queue<pair<int, int> > pq;
////	pq.push(make_pair(0, startNode));
////	while (!pq.empty()) {
////		int cost = -pq.top().first;
////		int here = pq.top().second;
////		pq.pop();
////		if (visited[here] < cost && visited[here] != 0)
////			continue;
////		for (int i = 0; i < Node[here].size(); i++) {
////			int there = Node[here][i].first;
////			int nextCost = cost + Node[here][i].second;
////			if (visited[there] <= nextCost && visited[there] != 0)
////				continue;
////			visited[there] = nextCost;
////			pq.push(make_pair(-nextCost, there));
////		}
////	}
////}
//
//vector<int> dijkstra(const int& startNode, const int& size) {
//	vector<int> dist(size+1, INF);
//	dist[startNode] = 0;
//	//���� cost, �ڴ� ���� ��ġ
//	priority_queue<pair<int, int> > pq;
//	pq.push({ 0, startNode });
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int here = pq.top().second;
//		pq.pop();
//		//�̰��� �� ���� ����� �����Ѵٸ�, �� ���� ����Ѵ�.
//		if (dist[here] < cost)
//			continue;
//		for (int i = 0; i < Node[here].size(); i++) {
//			int nextCost = cost + Node[here][i].second;
//			int there = Node[here][i].first;
//			if (dist[there] > nextCost) {
//				dist[there] = nextCost;
//				pq.push({ -nextCost, there });
//			}
//		}
//	}
//	return dist;
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int V, E, K;
//	int u, v, w;
//	cin >> V >> E >> K;
//	for (int i = 0; i < E; i++) {
//		cin >> u >> v >> w;
//		Node[u].push_back({ v,w });
//	}
//	//srcCost(K);
//	vector<int> ret = dijkstra(K, V);
//	for (int i = 1; i <= V; i++) {
//		if (ret[i] == INF)
//			cout << "INF" << endl;
//		else
//			cout << ret[i] << endl;
//	}
//}