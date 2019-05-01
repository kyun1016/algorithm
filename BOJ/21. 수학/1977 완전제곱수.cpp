//#include<iostream>
//
//using namespace std;
//
//void calc(int min, int max) {
//	int ret = -1, sum = 0;
//	for (int i = 1; i <= 100; i++) {
//		if (i*i >= min && i*i <= max) {
//			sum += i * i;
//			if (ret == -1)
//				ret = i * i;
//		}
//	}
//	if (ret == -1)
//		cout << ret;
//	else
//		cout << sum << endl << ret;
//}
//
//int main() {
//	int m, n;
//	cin >> m >> n;
//	calc(m, n);
//
//
//	return 0;
//
//
//}