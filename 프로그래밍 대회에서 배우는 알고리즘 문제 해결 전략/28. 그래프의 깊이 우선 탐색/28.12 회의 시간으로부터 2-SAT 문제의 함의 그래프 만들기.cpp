//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////�׷����� ���� ����Ʈ ǥ��
//vector<vector<int> > adj;
////�α��� a�� b�� ���� ��ġ�� �ʴ����� Ȯ���Ѵ�.
//bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
//	return a.second <= b.first || b.second <= a.first;
//}
////meetings[]�� �� ���� ���� �;��ϴ� ȸ�� �簣�� ����� ��, �̸�
////2-SAT ������ ��ȯ�� �� ���� �׷����� �����Ѵ�.
////i�� ���� meetings[2*i] Ȥ�� meetings[2*i+1] �� �ϳ� �ð��� ȸ�ǽ��� ��� �Ѵ�.
//void makeGraph(const vector<pair<int, int> >& meetings) {
//	int vars = meetings.size();
//	//�׷����� �� �������� �� ���� ������ ���´�.
//	adj.clear(); adj.resize(vars * 2);
//	for (int i = 0; i < vars; i += 2) {
//		//�� ���� i�� ȸ�ǳ� j�� ȸ�� �� �� �ϳ��� �ؾ��Ѵ�/
//		//(i or j) ���� �߰��Ѵ�.
//		int j = i + 1;
//		adj[i * 2 + 1].push_back(j * 2); //~i =>j
//		adj[j * 2 + 1].push_back(i * 2); //~i =>j
//	}
//}