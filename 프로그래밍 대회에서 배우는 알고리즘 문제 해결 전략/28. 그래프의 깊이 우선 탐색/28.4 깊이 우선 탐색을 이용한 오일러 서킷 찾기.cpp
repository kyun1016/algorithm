//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////�׷����� ���� ��� ǥ��. adj[i][j]=i�� j������ ������ ��
//vector<vector<int> > adj;
////���� �׷����� ���� ��� adj�� �־��� �� ���Ϸ� ��Ŷ�� ����Ѵ�.
////����� ������� circuit�� �������� ���Ϸ� ��Ŷ�� �ȴ�.
//void getEulerCircuit(int here, vector<int>& circuit) {
//	for (int there = 0; there < adj.size(); ++there) {
//		while (adj[here][there] > 0) {
//			adj[here][there]--;	//���� ������ ��� �����.
//			adj[there][here]--;
//			getEulerCircuit(there, circuit);
//		}
//	}
//	circuit.push_back(here);
//}