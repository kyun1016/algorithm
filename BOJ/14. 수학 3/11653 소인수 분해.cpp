//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N;
//	cin >> N;
//
//	if (N == 1)
//		return 0;
//	else {
//		for (int i = 2; i <= N; i++) {
//			while (N % i == 0) {
//				cout << i << "\n";
//				N /= i;
//			}
//		}
//	}
//
//	return 0;
//}