//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////�׷����� ���� ��� ǥ��. adj[i][j]=i�� j������ ������ ��
//vector<vector<int> > adj;
////graph[i][j] = i�� �����ؼ� j�� ������ �ܾ��� ��
//vector<string> graph[26][26];
////indegree[i]=i�� �����ϴ� �ܾ��� ��
////outdegree[i]=i�� ������ �ܾ��� ��
//vector<int> indegree, outdegree;
//void makeGraph(const vector<string>& words) {
//	//���� ���� �ʱ�ȭ
//	for (int i = 0; i < 26; i++)
//		for (int j = 0; j < 26; j++)
//			graph[i][j].clear();
//	adj = vector<vector<int> >(26, vector<int>(26, 0));
//	indegree = outdegree = vector<int>(26, 0);
//	//�� �ܾ �׷����� �߰��Ѵ�.
//	for (int i = 0; i < words.size(); i++) {
//		int a = words[i][0];
//		int b = words[i][words[i].size() - 1] - 'a';
//		graph[a][b].push_back(words[i]);
//		adj[a][b]++;
//		outdegree[a]++;
//		indegree[b]++;
//	}
//}