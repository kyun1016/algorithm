//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//int T, K, cache[502][502], sum[501];
//const int INF = 987654321;
//
//int main() {
//	cin >> T;
//	while (T--) {
//		cin >> K;
//		
//		int temp;
//		for (int i = 1; i <= K; i++) {
//			cin >> temp;
//			sum[i] = sum[i - 1] + temp;
//		}
//			
//		
//		for(int length=1;length<K;length++)
//			for (int start = 1; start <= K-length; start++) {
//				int end = start + length;
//				cache[start][end] = INF;
//				for (int mid = start; mid < end; mid++) {
//					cache[start][end] = min(cache[start][end], cache[start][mid] + cache[mid+1][end] + (sum[end] - sum[start - 1]));
//				}
//			}
//
//		cout << cache[1][K] << '\n';
//	}
//
//	return 0;
//}