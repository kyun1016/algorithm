////���Ŀ� �ӵ��� ���̱� ���ؼ�, 3���� �ּҰ������ Ȱ���Ѵٴ� ���̵� ������ ������
//
//#include<iostream>
//
//using namespace std;
//
//int SEM(int S, int E, int M) {
//	int ret = 1;
//	if (S == 365)
//		S = 0;
//	if (E == 24)
//		E = 0;
//	if (M == 29)
//		M = 0;
//	while (1) {
//		if (ret % 365 == S && ret % 24 == E && ret % 29 == M)
//			break;
//		ret++;
//	}
//	return ret;
//}
//
//
//
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int T, S, E, M;
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//		cin >> S >> E >> M;
//		cout << "#" << i << " " << SEM(S, E, M) << endl;
//	}
//
//	return 0;
//
//}