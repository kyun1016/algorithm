
//초기 구성이었는데, 이게 페이지가 바뀌면 않되는 초기 설정이 있었다.

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//vector<int> cost;
//vector<int> cache;
//int SUM;
//
//void sum_file() {
//	vector<int>::iterator it = cost.begin();
//	int a, b;
//	a = cost[0];
//	b = cost[1];
//	it = cost.insert(it, a + b);
//	it = cost.erase(++it);
//	it = cost.erase(it);
//	SUM += a + b;
//}
//
//
//int main() {
//	int T, K,temp;
//	cin >> T;
//	while (T--) {
//		cin >> K;
//		SUM = 0;
//		for (int i = 0; i < K; i++) {
//			cin >> temp;
//			cost.push_back(temp);
//		}
//		for (int i = 1; i < K; i++) {
//			sort(cost.begin(), cost.end());
//			sum_file();
//		}
//		cout << SUM << endl;
//		cost.pop_back();
//	}
//
//
//}



//O(n3)의 구현, 합치는데 필요한 모든값을 더하면서 답을 구해낸다ㅓ.

//#include<iostream>
//#include <algorithm>
//
//int INF = 1000000007;
//using namespace std;
//
//int dp[501][501];
//int cost[501];
//int sum[501];
//int T, K, i;
//
//int main() {
//	cin >> T;
//	while (T--) {
//		cin >> K;
//		for (i = 1; i <= K; ++i) {
//			cin >> cost[i];
//			sum[i] = sum[i - 1] + cost[i];
//		}
//
//		for (int d = 1; d < K; ++d) {
//			for (int tx = 1; tx + d <= K; ++tx) {
//				int ty = tx + d;
//				dp[tx][ty] = INF;
//
//				for (int mid = tx; mid < ty; ++mid)
//					dp[tx][ty] =
//					min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
//			}
//		}
//
//		cout << dp[1][K] << endl;
//	}
//	return 0;
//}



//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int cost[501];
//int cache[501];
//
//
//int sum_file(int i, int K) {
//	int &ret = cache[i];
//	if (ret != 0)
//		return ret;
//	ret += cost[i];
//	if (i == K)
//		return ret;
//	if (i == K - 1)
//		return ret += cost[i + 1];
//	if(i <= K - 2)
//		ret += min(sum_file(i + 1, K), cost[i + 1] + sum_file(i + 2, K));
//	cout << "이번 ret은 : " << ret << endl;
//	return ret;
//}
//
//
//int main() {
//	int T, K,temp;
//	cin >> T;
//	while (T--) {
//		cin >> K;
//		memset(cost, -1, sizeof(cost));
//		memset(cache, 0, sizeof(cache));
//		for (int i = 1; i <= K; i++) {
//			cin >> cost[i];
//		}
//
//		cout << sum_file(1, K) << endl;
//	}
//
//
//}