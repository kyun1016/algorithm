//#include<iostream>
//
//using namespace std;
//
//long long arr[101];
//
//void wave() {
//	arr[1] = arr[2] = arr[3] = 1;
//	arr[4] = arr[5] = 2;
//	for (int n = 6; n <= 100; n++) {
//		arr[n] = arr[n - 1] + arr[n - 5];
//	}
//}
//
//int main() {
//	int T, N;
//	cin >> T;
//	wave();
//	while (T--) {
//		cin >> N;
//		cout << arr[N] << endl;
//	}
//}
//
