#include<iostream>
#include<cstring>


using namespace std;
typedef unsigned long long ull;

int N;
int board[101][101];
ull cache[101][101];

void jump(int y, int x) {
	//기저 사례
	if (y >= N || x >= N) return;
	////메모이제이션
	//ull& ret = cache[y][x];
	//if (ret != -1) return ret;
	int jumpSize = board[y][x];
	if (jumpSize == 0)
		return;
	if (y + jumpSize < N && x < N) {
		cache[y + jumpSize][x] += cache[y][x];
		//cout << "jump x: " << x << " y:" << y << "to x : " << x << "y : " << y + jumpSize << endl;
		jump(y + jumpSize, x);
	}
	if (y< N && x + jumpSize < N) {
		cache[y][x + jumpSize] += cache[y][x];
		//cout << "jump x: " << x << " y:" << y << "to x : " << x + jumpSize << "y : " << y<< endl;
		jump(y, x + jumpSize);
	}
}

int main() {
	
	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];
	//memset(cache, -1, sizeof(cache));
	cache[0][0] = 1;
	jump(0, 0);
	cout << cache[N-1][N-1];
	
	return 0;
}