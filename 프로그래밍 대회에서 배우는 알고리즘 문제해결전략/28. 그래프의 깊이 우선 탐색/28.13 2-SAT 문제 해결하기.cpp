//#include<iostream>
//#include<vector>
//#include<stack>
//#include<algorithm>
//
//using namespace std;
//
////�׷����� ���� ����Ʈ ǥ��
//vector<vector<int> > adj;
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
//	//���ÿ� here�� �ִ´�. here�� �ļյ��� ��� ���ÿ��� here�Ŀ� ����.
//	st.push(here);
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		//(here, there)�� Ʈ�� ����
//		if (discovered[there] == -1)
//			ret = min(ret, scc(there));
//		//there�� �����ؾ� �ϴ� ���������� �ƴ϶��
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
//			if (t == here)
//				break;
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
//}
//
//
////adj�� ���� �׷����� ���� ����Ʈ ǥ���� �־��� ��, 2-SAT ������ ���� ��ȯ�Ѵ�.
//vector<int> solve2SAT() {
//	int n = adj.size() / 2;	//������ ��
//	//���� �׷����� �������� ������ ��Һ��� ���´�.
//	vector<int> label = tarjanSCC();
//	//�� SAT ������ Ǫ�� ���� �Ұ������� ȭ���Ѵ�. �� ������ ��Ÿ���� �� ������
//	//���� ������ ��ҿ� ���� ���� ��� ���� ����.
//	for(int i=0; i<2*n; i+= 2)
//		if(label[i] == label[i+1])
//			return vector<int>();
//	//SAT������ Ǫ�� ���� �����ϴ�. ���� ��������!
//	vector<int> value(2 * n, -1);
//	//Tarjan �˰��򿡼� SCC��ȣ�� ���� ������ �������� �����ȴ�.
//	//SCC ��ȣ�� �������� �� ������ �����ϸ� ���� ���� ������ �ȴ�.
//	vector<pair<int, int> > order;
//	for (int i = 0; i < 2 * n; i++)
//		order.push_back(make_pair(-label[i], i));
//	sort(order.begin(), order.end());
//	//�� ������ ���� �����Ѵ�.
//	for (int i = 0; i < 2 * n; i++) {
//		int vertex = order[i].second;
//		int variable = vertex / 2, isTrue = vertex % 2 == 0;
//		if (value[variable] != -1) continue;
//		// not A�� A���� ���� ���Դٸ� A�� ��
//		//A�� not A���� ���� ���Դٸ� A�� ����
//		value[variable] = !isTrue;
//	}
//	return value;
//}