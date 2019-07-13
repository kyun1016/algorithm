//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int N;
//int arr[1001];
//int cache[1001][1001];
//
//int playGame(const int& front, const int& end) {
//	int turn = (N - (front - end)) % 2;
//
//
//	int& ret = cache[front][end];
//	if (ret != -1)
//		return ret;
//
//	ret = 0;
//	if (front == end) 
//		if (turn)
//			return ret = arr[front];
//		return ret;
//
//	if (turn) 
//		ret = max(playGame(front + 1, end)+arr[front], playGame(front, end - 1) + arr[end]);
//	else 
//		ret = min(playGame(front + 1, end), playGame(front, end - 1));
//	
//	
//
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			cin >> arr[i];
//		}
//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cache[i][j] = -1;
//			}
//		}
//
//		cout << playGame(0, N-1) << endl;
//	}
//
//	return 0;
//}
//
//
////#include<cstdio>
////#include<algorithm>
////#include<iostream>
////
////using namespace std;
////
////int n, sum[1003], dp[1003][1003];
////int main()
////{
////	int t;
////	scanf("%d", &t);
////	while (t--)
////	{
////		scanf("%d", &n);
////		for (int i = 1; i <= n; i++)
////		{
////			scanf("%lld", &sum[i]);
////			sum[i] += sum[i - 1];
////		}
////		for (int l = 1; l <= n; l++)
////			for (int i = 1, j = l; j <= n; i++, j++) {
////				dp[i][j] = sum[j] - sum[i - 1] - std::min(dp[i + 1][j], dp[i][j - 1]);
////				cout << dp[i][j] << " " << dp[i+1][j] << " " << dp[i][j-1] << endl;
////			}
////		printf("%d\n", dp[1][n]);
////	}
////}