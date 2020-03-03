#include<iostream>
#include<cstring>

using namespace std;

int arr[50][50];
int ret = 0;
int T, N, M, K, X, Y;


void dfs(const int& x, const int& y) {
	arr[x][y] = ret;
	if (x > 0 && arr[x - 1][y] == -1)
		dfs(x - 1, y);
	if (x < M - 1 && arr[x + 1][y] == -1)
		dfs(x + 1, y);
	if (y > 0 && arr[x][y - 1] == -1)
		dfs(x, y - 1);
	if (y < N - 1 && arr[x][y + 1] == -1)
		dfs(x, y + 1);
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		//배열을 0으로 초기화
		memset(arr, 0, sizeof(arr));
		//
		ret = 0;

		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			arr[X][Y] = -1;
		}
		for(int x=0;x<M;x++)
			for(int y=0;y<N;y++)
				if (arr[x][y] == -1) {
					ret++;
					dfs(x, y);
				}
		cout << ret << endl;
	}



}