//#include<vector>
//#include<iostream>
//#include<queue>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
////perm�� �����ϱ� ���� �Ƿ��� �ּ� ������ ������ ���� ����Ѵ�.
//int bfs(const vector<int>& perm) {
//	int n = perm.size();
//	//��ǥ ������ �̸� ����Ѵ�.
//	vector<int> sorted = perm;
//	sort(sorted.begin(), sorted.end());
//	//�湮 ���(ť)�� ���������� �� ���������� �Ÿ�
//	queue<vector<int> > q;
//	map<vector<int>, int> distance;
//	//�������� ť�� �ִ´�.
//	distance[perm] = 0;
//	q.push(perm);
//	while (!q.empty()) {
//		vector<int> here = q.front();
//		q.pop();
//		//��ǥ ������ �߰������� ���� �����Ѵ�.
//		if (here == sorted) return distance[here];
//		int cost = distance[here];
//		//������ ��� �κ� ������ ������ ����.
//		for(int i=0;i<n;i++)
//			for (int j = i + 2; j <= n; j++) {
//				reverse(here.begin() + i, here.begin() + j);
//				if (distance.count(here) == 0) {
//					distance[here] = cost + 1;
//					q.push(here);
//				}
//				reverse(here.begin() + i, here.begin() + j);
//			}
//	}
//	//oops
//	return -1;
//}
//
//
//
//////�ڵ� 29.4 Sorting Game ������ ������ �ذ��ϴ� �ʺ� �켱 Ž���� ����
//map<vector<int>, int> toSort;
////[0,...n-1]�� ��� ������ ���� toSort[]�� ����� �����Ѵ�.
//void precalc(int n) {
//	vector<int> perm(n);
//	for (int i = 0; i < n; i++)  perm[i] = i;
//	queue<vector<int> > q;
//	q.push(perm);
//	toSort[perm] = 0;
//	while (!q.empty()) {
//		vector<int> here = q.front();
//		q.pop();
//		int cost = toSort[here];
//		for (int i = 0; i < n; i++)
//			for (int j = i + 2; j <= n; j++) {
//				reverse(here.begin() + i, here.begin() + j);
//				if (toSort.count(here) == 0) {
//					toSort[here] = cost + 1;
//					q.push(here);
//				}
//				reverse(here.begin() + i, here.begin() + j);
//			}
//
//
//	}
//	
//}
//
//int solve(const vector<int>& perm) {
//	//perm�� [0,...,n-1]�� ������ ��ȯ�Ѵ�.
//	int n = perm.size();
//	vector<int> fixed(n);
//	for (int i = 0; i < n; i++) {
//		int smaller = 0;
//		for (int j = 0; j < n; j++)
//			if (perm[j] < perm[i])
//				++smaller;
//		fixed[i] = smaller;
//	}
//	return toSort[fixed];
//}