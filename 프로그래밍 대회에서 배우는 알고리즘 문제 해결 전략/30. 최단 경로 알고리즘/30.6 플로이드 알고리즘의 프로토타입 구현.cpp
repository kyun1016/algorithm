//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//////������ ����
////int V;
////const int MAX_V = 20001;
//////�׷����� ���� ��� ǥ��
//////adj[u][v]=u���� v�� ���� ������ ����ġ. ������ ������ ���� ū ���� �ִ´�.
////int adj[MAX_V][MAX_V];
////int C[MAX_V][MAX_V][MAX_V];
////void allPairShortestPath1() {
////	//C[0]�� �ʱ�ȭ
////	for (int i = 0; i < V; i++)
////		for (int j = 0; j < V; j++)
////			if (i != j)
////				C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
////	//C[k-1]�� ������ C[k]�� ����� �� �ִ�.
////	for (int k = 1; k < V; k++)
////		for (int i = 0; i < V; i++)
////			for (int j = 0; j < V; j++)
////				C[k][i][j] = min(C[k - 1][i][j], C[k - 1][i][k] + C[K - 1][k][j]);
////}
//
//
//
////////�ڵ� 30.7 �÷��̵� �˰����� ����
//////������ ����
////int V;
////const int MAX_V = 20001;
//////�׷����� ���� �ؿ��� ǥ��
//////adj[u][v]=u���� v�� ���� ������ ����ġ. ������ ������ ���� ū ���� �ִ´�.
////int adj[MAX_V][MAX_V];
//////�÷��̵��� ��� �� �ִ� �Ÿ� �˰���
////void floyd() {
////	//C[0]�� �ʱ�ȭ
////	for (int i = 0; i < V; i++)
////		adj[i][i] = 0;
////
////	//C[k-1]�� ������ C[k]�� ����� �� �ִ�.
////	for (int k = 1; k < V; k++)
////		for (int i = 0; i < V; i++)
////			for (int j = 0; j < V; j++)
////				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
////}
//
//
//
//////�ڵ� 30.8 �÷��̵� �˰��򿡼� ���� �ִ� ��� ����ϱ�
////������ ����
//int V;
//const int MAX_V = 20001;
////�׷����� ���� ��� ǥ��
////adj[u][v]=u���� v�� ���� ������ ����ġ. ������ ������ ���� ū ���� �ִ´�.
//int adj[MAX_V][MAX_V];
////via[u][v]=u���� v���� ���� �ִ� ��ΰ� �����ϴ� �� �� ���� ��ȣ�� ū ����
////-1�� �ʱ�ȭ�� �д�.
//int via[MAX_V][MAX_V];
////�÷��̵��� ��� �� �ִ� �Ÿ� �˰���
//void floyd2() {
//	for (int i = 0; i < V; i++)
//		adj[i][i] = 0;
//	memset(via, -1, sizeof(via));
//	for(int k = 0; k<V;k++)
//		for(int i=0;i<V;i++)
//			for(int j=0;j<V;j++)
//				if (adj[i][j] > adj[i][k] + adj[k][j]) {
//					via[i][j] = k;
//					adj[i][j] = adj[i][k] + adj[k][j];
//				}
//}
////u���� v�� ���� �ִ� ��θ� ����� path�� �����Ѵ�.
//void reconstruct(int u, int v, vector<int>& path) {
//	//���� ���
//	if (via[u][v] == -1) {
//		path.push_back(u);
//		if (u != v) path.push_back(v);
//	}
//	else {
//		int w = via[u][v];
//		reconstruct(u, w, path);
//		path.pop_back();	//w�� �ߺ����� ���Ƿ� �����.
//		reconstruct(w, v, path);
//	}
//}