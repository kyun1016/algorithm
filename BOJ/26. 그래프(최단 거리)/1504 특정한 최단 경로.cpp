//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//////정점의 개수
////int V;
////const int MAX_V = 20001;
//////그래프의 인접 해열ㄹ 표현
//////adj[u][v]=u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
////int adj[MAX_V][MAX_V];
////int C[MAX_V][MAX_V][MAX_V];
////void allPairShortestPath1() {
////	//C[0]을 초기화
////	for (int i = 0; i < V; i++)
////		for (int j = 0; j < V; j++)
////			if (i != j)
////				C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
////	//C[k-1]이 있으면 C[k]를 계산할 수 있다.
////	for (int k = 1; k < V; k++)
////		for (int i = 0; i < V; i++)
////			for (int j = 0; j < V; j++)
////				C[k][i][j] = min(C[k - 1][i][j], C[k - 1][i][k] + C[K - 1][k][j]);
////}
//
//
//
////////코드 30.7 플로이드 알고리즘의 구현
//////정점의 개수
////int V;
////const int MAX_V = 20001;
//////그래프의 인접 해열ㄹ 표현
//////adj[u][v]=u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
////int adj[MAX_V][MAX_V];
//////플로이드의 모든 쌍 최단 거리 알고리즘
////void floyd() {
////	//C[0]을 초기화
////	for (int i = 0; i < V; i++)
////		adj[i][i] = 0;
////
////	//C[k-1]이 있으면 C[k]를 계산할 수 있다.
////	for (int k = 1; k < V; k++)
////		for (int i = 0; i < V; i++)
////			for (int j = 0; j < V; j++)
////				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
////}
//
//
//
//////코드 30.8 플로이드 알고리즘에서 실제 최단 경로 계산하기
////정점의 개수
//int V,E;
//const int MAX_V = 801;
////그래프의 인접 행렬 표현
////adj[u][v]=u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
//int adj[MAX_V][MAX_V];
////via[u][v]=u에서 v까지 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점
////-1로 초기화해 둔다.
//int via[MAX_V][MAX_V];
////플로이드의 모든 쌍 최단 거리 알고리즘
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
////u에서 v로 가는 최단 경로를 계산해 path에 저장한다.
//void reconstruct(int u, int v, vector<int>& path) {
//	//기저 사례
//	if (via[u][v] == -1) {
//		path.push_back(u);
//		if (u != v) path.push_back(v);
//	}
//	else {
//		int w = via[u][v];
//		reconstruct(u, w, path);
//		path.pop_back();	//w가 중복으로 들어가므로 지운다.
//		reconstruct(w, v, path);
//	}
//}
//
////u에서 v로 가는 최단 경로를 계산해 path에 저장한다.
//int reconstruct2(int u, int v) {
//	int ret = 0;
//	//기저 사례
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
//	//생각을 해보자 1번 정점에서 N번 정점으로 이동하는데
//	//a,b를 지나가면서의 최단 거리를 출력해아한다.
//	//총 경우의 수를 따져보자
//	//총 6개의 간선으로 축약시킨다.
//	//1>a, 1>b, 1>N, a>b, a>N, b>N
//	//이 6개의 간선의 조합을 통해 1>N의 최단 거리를 구해내자.
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
//	//via[1][V]를 체크하자
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