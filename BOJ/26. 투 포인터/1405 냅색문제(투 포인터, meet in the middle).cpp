//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, C, arr[31];
//vector<long long> Left, Right;
//
//void dfs(const int& start, const int& end, const long long& sum, vector<long long> &v) {
//	if (sum > C)
//		return;
//	if (start == end) {
//		if (sum != 0) v.push_back(sum);
//		return;
//	}
//	//�̹� ���� �������� �ʴ� ���
//	dfs(start + 1, end, sum, v);
//	//�����ϴ� ���
//	dfs(start + 1, end, sum+ arr[start], v);
//}
//
//int main() {
//	cin >> N >> C;
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//
//	dfs(0, N / 2, 0, Left);
//	dfs(N/2, N, 0, Right);
//
//	long long ans = (long long)Left.size() + (long long)Right.size();
//	sort(Right.begin(), Right.end());
//
//	//�̺�Ž��
//	for (int i = 0; i < Left.size(); i++) {
//		//gap�� ũ�⺸�� ���� ������ Right ���ҵ��� 
//		//Left�� �����Ͽ� ���ο� ����Ǽ��� ������.
//		long long gap = C - Left[i];
//
//		//upper_bound�� Ȱ��
//		//lower_bound�� ��� ���� �ּ��� �κ��� ����Ű�Ƿ� �Ұ����ϴ�.
//		long long count = upper_bound(Right.begin(), Right.end(), gap) - Right.begin();
//
//		ans += count;
//	}
//
//	//�ƹ��͵� �������� ���� ��츦 �߰����ش�.
//	cout << ans + 1  << '\n';
//
//	return 0;
//}