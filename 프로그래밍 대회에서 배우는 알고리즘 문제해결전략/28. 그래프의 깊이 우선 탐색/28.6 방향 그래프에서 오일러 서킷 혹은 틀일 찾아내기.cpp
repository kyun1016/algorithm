//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////�׷����� ���� ��� ǥ��. adj[i][j]=i�� j������ ������ ��
//vector<vector<int> > adj;
////indegree[i]=i�� �����ϴ� �ܾ��� ��
////outdegree[i]=i�� ������ �ܾ��� ��
//vector<int> indegree, outdegree;
//
////28.3 ���Ϸ� ��Ŷ
////#include<iostream>
////#include<vector>
////
////using namespace std;
////
//////�׷����� ���� ��� ǥ��. adj[i][j]=i�� j������ ������ ��
////vector<vector<int> > adj;
//////���� �׷����� ���� ��� adj�� �־��� �� ���Ϸ� ��Ŷ�� ����Ѵ�.
//////����� ������� circuit�� �������� ���Ϸ� ��Ŷ�� �ȴ�.
////void getEulerCircuit(int here, vector<int>& circuit) {
////	for (int there = 0; there < adj.size(); ++there) {
////		while (adj[here][there] > 0) {
////			adj[here][there]--;	//���� ������ ��� �����.
////			adj[there][here]--;
////			getEulerCircuit(there, circuit);
////		}
////	}
////	circuit.push_back(here);
////}
//
////����׷����� ���� ��� adj�� �־��� �� ���Ϸ� ��Ŷ Ȥ�� Ʈ������ ����Ѵ�.
//void getEulerCircuit(int here, vector<int>& circuit) {
//	for (int there = 0; there < adj.size(); there++) 
//		while (adj[here][there] > 0) {
//			adj[here][there]--;//������ �����
//			getEulerCircuit(there, circuit);
//		}
//	circuit.push_back(here);
//}
////���� �׷����� ���Ϸ� Ʈ�����̳� ��Ŷ�� ��ȯ�Ѵ�.
//vector<int> getEulerTrailOrCircuit() {
//	vector<int> circuit;
//	//�켱 Ʈ������ ã�ƺ���: �������� �����ϴ� ���
//	for (int i = 0; i < 26; i++)
//		if (outdegree[i] == indegree[i] + 1) {
//			getEulerCircuit(i, circuit);
//			return circuit;
//		}
//	//�ƴϸ� ��Ŷ�̴�, ������ ������ �ƹ� ���������� �����Ѵ�.
//	for(int i=0;i<26;i++)
//		if (outdegree[i]) {
//			getEulerCircuit(i, circuit);
//			return circuit;
//		}
//	//��� ������ ��� �� �迵�� ��ȯ�Ѵ�.
//	return circuit;
//}
//
