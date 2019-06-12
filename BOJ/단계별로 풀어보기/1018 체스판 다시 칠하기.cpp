#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string board[51];

string object[2] = { "WBWBWBWB", "BWBWBWBW" };


int Min = 64;

void countChange(int start_x, int start_y) {
	int count = 0;
	for (int y = start_y; y < start_y + 8; y++)
		for (int x = start_x; x < start_x + 8; x++)
			if (object[y % 2][x - start_x] != board[y][x])
				count++;
	Min = min(Min, count);
	count = 0;
	for (int y = start_y; y < start_y + 8; y++)
		for (int x = start_x; x < start_x + 8; x++)
			if (object[(y + 1) % 2][x - start_x] != board[y][x])
				count++;
	Min = min(Min, count);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int y = 0; y <= N - 8; y++)
		for (int x = 0; x <= M - 8; x++)
			countChange(x, y);
		

	cout << Min << endl;
	

	return 0;
}