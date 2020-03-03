//#include<iostream>
//#include<cstring>	//memset을 활용하기 위해 선언
//
//using namespace std;
//
//int arr[2000];
//
////cache[i][j] = i에서 j까지 팰린드롬인가?
//int cache[2000][2000];
//
//int dp(const int& front, const int& end) {
//	int& ret = cache[front][end];
//	
//	//기저 사례 : 이미 탐색을 한 구간인 경우
//	if (ret != -1)
//		return ret;
//
//	int size = front - end;
//
//	//기저 사례 : 구간의 길이가 0인 경우
//	if (size == 0)
//		return ret = 1;
//	//기저 사례 : 구간의 길이가 1인 경우
//	else if (size == 1) {
//		if (arr[front] == arr[end])
//			return ret = 1;
//	}
//	//구간의 길이가 1보다 큰 경우
//	else {
//		int before_step = dp(front + 1, end - 1);
//		if (before_step == 1 && arr[front] == arr[end]) {
//			return ret = 1;
//		}
//	}
//
//	return ret = 0;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N, M, a, b;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//
//	memset(cache, -1, sizeof(cache));
//
//
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> a >> b;
//		cout << dp(a - 1,b - 1) << "\n";
//	}
//
//}