//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//int cache[501][501];
//vector<pair<int, int> > arr;
//int N;
//int INF = 2147483647;
//
//int dp(int begin, int end) {
//	int& ret = cache[begin][end];
//	if (ret != 0)
//		return ret;
//
//	if (begin == end)
//		return 0;
//
//	ret = INF;
//
//	for (int i = begin; i < end; i++) {
//		//하나의 행렬을 두개의 행렬로 나누어주자.
//		//그러면서 두개의 행렬을 곱한 값을 더해주는 것이 포인트이다.
//		ret = min(ret, dp(begin, i) + dp(i + 1, end) + arr[begin].first * arr[i].second * arr[end].second);
//	}
//	
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int a, b;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b;
//		arr.push_back({ a,b });
//	}
//
//	int ret = dp(0,N-1);
//
//		
//
//	cout << ret;
//	return 0;
//}