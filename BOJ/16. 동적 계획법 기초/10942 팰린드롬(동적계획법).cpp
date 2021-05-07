//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//int N, M, S, E, arr[2002], cache[2002][2002];
//
//int dp(const int& start, const int& end) {
//	int& ret = cache[start][end];
//
//	// 기저 사례 : 이미 탐색을 한 구간인 경우
//	if (ret != -1)
//		return ret;
//
//	// 구간의 길이가 0 인 경우
//	if (start == end)
//		return ret = 1;
//	// 구간의 길이가 1인 경우
//	else if (end - start == 1) {
//		if (arr[start] == arr[end])
//			return ret = 1;
//	}	
//	// 구간의 길이가 1보다 큰 경우
//	else {
//		if (dp(start + 1, end - 1) && arr[start] == arr[end])
//			return ret = 1;
//	}
//
//	return ret = 0;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//		cin >> arr[i];
//
//	memset(cache, -1, sizeof(cache));
//
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> S >> E;
//		cout << dp(S, E) << '\n';
//	}
//
//	return 0;
//}