//#include<iostream>
//#include<vector>
//#include<stack>
//#include<algorithm>
//
//using namespace std;
//
////�׷����� ���� ����Ʈ ǥ��
//vector<vector<int> > adj;
////�� ������ ������Ʈ ��ȣ. ������Ʈ ��ȣ�� 0���� �����ϸ�,
////���� ������ ������Ʈ�� ���� �������� ������Ʈ ��ȣ�� ����.
//vector<int> sccId;
////�� ������ �߰� ����
//vector<int> discovered;
////������ ��ȣ�� ��� ����
//stack<int> st;
//int sccCounter, vertexCounter;
////here�� ��Ʈ�� �ϴ� ����Ʈ������ ������ �����̳� ���� ������
////���� �� �� �ִ� ���� �� �ּ� �߰� ������ ��ȯ�Ѵ�.
////(�̹� SCC�� ���� �������� ����� ���� ������ �����Ѵ�)
//int scc(int here) {
//	int ret = discovered[here] = vertexCounter++;
//	//���ÿ� here�� �ִ´�. here�� �ļյ��� ��� ���ÿ��� here �Ŀ� ����.
//	st.push(here);
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		//(here, there)�� Ʈ�� ����
//		if (discovered[there] == -1)
//			ret = min(ret, scc(there));
//		//there�� �����ؾ� �ϴ� ���� ������ �ƴ϶��
//		else if (sccId[there] == -1)
//			ret = min(ret, discovered[there]);
//	}
//	//here���� �θ�� �ö󰡴� ������ ����� ���� Ȯ���Ѵ�.
//	if (ret == discovered[here]) {
//		//here�� ��Ʈ�� �ϴ� ����Ʈ���� ���� �ִ� �������� ���� �ϳ��� ������Ʈ�� ���´�.
//		while (true) {
//			int t = st.top();
//			st.pop();
//			sccId[t] = sccCounter;
//			if (t == here) break;
//			
//		}
//		++sccCounter;
//	}
//	return ret;
//}
//
////tarjan�� SCC�˰���
//vector<int> tarjanSCC() {
//	//�迭���� ���� �ʱ�ȭ
//	sccId = discovered = vector<int>(adj.size(), -1);
//	//ī���� �ʱ�ȭ
//	sccCounter = vertexCounter = 0;
//	//��� ������ ���� scc() ȣ��
//	for (int i = 0; i < adj.size(); i++)
//		if (discovered[i] == -1)
//			scc(i);
//	return sccId;
//
//}
//
//
//
