#include<iostream>

using namespace std;

int T, N;

int cache[50][2];

int dfs_0(const int& depth) {
	int& ret = cache[depth][0];

	//±âÀú »ç·Ê
	if (depth == 0)
		return ret = 1;
	if (depth == 1)
		return ret = 0;
	if (ret != 0)
		return ret;

	return ret = dfs_0(depth - 1) + dfs_0(depth - 2);
}

int dfs_1(const int& depth) {
	int& ret = cache[depth][1];

	//±âÀú »ç·Ê
	if (depth == 0)
		return ret = 0;
	if (depth == 1)
		return ret = 1;
	if (ret != 0)
		return ret;

	return ret = dfs_1(depth - 1) + dfs_1(depth - 2);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cache[0][0] = 1;
	cache[1][1] = 1;

	//input
	cin >> T;
	while (T--) {
		cin >> N;

		//calc
		dfs_0(N);
		dfs_1(N);

		//output
		cout << cache[N][0] << ' ' << cache[N][1] << "\n";
	}

	return 0;
}