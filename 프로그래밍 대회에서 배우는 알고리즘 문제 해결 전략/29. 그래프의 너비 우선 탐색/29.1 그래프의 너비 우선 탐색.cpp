//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
////�׷����� ���� ����Ʈ ǥ��
//vector<vector<int> > adj;
////start���� ������ �׷����� �ʺ� �켱 Ž���ϰ� �� ������ �湮 ������ ��ȯ�Ѵ�.
//vector<int> bfs(int start) {
//	//�� ������ �湮 ����
//	vector<bool> discovered(adj.size(), false);
//	//�湮�� ���� ����� �����ϴ� ť
//	queue<int> q;
//	//������ �湮 ����
//	vector<int> order;
//	discovered[start] = true;
//	q.push(start);
//	while (!q.empty()) {
//		int here = q.front();
//		q.pop();
//		//here�� �湮�Ѵ�.
//		order.push_back(here);
//		//������ ������ �˻��Ѵ�.
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i];
//			//ó�� ���� �����̸� �湮 ��Ͽ� ���� �ִ´�.
//			if (!discovered[there]) {
//				q.push(there);
//				discovered[there] = true;
//			}
//		}
//	}
//	return order;
//}