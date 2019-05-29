//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////알파벳의 각 글자에 대한 인접 행렬 표현
////간선 (i,j)는 알파벳 i가 j보다 앞에 와야 함을 나타낸다.
//vector<vector<int> > adj;
////주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다.
//void makeGraph(const vector<string>& words) {
//	adj = vector<vector<int> >(26, vector<int>(26, 0));
//	for (int j = 1; j < words.size(); j++) {
//		int i = j - 1, len = min(words[i].size(), words[j].size());
//		//word[i]가 word[j]앞에 오는 이유를 찾는다.
//		for (int k = 0; k < len; k++) {
//			int a = words[i][k] - 'a';
//			int b = words[j][k] - 'a';
//			adj[a][b] = 1;
//			break;
//		}
//	}
//}
////28.3 깊이 우선 탐색을 이용한 위상 정렬
//vector<int> seen, order;
//void dfs(int here) {
//	seen[here] = 1;
//	for (int there = 0; there < adj.size(); there++)
//		if (adj[here][there] && !seen[there])
//			dfs(there);
//	order.push_back(here);
//}
////adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
////그래프가 DAG가 아니라면 빈 벡터를 반환한다.
//vector<int> topologicalSort() {
//	int n = adj.size();
//	seen = vector<int>(n, 0);
//	order.clear();
//	for (int i = 0; i < n; i++)
//		if (!seen[i]) dfs(i);
//	reverse(order.begin(), order.end());
//	//만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j < n; i++)
//			if (adj[order[j]][order[i]])
//				return vector<int>();
//	//없는 경우라면 깊이 우선탐색에서 얻은 순서를 반환한다.
//	return order;
//}