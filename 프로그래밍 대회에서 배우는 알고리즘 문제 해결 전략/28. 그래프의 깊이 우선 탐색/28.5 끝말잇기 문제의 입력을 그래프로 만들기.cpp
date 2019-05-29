//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////그래프의 인접 행렬 표현. adj[i][j]=i와 j사이의 간선의 수
//vector<vector<int> > adj;
////graph[i][j] = i로 시작해서 j로 끝나는 단어의 수
//vector<string> graph[26][26];
////indegree[i]=i로 시작하는 단어의 수
////outdegree[i]=i로 끝나는 단어의 수
//vector<int> indegree, outdegree;
//void makeGraph(const vector<string>& words) {
//	//전역 변수 초기화
//	for (int i = 0; i < 26; i++)
//		for (int j = 0; j < 26; j++)
//			graph[i][j].clear();
//	adj = vector<vector<int> >(26, vector<int>(26, 0));
//	indegree = outdegree = vector<int>(26, 0);
//	//각 단어를 그래프에 추가한다.
//	for (int i = 0; i < words.size(); i++) {
//		int a = words[i][0];
//		int b = words[i][words[i].size() - 1] - 'a';
//		graph[a][b].push_back(words[i]);
//		adj[a][b]++;
//		outdegree[a]++;
//		indegree[b]++;
//	}
//}