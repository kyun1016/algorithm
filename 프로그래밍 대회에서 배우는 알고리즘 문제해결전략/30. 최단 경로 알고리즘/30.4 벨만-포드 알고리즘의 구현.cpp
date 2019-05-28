//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////������ ����
//int V;
//const int MAX_V = 501;
//const int INF = 1000000007;
////�׷����� ���� ����Ʈ.(����� ���� ��ȣ, ���� ����ġ) ���� ��´�.
//vector<pair<int, int> > adj[MAX_V];
////reachable[u][v] = u���� v�� ���� ��ΰ� �ִ°�?
//bool reachable[MAX_V][MAX_V];
////���� ����Ŭ�� ���� ��� �� �� �迭�� ��ȯ
//vector<int> bellmanFord(int src) {
//	//�������� ������ ��� ���������� �ִ� �Ÿ� ������ INF�� �д�.
//	vector<int> upper(V+1, INF);
//	upper[src] = 0;
//	bool updated = false;
//	//V�� ��ȸ�Ѵ�.
//	for (int iter = 0; iter < V; ++iter) {
//		updated = false;
//		for(int here = 1; here <= V; here++)
//			for (int i = 0; i < adj[here].size(); i++) {
//				int there = adj[here][i].first;
//				int cost = adj[here][i].second;
//				//(here, there)������ ���� ��ȭ�� �õ��Ѵ�.
//				if (upper[there] > upper[here] + cost) {
//					//����
//					upper[there] = upper[here] + cost;
//					updated = true;
//				}
//			}
//		//��� ������ ���� ��ȭ�� �������� ��� V-1���� �� �ʿ� ���� ���� �����Ѵ�.
//		if (!updated) break;
//	}
//	//V��° ��ȸ������ ��ȭ�� �����ߴٸ� ���� ����Ŭ�� �ִ�.
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
///////�ڵ� 30.5 ���� ���� �˰����� �̿��� �ð����� ���� �ذ��ϱ�
////src���� target���� ���� �ִܰŸ��� ����Ѵ�.
//int bellman2(int src, int target) {
//	//�������� ������ ��� ���������� �ִ� �Ÿ� ������ INF�� �д�
//	vector<int> upper(V, INF);
//	upper[src] = 0;
//	//V-1�� ��ȸ�Ѵ�.
//	for(int iter = 0;iter < V-1;iter++)
//		for(int here = 0; here < V;here++)
//			for (int i = 0; i < adj[here].size(); i++) {
//				int there = adj[here][i].first;
//				int cost = adj[here][i].second;
//				//(here, there) ������ ���� ��ȭ�� �õ��Ѵ�.
//				upper[there] = min(upper[there], upper[here] + cost);
//			}
//	//���� ����Ŭ�� ���� ���θ� Ȯ������.
//	for(int here=0;here<V;here++)
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i].first;
//			int cost = adj[here][i].second;
//			//(here, there) ������ ���� ��ȭ�� �õ��Ѵ�.
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
