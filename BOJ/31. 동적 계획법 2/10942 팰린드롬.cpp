//#include<iostream>
//#include<cstring>	//memset�� Ȱ���ϱ� ���� ����
//
//using namespace std;
//
//int arr[2000];
//
////cache[i][j] = i���� j���� �Ӹ�����ΰ�?
//int cache[2000][2000];
//
//int dp(const int& front, const int& end) {
//	int& ret = cache[front][end];
//	
//	//���� ��� : �̹� Ž���� �� ������ ���
//	if (ret != -1)
//		return ret;
//
//	int size = front - end;
//
//	//���� ��� : ������ ���̰� 0�� ���
//	if (size == 0)
//		return ret = 1;
//	//���� ��� : ������ ���̰� 1�� ���
//	else if (size == 1) {
//		if (arr[front] == arr[end])
//			return ret = 1;
//	}
//	//������ ���̰� 1���� ū ���
//	else {
//		int before_step = dp(front + 1, end - 1);
//		if (before_step == 1 && arr[front] == arr[end]) {
//			return ret = 1;
//		}
//	}
//
//	return ret = 0;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N, M, a, b;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//
//	memset(cache, -1, sizeof(cache));
//
//
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> a >> b;
//		cout << dp(a - 1,b - 1) << "\n";
//	}
//
//}