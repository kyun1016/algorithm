//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//void binarySearch(const int & N, const int & K) {
//	int first = 1;
//	int last = K;
//	int mid = 1;
//	int ret;
//	while (first <= last) {
//		int cnt = 0;
//		mid = (first + last) / 2;
//		for (int i = 1; i <= N; i++)
//			cnt += min(mid / i, N);
//		if (cnt < K)
//			first = mid + 1;
//		else {
//			ret = mid;
//			last = mid - 1;
//		}
//	}
//	cout << ret;
//	return;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N, K;
//	cin >> N >> K;
//
//	binarySearch(N, K);
//
//
//}