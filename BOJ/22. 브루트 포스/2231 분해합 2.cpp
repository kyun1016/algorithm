//#include<iostream>
//
//using namespace std;
//
//int N;
//
//int main() {
//	cin >> N;
//
//	for (int i = 1; i < N; i++) {
//		int i_sum = i;
//		int temp = i;
//		while (temp) {
//			i_sum += temp % 10;
//			temp /= 10;
//		}
//		if (i_sum == N) {
//			cout << i << endl;
//			return 0;
//		}
//	}
//
//	cout << 0 << endl;
//
//	return 0;
//}