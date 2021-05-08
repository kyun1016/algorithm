//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, C, arr[31];
//vector<long long> Left, Right;
//
//void dfs(const int& start, const int& end, const long long& sum, vector<long long> &v) {
//	if (sum > C)
//		return;
//	if (start == end) {
//		if (sum != 0) v.push_back(sum);
//		return;
//	}
//	//이번 것을 포함하지 않는 경우
//	dfs(start + 1, end, sum, v);
//	//포함하는 경우
//	dfs(start + 1, end, sum+ arr[start], v);
//}
//
//int main() {
//	cin >> N >> C;
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//
//	dfs(0, N / 2, 0, Left);
//	dfs(N/2, N, 0, Right);
//
//	long long ans = (long long)Left.size() + (long long)Right.size();
//	sort(Right.begin(), Right.end());
//
//	//이분탐색
//	for (int i = 0; i < Left.size(); i++) {
//		//gap의 크기보다 작은 범위의 Right 원소들은 
//		//Left와 조합하여 새로운 경우의수를 만들어낸다.
//		long long gap = C - Left[i];
//
//		//upper_bound를 활용
//		//lower_bound의 경우 가장 최소인 부분을 가리키므로 불가능하다.
//		long long count = upper_bound(Right.begin(), Right.end(), gap) - Right.begin();
//
//		ans += count;
//	}
//
//	//아무것도 포함하지 않은 경우를 추가해준다.
//	cout << ans + 1  << '\n';
//
//	return 0;
//}