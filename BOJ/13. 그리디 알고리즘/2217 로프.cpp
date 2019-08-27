//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int arr[100001];
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
//
//	for (int i = 0; i < N; i++) {
//		if (ret < (N - i) * arr[i])
//			ret = (N - i) * arr[i];
//	}
//
//	cout << ret;
//
//	return 0;
//}