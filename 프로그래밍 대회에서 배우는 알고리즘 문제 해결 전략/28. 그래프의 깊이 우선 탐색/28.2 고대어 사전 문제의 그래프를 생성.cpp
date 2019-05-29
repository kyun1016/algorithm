//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////���ĺ��� �� ���ڿ� ���� ���� ��� ǥ��
////���� (i,j)�� ���ĺ� i�� j���� �տ� �;� ���� ��Ÿ����.
//vector<vector<int> > adj;
////�־��� �ܾ��κ��� ���ĺ� ���� ���İ��� �׷����� �����Ѵ�.
//void makeGraph(const vector<string>& words) {
//	adj = vector<vector<int> >(26, vector<int>(26, 0));
//	for (int j = 1; j < words.size(); j++) {
//		int i = j - 1, len = min(words[i].size(), words[j].size());
//		//word[i]�� word[j]�տ� ���� ������ ã�´�.
//		for (int k = 0; k < len; k++) {
//			int a = words[i][k] - 'a';
//			int b = words[j][k] - 'a';
//			adj[a][b] = 1;
//			break;
//		}
//	}
//}
////28.3 ���� �켱 Ž���� �̿��� ���� ����
//vector<int> seen, order;
//void dfs(int here) {
//	seen[here] = 1;
//	for (int there = 0; there < adj.size(); there++)
//		if (adj[here][there] && !seen[there])
//			dfs(there);
//	order.push_back(here);
//}
////adj�� �־��� �׷����� ���������� ����� ��ȯ�Ѵ�.
////�׷����� DAG�� �ƴ϶�� �� ���͸� ��ȯ�Ѵ�.
//vector<int> topologicalSort() {
//	int n = adj.size();
//	seen = vector<int>(n, 0);
//	order.clear();
//	for (int i = 0; i < n; i++)
//		if (!seen[i]) dfs(i);
//	reverse(order.begin(), order.end());
//	//���� �׷����� DAG�� �ƴ϶�� ���� ����� ������ ������ �ִ�.
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j < n; i++)
//			if (adj[order[j]][order[i]])
//				return vector<int>();
//	//���� ����� ���� �켱Ž������ ���� ������ ��ȯ�Ѵ�.
//	return order;
//}