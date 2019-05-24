//#include<vector>
//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//vector < vector<int> > adj;
//
//
////start���� ������ �׷����� �ʺ� �켱 Ž���ϰ� ���������� �� ����������
////�ִ� �Ÿ��� �ʺ� �켱 Ž�� ���д� Ʈ���� ����Ѵ�.
////distance[i] = start���� i������ �ִ� �Ÿ�
////parent[i]=�ʺ� �켱 Ž�� ���д� Ʈ������ i�� �θ��� ��ȣ. ��Ʈ�� ��� �ڽ��� ��ȣ
//void bfs2(int start, vector<int>& distance, vector<int>& parent) {
//	distance = vector<int>(adj.size(), -1);
//	parent = vector<int>(adj.size(), -1);
//	//�湮�� ���� ����� �����ϴ� ť
//	queue<int> q;
//	distance[start] = 0;
//	parent[start] = start;
//	q.push(start);
//	while (!q.empty()) {
//		int here = q.front();
//		q.pop();
//		//here�� ��� ������ ������ �˻��Ѵ�.
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i];
//			//ó�� ���� �����̸� �湮 ��Ͽ� ����ִ´�.
//			if (distance[there] == -1) {
//				q.push(there);
//				distance[there] = distance[here] + 1;
//				parent[there] = here;
//			}
//		}
//	}
//}
//
////v�κ��� ������������ �ִ� ��θ� ����Ѵ�.
//vector<int> shortestPath(int v, const vector<int>& parent) {
//	vector<int> path(1, v);
//	while (parent[v] != v) {
//		v = parent[v];
//		path.push_back(v);
//	}
//	reverse(path.begin(), path.end());
//	return path;
//}