//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////�׷����� ���� ����Ʈ ǥ��
//vector<vector<int> > adj;
////�� ������ �߰� ����. -1�� �ʱ�ȭ�Ѵ�.
//vector<int> discovered;
////�� ������ ���������� ���θ� �����Ѵ�. false�� �ʱ�ȭ�Ѵ�.
//vector<bool> isCutVertex;
//int counter = 0;
////here�� ��Ʈ�� �ϴ� ����Ʈ���� �ִ� ���������� ã�´�.
////��ȯ ���� �ش� ����Ʈ������ ������ �������� �� �� �ִ� ���� ��
////���� ���� �߰ߵ� ������ �߰� ����. ó�� ȣ���� ���� isRoot=true�� �д�.
//int findCutVertex(int here, bool isRoot) {
//	//�߰� ������ ����Ѵ�.
//	discovered[here] = counter++;
//	int ret = discovered[here];
//	//��Ʈ�� ����� ������ ������ ���� �ڼ� ����Ʈ���� ������ ����.
//	int children = 0;
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		if (discovered[there] == -1) {
//			++children;
//			//�� ����Ʈ������ �� �� �ִ� ���� ���� ������ ��ȣ
//			int subtree = findCutVertex(there, false);
//			//�� ��尡 �ڱ� �ڽ� ���Ͽ� �ִٸ� ���� ��ġ�� ������!
//			if (!isRoot && subtree >= discovered[here])
//				isCutVertex[here] = true;
//			ret = min(ret, subtree);
//		}
//		else
//			ret = min(ret, discovered[there]);
//	}
//	//��Ʈ�� ��� ������ ������ ����Ʈ���� ������ �Ѵ�.
//	if (isRoot) isCutVertex[here] = (children >= 2);
//	return ret;
//
//}