#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<pair<int, int> > V;
int up_cache[101], down_cache[101];

//오름차순으로 계속 큰 전깃줄로 이동하여 체크한다.
int lis(int start) {
	int& ret = up_cache[start];
	if (ret != 0)
		return ret;
	ret = 1;
	for (int next = start + 1; next < N; next++)
		if (V[start].second < V[next].second)
			ret = max(ret, lis(next) + 1);
	return ret;
}

//계속 작아지는 방향으로 체크
int lis2(int start) {
	int& ret = down_cache[start];
	if (ret != 0)
		return ret;
	ret = 1;
	for (int next = start - 1; next >= 0; next--)
		if (V[start].second > V[next].second)
			ret = max(ret, lis2(next) + 1);
	return ret;
}

int main() {
	//input
	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++)
		cin >> V[i].first >> V[i].second;

	//calc
	sort(V.begin(), V.end());
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret = max(ret, max(lis(i), lis2(i)));
	}

	//output
	cout << N-ret << endl;

	return 0;
}