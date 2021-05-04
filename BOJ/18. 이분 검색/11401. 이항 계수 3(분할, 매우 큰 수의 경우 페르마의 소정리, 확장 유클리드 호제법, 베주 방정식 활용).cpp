//#include<iostream>
//
//using namespace std;
//typedef unsigned long long ull;
//
//ull N, K;
//ull factorial_list[4000001];
//ull inverse_mod_INF_list[4000001];
//ull INF = 1000000007;
//
//ull power(ull x, ull y) {    //���� ������ �̿��Ͽ� x^y ���ϱ�
//	ull ret = 1;
//	while (y > 0) {
//		if (y % 2) {
//			ret *= x;
//			ret %= INF;
//		}
//		x *= x;
//		x %= INF;
//		y /= 2;
//	}
//	return ret;
//}
//
//int main() {
//	//input
//	cin >> N >> K;
//
//	//factorial ���
//	factorial_list[1] = 1;
//	for (ull i = 2; i <= N; i++)
//		factorial_list[i] = (i * factorial_list[i - 1]) % INF;
//
//	//(inverse) % INF ���
//	inverse_mod_INF_list[0] = 1;
//	inverse_mod_INF_list[N] = power(factorial_list[N], INF - 2);
//	//���� ������� (1/N!)%INF�� ���� ���� �� �ִ�.
//	//���� ���������� (1/(N-i)!)%INF�� ���� ���س�����.
//	for (ull i = N - 1; i >= 1; i--) 
//		inverse_mod_INF_list[i] = (inverse_mod_INF_list[i + 1] * (i + 1)) % INF;
//	ull ret = (factorial_list[N]*inverse_mod_INF_list[N-K]) % INF;
//	ret = (ret*inverse_mod_INF_list[K]) % INF;
//	cout << ret << endl;
//
//	return 0;
//}