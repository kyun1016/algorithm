//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//int cost[11];
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N, object;
//	cin >> N >> object;
//	for (int i = 0; i < N; i++) {
//		cin >> cost[i];
//	}
//
//	int ret = 0;
//	for (int i = N - 1; i >= 0; i--) {
//		if (object == 0)
//			break;
//		while (object >= cost[i]) {
//			object -= cost[i];
//			ret++;
//		}
//
//	}
//
//	cout << ret;
//
//	return 0;
//}