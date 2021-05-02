#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[305];
int cache[305][2];

int dfs(const int& depth, const int& consequence) {
	int& ret = cache[depth][consequence];
	
	if (ret != 0)
		return ret;
	else if (depth == N)
		return ret = arr[depth];
	else if (depth == N + 1)
		return ret = -987654321;
	
	if (consequence == 0)
		return ret = arr[depth] + max(dfs(depth + 1, 1), dfs(depth + 2, 0));
	else
		return ret = arr[depth] + dfs(depth + 2, 0);
}

int	main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	cout << max(dfs(1,0), dfs(2,0)) << endl;

	//for (int i = 0; i <= N; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		cout << cache[i][j] << " ";
	//	}
	//	cout << endl;
	//}

}