//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//////������ ����
////int V;
////const int MAX_V = 20001;
//////�׷����� ���� �ؿ��� ǥ��
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
//int V,E;
//const int MAX_V = 801;
////�׷����� ���� ��� ǥ��
////adj[u][v]=u���� v�� ���� ������ ����ġ. ������ ������ ���� ū ���� �ִ´�.
//int adj[MAX_V][MAX_V];
////via[u][v]=u���� v���� ���� �ִ� ��ΰ� �����ϴ� �� �� ���� ��ȣ�� ū ����
////-1�� �ʱ�ȭ�� �д�.
//int via[MAX_V][MAX_V];
////�÷��̵��� ��� �� �ִ� �Ÿ� �˰���
//void floyd2() {
//	for (int i = 0; i <= V; i++)
//		adj[i][i] = 0;
//	memset(via, -1, sizeof(via));
//	for (int k = 1; k <= V; k++)
//		for (int i = 1; i <= V; i++)
//			for (int j = 1; j <= V; j++)
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
//
////u���� v�� ���� �ִ� ��θ� ����� path�� �����Ѵ�.
//int reconstruct2(int u, int v) {
//	int ret = 0;
//	//���� ���
//	if (via[u][v] == -1) {
//		ret += adj[u][v];
//	}
//	else {
//		int w = via[u][v];
//		ret += reconstruct2(u, w);
//		
//		ret += reconstruct2(w, v);
//	}
//	return ret;
//}
//
//
//int main() {
//	int a, b, c;
//	cin >> V >> E;
//	for (int i = 0; i < E; i++) {
//		cin >> a >> b >> c;
//		if (adj[a][b] != 0 && c > adj[a][b])
//			continue;
//		adj[a][b] = c;
//		adj[b][a] = c;
//	}
//	cin >> a >> b;
//	//������ �غ��� 1�� �������� N�� �������� �̵��ϴµ�
//	//a,b�� �������鼭�� �ִ� �Ÿ��� ����ؾ��Ѵ�.
//	//�� ����� ���� ��������
//	//�� 6���� �������� ����Ų��.
//	//1>a, 1>b, 1>N, a>b, a>N, b>N
//	//�� 6���� ������ ������ ���� 1>N�� �ִ� �Ÿ��� ���س���.
//	floyd2();
//	int ret = 0;
//	
//	/*cout << reconstruct2(1, a) << endl;
//	cout << reconstruct2(b, V) << endl;
//	cout << reconstruct2(1, b) << endl;
//	cout << reconstruct2(a, V) << endl;*/
//
//	int oneToA, aToN, aToB, bToN, oneToB,oneToN;
//	oneToA = reconstruct2(1, a);
//	aToB = reconstruct2(a, b);
//	oneToB = reconstruct2(1, b);
//	aToN = reconstruct2(a, V);
//	bToN = reconstruct2(b, V);
//	oneToN = reconstruct2(1, V);
//
//	//via[1][V]�� üũ����
//	int check = via[1][V];
//	bool isVia[2] = { false };
//	while (check != -1) {
//		if (check == a)
//			isVia[0] = true;
//		if (check == b)
//			isVia[1] = true;
//		check = via[1][check];
//	}
//	check = via[1][V];
//	while (check != -1) {
//		if (check == a)
//			isVia[0] = true;
//		if (check == b)
//			isVia[1] = true;
//		check = via[check][V];
//	}
//	if (adj[1][V] == 0)
//		cout << -1 << endl;
//	else if (isVia[0] && isVia[1]) {
//		cout << oneToN << endl;
//	}
//	else if (!isVia[0] && !isVia[1]) {
//		ret = min(oneToA + aToB + bToN, oneToB + aToB + aToN);
//		ret = min(ret, oneToA + aToB * 2 + aToN);
//		ret = min(ret, oneToB + aToB * 2 + bToN);
//		ret = min(ret, oneToN + aToN * 2 + bToN * 2);
//		ret = min(ret, oneToN + aToN + aToB + bToN);
//		ret = min(ret, oneToA * 2 + oneToB * 2 + oneToN);
//		cout << ret << endl;
//	}
//	else if (!isVia[0] && isVia[1]) {
//		ret = min(oneToA + aToB + bToN, oneToB + aToB + aToN);
//		ret = min(ret, oneToA + aToB * 2 + aToN);
//		ret = min(ret, oneToB + aToB * 2 + bToN);
//		ret = min(ret, oneToN + aToN * 2 + bToN * 2);
//		ret = min(ret, oneToN + aToN + aToB + bToN);
//		ret = min(ret, oneToA * 2 + oneToB * 2 + oneToN);
//		ret = min(ret, oneToN + aToB * 2);
//		cout << ret << endl;
//	}
//	else if (isVia[0] && !isVia[1]) {
//		ret = min(oneToA + aToB + bToN, oneToB + aToB + aToN);
//		ret = min(ret, oneToA + aToB * 2 + aToN);
//		ret = min(ret, oneToB + aToB * 2 + bToN);
//		ret = min(ret, oneToN + aToN * 2 + bToN * 2);
//		ret = min(ret, oneToN + aToN + aToB + bToN);
//		ret = min(ret, oneToA * 2 + oneToB * 2 + oneToN);
//		ret = min(ret, oneToN + aToB * 2);
//		cout << ret << endl;
//	}
//}