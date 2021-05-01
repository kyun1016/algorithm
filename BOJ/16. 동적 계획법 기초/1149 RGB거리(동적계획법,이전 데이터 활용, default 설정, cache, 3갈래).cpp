#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1005][3];
int cache[1005][3];

int dfs(const int& depth, const int& color) {
	int& ret = cache[depth][color];
	if (depth == N)
		return ret = arr[depth][color];
	if (ret != 0)
		return ret;

	//가장 처음 시작 default
	if (depth == 0) {
		int temp = dfs(depth + 1, 0);
		temp = min(temp, dfs(depth + 1, 1));
		temp = min(temp, dfs(depth + 1, 2));
		return ret = temp;
	}

	else if (color == 0)
		return ret = arr[depth][color] + min(dfs(depth + 1, 1), dfs(depth + 1, 2));
	else if (color == 1)
		return ret = arr[depth][color] + min(dfs(depth + 1, 0), dfs(depth + 1, 2));
	else if (color == 2)
		return ret = arr[depth][color] + min(dfs(depth + 1, 0), dfs(depth + 1, 1));
}

int main() {
	//input
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	cout << dfs(0,0);
}