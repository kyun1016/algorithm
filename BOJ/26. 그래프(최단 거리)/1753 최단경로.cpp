//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
////first = 다음 노드, second = 가중치
//const int INF = 1000000007;
////연결된 노드를 저장하는 배열이다.
//vector<pair<int, int> > Node[20001];
//queue<pair<int, int> > qu;
//int visited[20001];
//
////근본 없이 내 생각대로 만들어보았다.
//void srcCost(const int& startNode) {
//	//시작 노드에서 뻗어나오는 모든 간선을 담아주자.
//	for (int i = 0; i < Node[startNode].size(); i++) {
//		qu.push({ Node[startNode][i] });
//		visited[Node[startNode][i].first] = Node[startNode][i].second;
//	}
//
//	while (!qu.empty()) {
//		//지금 있는 위치를 직관적으로 보여주자.
//		pair<int, int> hereNode = qu.front();
//		qu.pop();
//		for (int i = 0; i < Node[hereNode.first].size(); i++) {
//			int nextNode = Node[hereNode.first][i].first;
//			int nextCost = hereNode.second + Node[hereNode.first][i].second;
//			//만일 다음에 방문할 노드가 이미 큐에 담겨있고, 그 크기가 지금 구하는 크기보다 작으면 패스한다.
//			if (visited[nextNode] != 0 &&visited[nextNode] < nextCost)
//				continue;
//			qu.push({ nextNode, nextCost });
//			visited[nextNode] = nextCost;
//		}
//	}
//}
//
//
//////다익스트라를 활용해서 만들어보자.
//////priority_queue를 활용하는 것이 특별한 점이다.
//////활용하는 것은 위와 거의 동일한데, 음.... visited를 비슷하게 활용해볼까?
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
//	//앞은 cost, 뒤는 현재 위치
//	priority_queue<pair<int, int> > pq;
//	pq.push({ 0, startNode });
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int here = pq.top().second;
//		pq.pop();
//		//이곳에 더 작은 방법이 존재한다면, 이 경우는 폐기한다.
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