//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int arr[1001];
//int N;
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
//	sort(arr, arr + N);
//
//	int ret = 0;
//	for (int i = 0; i < N; i++) {
//		ret += arr[i] * (N - i);
//	}
//
//	cout << ret;
//
//	return 0;
//}