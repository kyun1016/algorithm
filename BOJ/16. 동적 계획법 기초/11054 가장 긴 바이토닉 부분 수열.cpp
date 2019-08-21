//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//
//using namespace std;
//
//typedef unsigned long long ull;
//
////int cache[1001];
//int decrease[1001];
//int increase[1001];
//int arr[1001];
//int N;
//
////int dp(int start, int here, int left, int right) {
////	int& ret = cache[start];
////	if (ret != 0)
////		return ret;
////	ret = 1;
////	for (int next = here + 1; next < N; next++) {
////		if (arr[left] < arr[next])
////			ret = max(ret, dp(next) + 1);
////	}
////
////	return ret;
////}
//
//int calcDecrease(int here) {
//	int& ret = decrease[here];
//	if (ret != 0)
//		return ret;
//	ret = 1;
//	for (int i = here + 1; i < N; i++) {
//		if (arr[here] > arr[i]) {
//			ret = max(ret, 1 + calcDecrease(i));
//		}
//	}
//	return ret;
//}
//
//int calcIncrease(int here) {
//	int& ret = increase[here];
//	if (ret != 0)
//		return ret;
//	ret = 1;
//	for (int i = here - 1; i >= 0; i--) {
//		if (arr[here] > arr[i]) {
//			ret = max(ret, 1 + calcIncrease(i));
//		}
//	}
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = 0; i < N; i++) {
//		calcDecrease(i);
//		calcIncrease(i);
//	}
//
//	int ret = 0;
//	for (int i = 0; i < N; i++) {
//		ret = max(ret, increase[i] + decrease[i] - 1);
//	}
//
//	cout << ret;
//	return 0;
//}