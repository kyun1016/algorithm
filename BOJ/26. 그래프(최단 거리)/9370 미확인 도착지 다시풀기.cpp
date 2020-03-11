//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//const int INF = 1000000007;
//const int MAX_V = 2001;
//vector<pair<int, int> > V[2001];
//vector<int> find_this;
//
//int N, M, T;
//int S, G, H;
//
//vector<int> dijkstra(const int& start) {
//	//�� ���� �̵��ϴµ� �ʿ��� �ð��� ����, ó������ INF�� �ʱ�ȭ
//	vector<int> dist(N + 1, INF);
//	//���������� 0���� ����
//	dist[start] = 0;
//
//	priority_queue<pair<int, int> > pq;
//	pq.push({ 0, start });
//
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int here = pq.top().second;
//		pq.pop();
//		//���� �̹� �ڽ�Ʈ�� �ִܰ�ΰ� �ƴ϶�� �н�
//		if (cost > dist[here]) continue;
//		for (int i = 0; i < V[here].size(); i++) {
//			int there = V[here][i].first;
//			int next_cost = cost + V[here][i].second;
//			//���� ������ ���� �ִܰ�ΰ� ���ŵǴ� ���
//			if (next_cost < dist[there]) {
//				dist[there] = next_cost;
//				pq.push({ -next_cost, there });
//			}
//		}
//	}
//
//	return dist;
//}
//
//int main() {
//	int testcase;
//	cin >> testcase;
//	for (int i = 0; i < testcase; i++) {
//		cin >> N >> M >> T;
//		cin >> S >> G >> H;
//
//		//Ȱ��Ǵ� ������ ���� �̸� �ʱ�ȭ�� ���ش�.
//		for (int j = 1; j <= N; j++)
//			V[j].clear();
//		int a, b, c;
//		for (int j = 0; j < M; j++) {
//			cin >> a >> b >> c;
//			V[a].push_back({ b,c });
//			V[b].push_back({ a,c });
//		}
//
//		int temp;
//		//�׻� �ʱ�ȭ�� ���ش�.
//		find_this.clear();
//		for (int j = 0; j < T; j++) {
//			cin >> temp;
//			find_this.push_back(temp);
//		}
//		//�̸� ������������ �����Ѵ�.
//		sort(find_this.begin(), find_this.end());
//
//		vector<int> root = dijkstra(S);
//		vector<int> branch1 = dijkstra(G);
//		vector<int> branch2 = dijkstra(H);
//
//		vector<int> ret;
//		for (int j = 1; j <= N; j++) {
//			//������������ j�� ���ñ��� �ɸ� cost��
//			//H, G���� �����ؼ� ���ư� cost�� ������ ���
//			//ret�� ��� �������ش�.
//			if (root[j] == root[G] + branch1[H] + branch2[j] || root[j] == root[H] + branch2[G] + branch1[j]) {
//				ret.push_back(j);
//			}
//		}
//
//		//�츮�� ã�� ���� ����� ��尡 �ִ� ���(ret�� ����ִ� ���)�� �ϳ��� ���
//		for (int j = 0; j < find_this.size(); j++) {
//			int here = find_this[j];
//			for (int k = 0; k < ret.size(); k++) {
//				if (here == ret[k])
//					cout << here << " ";
//			}
//		}
//		cout << endl;
//	}
//
//	return 0;
//}