#include<iostream>

using namespace std;

int N;
int cache[1000005];
const int INF = 15746;

int dfs(const int& N) {
	int& ret = cache[N];
	if (N == 1)
		return ret = 1;
	if (N == 2)
		return ret = 2;
	if (ret != 0)
		return ret;

	return ret = (dfs(N - 2) + dfs(N - 1)) % INF;
}

int main() {
	cin >> N;

	cout << dfs(N) << endl;
}