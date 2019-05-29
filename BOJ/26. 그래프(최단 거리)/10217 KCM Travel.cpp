//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//
//
//const int INF = 100000007;
//const int MAX_N = 101;
////dist의 first는 시간, second는 cost
//int dist[101][10001];
//
////first는 다음 공항, second.first는 cost, second.second는 소요 시간이다.
//vector<pair<int, pair<int, int> > > adj[MAX_N];
//
////벨만-포드 알고리즘을 활용한 탐색
//void bellmanFord(int N) {
//	//앞은 소요시간을 저장하고, 뒤는 비용을 저장한다.
//	vector<pair<int, int> > upper(N + 1, { INF, 0 });
//	//1에서 시작하므로 1은 0으로 한다.
//	upper[1] = { 0,0 };
//
//	bool updated = false;
//
//	for (int iter = 0; iter < N; iter++) {
//		updated = false;
//		for (int here = 1; here <= N; here++) {
//			int thisCost = 0;
//			for (int i = 0; i < adj[here].size(); i++) {
//				int there = adj[here][i].first;
//				int cost = adj[here][i].second.first;
//				int timeCost = adj[here][i].second.second;
//				if (upper[there].first > upper[here].first + timeCost) {
//					thisCost = cost;
//					upper[there].first = upper[here].first + timeCost;
//				}
//			}
//		}
//
//	}
//
//
//}
//
//
//
//
//
////다익스트라 알고리즘을 활용한 탐색
//void dijkstra(int N,int M) {
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			dist[i][j] = INF;
//	
//	dist[1][0] = 0;
//	//first는 time, second.first는 cost, second.second는 현재 위치
//	priority_queue<pair<int, pair<int,int> > > pq;
//	pq.push({ 0,{0,1} });
//
//	while (!pq.empty()) {
//		int timeCost = -pq.top().first;
//		int cost = pq.top().second.first;
//		int here = pq.top().second.second;
//		pq.pop();
//		//도착 지점에 다다른 경우 출력하자.
//		if (here == N) {
//			cout << timeCost << endl;
//			return;
//		}
//
//		//만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시하자.
//		if (dist[here][cost] < timeCost) continue;
//		//인접한 정점들을 모두 검사한다.
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			int thereCost = adj[here][i].second.first + cost;
//			int thereTimeCost = adj[here][i].second.second + timeCost;
//			//예산을 초과한 경우
//			if (thereCost > M)
//				continue;
//			if (dist[there][thereCost] > thereTimeCost) {
//				dist[there][thereCost] = thereTimeCost;
//				pq.push({ -thereTimeCost, {thereCost,there} });
//			}
//		}
//	}
//
//
//	cout << "Poor KCM" << endl;
//	return;
//}
//
//int main() {
//	int T, N, M, K;
//	int start, end, cost, timeDelay;
//	cin >> T;
//	while (T--) {
//		cin >> N >> M >> K;
//		for (int i = 1; i <= N; i++) {
//			adj[i].clear();
//		}
//		for (int i = 0; i < K; i++) {
//			cin >> start >> end >> cost >> timeDelay;
//			adj[start].push_back({ end, {cost, timeDelay} });
//		}
//		dijkstra(N, M);
//	}
//
//
//	return 0;
//}


#include<iostream>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

//순서대로 도착공항, 비용, 소요시간
vector<tuple<int, int, int> > adj[101];
//dist[i][j] : 1번 도시에서 i번 도시까지 비용 j를 사용하는 최소 시간
int dist[103][10003];
const int INF = 1000000007;

//N개의 도시와 M원의 지원비용으로 N번 공항을 갈 수 있는지 확인하자.
void dijkstra(int N, int M) {
	//초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = INF;
	//출발 도시는 1번 이므로 초기값을 넣어준다.
	dist[1][0] = 0;
	//순서대로 -소요시간, 비용, 현재 위치이다.
	priority_queue<tuple<int, int, int> > pq;
	pq.push({ 0,1,0 });
	while (!pq.empty()) {
		int hereTimeCost = -get<0>(pq.top());
		int here = get<1>(pq.top());
		int hereCost = get<2>(pq.top());
		pq.pop();
		//만일 도착하였다면, 소요시간을 출력한다. 그리고 종료
		if (here == N) {
			cout << hereTimeCost << endl;
			return;
		}
		//만일 이미 이것보다 빠른 시간을 찾았다면, 이번에는 무시한다.
		if (dist[here][hereCost] < hereTimeCost)
			continue;
		for (auto next : adj[here]) {
			int there = get<0>(next);
			int thereCost = get<1>(next) + hereCost;
			int thereTimeCost = get<2>(next) + hereTimeCost;
			//만일 지원 금액을 초과하였다면, 이 경우는 무시한다.
			if (thereCost > M)
				continue;
			//더 짧은 시간을 찾았다면, 변경해주자.
			if (dist[there][thereCost] > thereTimeCost) {
				dist[there][thereCost] = thereTimeCost;
				pq.push({ -thereTimeCost, there, thereCost });
			}
		}
			
	}

	//여기까지 왔다는 것은 비용 내에 N번째 공항에 도착하지 못한 것이다.
	cout << "Poor KCM" << endl;
	return;
}

int main() {
	int T, N, M, K;
	int start, end, cost, timeCost;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		//초기화를 해준다.
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
		}
		//티켓 정보 입력
		for (int i = 0; i < K; i++) {
			cin >> start >> end >> cost >> timeCost;
			adj[start].push_back({ end, cost, timeCost });
		}


		dijkstra(N, M);
	}

}