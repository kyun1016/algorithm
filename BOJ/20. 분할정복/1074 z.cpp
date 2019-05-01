//#include<iostream>
//
//using namespace std;
//
//void calc(int N, int r, int c) {
//	long long k;
//	long long mul;
//	long long ret = 0;
//
//
//	while (r) {
//		mul = 2;
//		for (k = 1; k <= r;k*=2) {
//			mul *= 4;
//		}
//		k /= 2;
//		mul /= 4;
//		ret += mul;
//		r -= k;
//	}
//
//
//	while (c) {
//		mul = 1;
//		for (k = 1; k <= c; k *= 2) {
//			mul *= 4;
//		}
//		k /= 2;
//		mul /= 4;
//		ret += mul;
//		c -= k;
//	}
//
//
//	cout << ret;
//}
//
//int main() {
//	int N, r, c;
//	
//	cin >> N >> r >> c;
//
//	calc(N, r, c);
//
//	return 0;
//}