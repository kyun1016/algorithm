//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////�׷����� ���� ����Ʈ ǥ��
//vector<vector<int> > adj;
////discoverded[i]=i�� ������ �߰� ����
////finished[i]=dfs(i)�� ���������� 1, �ƴϸ� 0
//vector<int> discovered, finished;
////���ݱ��� �߰��� ������ ��
//int counter;
//
//void dfs2(int here) {
//	discovered[here] = counter++;
//	//��� ���� ������ ��ȸ�ϸ鼭
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		cout << "(" << here << "," << there << ") is a";
//		//���� �湮�� �� ���ٸ� �湮�Ѵ�.
//		if (discovered[there] == -1) {
//			cout << "tree edge" << endl;
//			dfs2(there);
//		}
//		else if (discovered[here] < discovered[there])
//			cout << "forward edge" << endl;
//		//���� dfs2(there)�� ���� �������� �ʾ����� there�� here�� ������.
//		else if (finished[there] == 0)
//			cout << "back edge" << endl;
//		//�� ���� ���� ��� ���� ����
//		else
//			cout << "cross edge" << endl;
//
//	}
//	finished[here] = 1;
//	//���� there�� here���� �ʰ� �߰ߵ����� there�� here�� �ļ��̴�.
//
//}