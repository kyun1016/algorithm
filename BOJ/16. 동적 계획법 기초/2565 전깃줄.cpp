//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//int cache[101][501];
//vector<pair<int, int> > arr;
//int N;
//
////�����غ���.
////������ �� ��, ������ �� �ְ�, ���� �������� �ִ�.
////ù ������ �����ϸ�, �� ���� ������ ���� ������ ������ �� ū ������ Ȯ�����ش�.
////�� ū ��쿡�� ������ �� ����, ���� �������� �ִ� ���� �ݺ��� ������.
//int linkLine(int here = 0, int before=0) {
//	//�޸������̼��� Ȱ������.
//	int& ret = cache[here][before];
//	//���� ���: �̹� �� ������ �ִ� ������ ���� ���
//	if (ret != -1)
//		return ret;
//	//���� ���: ��� ������ ������ �湮�� ���
//	if (here >= N)
//		return 0;
//	
//	ret = 0;
//	//������ �ϴ� ���, ������ �����ϴ��� Ȯ������.
//	if (before < arr[here].second)
//		//������ �� �� �ִ� �������, ���� �ʴ� ���� �� Ŭ �� �����Ƿ� ���� �ʴ°͵� ���� �˻����ش�.
//		ret = max(1 + linkLine(here + 1, arr[here].second), linkLine(here + 1, before));
//	//������ �Ұ����� ���� �׳� ���� ���� Ȯ���Ϸ� �Ѿ��.
//	else
//		ret = max(ret, linkLine(here + 1, before));
//
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int a, b;
//	cin >> N;
//	//��� �������� �̹� Ǯ�̿��� �߿�ġ �ʴ�.
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b;
//		arr.push_back({ a,b });
//	}
//
//	sort(arr.begin(), arr.end());
//	for (int i = 0; i <= N; i++) {
//		for (int j = 0; j <= 500; j++) {
//			cache[i][j] = -1;
//		}
//	}
//
//	int ret = linkLine();
//
//	cout << N - ret;
//	return 0;
//}