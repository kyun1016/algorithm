//#include <iostream>
//#include <vector>
//
//using namespace std;
//
////�׷����� ���� ����Ʈ ǥ��
//vector<vector<int>> adj;
////�� ������ �湮�ߴ��� ���θ� ��Ÿ����.
//vector<bool> visited;
//void dfs(int here) {
//	cout << "DFS visits" << here << endl;
//	visited[here] = true;
//	//��� ���� ������ ��ȸ�ϸ鼭
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		//���� �湮�� �� ���ٸ� �湮�Ѵ�.
//		if (!visited[there])
//			dfs(there);
//	}
//	//���̻� �湮�� ������ ������, ���ȣ���� �����ϰ� ���� �������� ���ư���.
//}
////��� ������ �湮�Ѵ�.
//void dfsAll() {
//	//visited�� ��� false�� �ʱ�ȭ�Ѵ�.
//	visited = vector<bool>(adj.size(), false);
//	//��� ������ ��ȸ�ϸ鼭, ���� �湮�� �� ������ �湮�Ѵ�.
//	for (int i = 0; i < adj.size(); i++)
//		if (!visited[i])
//			dfs(i);
//}