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
//ull power(ull x, ull y) {    //분할 정복을 이용하여 x^y 구하기
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
//	//factorial 계산
//	factorial_list[1] = 1;
//	for (ull i = 2; i <= N; i++)
//		factorial_list[i] = (i * factorial_list[i - 1]) % INF;
//
//	//(inverse) % INF 계산
//	inverse_mod_INF_list[0] = 1;
//	inverse_mod_INF_list[N] = power(factorial_list[N], INF - 2);
//	//위의 계산으로 (1/N!)%INF의 값을 구할 수 있다.
//	//이제 연쇄적으로 (1/(N-i)!)%INF의 값을 구해나가자.
//	for (ull i = N - 1; i >= 1; i--) 
//		inverse_mod_INF_list[i] = (inverse_mod_INF_list[i + 1] * (i + 1)) % INF;
//	ull ret = (factorial_list[N]*inverse_mod_INF_list[N-K]) % INF;
//	ret = (ret*inverse_mod_INF_list[K]) % INF;
//	cout << ret << endl;
//
//	return 0;
//}