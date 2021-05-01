#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[505][505];
int cache[505][505];

int dfs(const int& depth, const int& pos) {
	int& ret = cache[depth][pos];
	if (ret != 0)
		return ret;
	if (depth == N)
		return 0;
	int temp = max(dfs(depth + 1, pos), dfs(depth + 1, pos + 1));
	return ret = arr[depth][pos] + temp;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x <= y; x++)
			cin >> arr[y][x];

	cout << dfs(0,0) << endl;
	
	return 0;
}