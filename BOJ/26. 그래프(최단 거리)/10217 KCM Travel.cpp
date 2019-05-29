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
////dist�� first�� �ð�, second�� cost
//int dist[101][10001];
//
////first�� ���� ����, second.first�� cost, second.second�� �ҿ� �ð��̴�.
//vector<pair<int, pair<int, int> > > adj[MAX_N];
//
////����-���� �˰����� Ȱ���� Ž��
//void bellmanFord(int N) {
//	//���� �ҿ�ð��� �����ϰ�, �ڴ� ����� �����Ѵ�.
//	vector<pair<int, int> > upper(N + 1, { INF, 0 });
//	//1���� �����ϹǷ� 1�� 0���� �Ѵ�.
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
////���ͽ�Ʈ�� �˰����� Ȱ���� Ž��
//void dijkstra(int N,int M) {
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			dist[i][j] = INF;
//	
//	dist[1][0] = 0;
//	//first�� time, second.first�� cost, second.second�� ���� ��ġ
//	priority_queue<pair<int, pair<int,int> > > pq;
//	pq.push({ 0,{0,1} });
//
//	while (!pq.empty()) {
//		int timeCost = -pq.top().first;
//		int cost = pq.top().second.first;
//		int here = pq.top().second.second;
//		pq.pop();
//		//���� ������ �ٴٸ� ��� �������.
//		if (here == N) {
//			cout << timeCost << endl;
//			return;
//		}
//
//		//���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� ���� ���� ��������.
//		if (dist[here][cost] < timeCost) continue;
//		//������ �������� ��� �˻��Ѵ�.
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			int thereCost = adj[here][i].second.first + cost;
//			int thereTimeCost = adj[here][i].second.second + timeCost;
//			//������ �ʰ��� ���
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

//������� ��������, ���, �ҿ�ð�
vector<tuple<int, int, int> > adj[101];
//dist[i][j] : 1�� ���ÿ��� i�� ���ñ��� ��� j�� ����ϴ� �ּ� �ð�
int dist[103][10003];
const int INF = 1000000007;

//N���� ���ÿ� M���� ����������� N�� ������ �� �� �ִ��� Ȯ������.
void dijkstra(int N, int M) {
	//�ʱ�ȭ
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = INF;
	//��� ���ô� 1�� �̹Ƿ� �ʱⰪ�� �־��ش�.
	dist[1][0] = 0;
	//������� -�ҿ�ð�, ���, ���� ��ġ�̴�.
	priority_queue<tuple<int, int, int> > pq;
	pq.push({ 0,1,0 });
	while (!pq.empty()) {
		int hereTimeCost = -get<0>(pq.top());
		int here = get<1>(pq.top());
		int hereCost = get<2>(pq.top());
		pq.pop();
		//���� �����Ͽ��ٸ�, �ҿ�ð��� ����Ѵ�. �׸��� ����
		if (here == N) {
			cout << hereTimeCost << endl;
			return;
		}
		//���� �̹� �̰ͺ��� ���� �ð��� ã�Ҵٸ�, �̹����� �����Ѵ�.
		if (dist[here][hereCost] < hereTimeCost)
			continue;
		for (auto next : adj[here]) {
			int there = get<0>(next);
			int thereCost = get<1>(next) + hereCost;
			int thereTimeCost = get<2>(next) + hereTimeCost;
			//���� ���� �ݾ��� �ʰ��Ͽ��ٸ�, �� ���� �����Ѵ�.
			if (thereCost > M)
				continue;
			//�� ª�� �ð��� ã�Ҵٸ�, ����������.
			if (dist[there][thereCost] > thereTimeCost) {
				dist[there][thereCost] = thereTimeCost;
				pq.push({ -thereTimeCost, there, thereCost });
			}
		}
			
	}

	//������� �Դٴ� ���� ��� ���� N��° ���׿� �������� ���� ���̴�.
	cout << "Poor KCM" << endl;
	return;
}

int main() {
	int T, N, M, K;
	int start, end, cost, timeCost;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		//�ʱ�ȭ�� ���ش�.
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
		}
		//Ƽ�� ���� �Է�
		for (int i = 0; i < K; i++) {
			cin >> start >> end >> cost >> timeCost;
			adj[start].push_back({ end, cost, timeCost });
		}


		dijkstra(N, M);
	}

}