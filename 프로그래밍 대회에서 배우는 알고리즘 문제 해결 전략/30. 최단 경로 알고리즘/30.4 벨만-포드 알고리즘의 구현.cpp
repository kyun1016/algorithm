//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////정점의 개수
//int V;
//const int MAX_V = 501;
//const int INF = 1000000007;
////그래프의 인접 리스트.(연결된 정점 번호, 간선 가중치) 쌍을 담는다.
//vector<pair<int, int> > adj[MAX_V];
////reachable[u][v] = u에서 v로 가는 경로가 있는가?
//bool reachable[MAX_V][MAX_V];
////음수 사이클이 있을 경우 텅 빈 배열을 반환
//vector<int> bellmanFord(int src) {
//	//시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
//	vector<int> upper(V+1, INF);
//	upper[src] = 0;
//	bool updated = false;
//	//V번 순회한다.
//	for (int iter = 0; iter < V; ++iter) {
//		updated = false;
//		for(int here = 1; here <= V; here++)
//			for (int i = 0; i < adj[here].size(); i++) {
//				int there = adj[here][i].first;
//				int cost = adj[here][i].second;
//				//(here, there)간선을 따라 완화를 시도한다.
//				if (upper[there] > upper[here] + cost) {
//					//성공
//					upper[there] = upper[here] + cost;
//					updated = true;
//				}
//			}
//		//모든 간선에 대해 완화가 실패했을 경우 V-1번도 돌 필요 없이 곧장 종료한다.
//		if (!updated) break;
//	}
//	//V번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
//	if (updated) {
//
//		upper.clear();
//		cout << "YES" << endl;
//		return upper;
//	}
//	else {
//		cout << "NO" << endl;
//		return upper;
//	}
//}
//
//
//
///////코드 30.5 벨만 포드 알고리즘을 이용해 시간여행 문제 해결하기
////src에서 target으로 가는 최단거리를 계산한다.
//int bellman2(int src, int target) {
//	//시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다
//	vector<int> upper(V, INF);
//	upper[src] = 0;
//	//V-1번 순회한다.
//	for(int iter = 0;iter < V-1;iter++)
//		for(int here = 0; here < V;here++)
//			for (int i = 0; i < adj[here].size(); i++) {
//				int there = adj[here][i].first;
//				int cost = adj[here][i].second;
//				//(here, there) 간선을 따라 완화를 시도한다.
//				upper[there] = min(upper[there], upper[here] + cost);
//			}
//	//음수 사이클의 존재 여부를 확인하자.
//	for(int here=0;here<V;here++)
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			int cost = adj[here][i].second;
//			//(here, there) 간선을 따라 완화를 시도한다.
//			upper[there] = min(upper[there], upper[here] + cost);
//		}
//}
//
//
//
//
//
//
//int main() {
//	int testCase, road, hole;
//	int a, b, c;
//	cin >> testCase;
//	while (testCase--) {
//		cin >> V >> road >> hole;
//		for (int i = 1; i <= V; i++) {
//			adj[i].clear();
//		}
//		while (road--) {
//			cin >> a >> b >> c;
//			adj[a].push_back({ b,c });
//		}
//		while (hole--) {
//			cin >> a >> b >> c;
//			adj[a].push_back({ b,-c });
//		}
//		
//		vector<int> ret = bellmanFord(1);
//	}
//
//
//
//
//	return 0;
//}
//
//
