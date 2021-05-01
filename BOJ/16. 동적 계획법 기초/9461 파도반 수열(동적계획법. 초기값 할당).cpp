#include<iostream>

using namespace std;

int T, N;
long long cache[150];

//ver.1
long long dfs(const int& depth) {
	long long& ret = cache[depth];
	if (ret != 0)
		return ret;
	
	return ret = dfs(depth - 1) + dfs(depth - 5);
}


int main() {
	cin >> T;
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 1;
	cache[4] = 2;
	cache[5] = 2;
	cache[6] = 3;
	////ver.2
	for (int i = 7; i < 101; i++) {
		cache[i] = cache[i - 1] + cache[i - 5];
	}
	while (T--) {
		cin >> N;
		cout << cache[N] << endl;
		//ver.1
		//cout << dfs(N) << endl;
	}
}