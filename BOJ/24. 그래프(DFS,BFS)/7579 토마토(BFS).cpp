#include<iostream>
#include<queue>

using namespace std;

int tomatoBox[102][102][101];
int Y, X, H, MAX;
int dirX[6] = { 0, 0, 1, -1,0,0 };
int dirY[6] = { 1, -1, 0, 0,0,0 };
int dirH[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int> > findHere;


int Max(int a, int b) {
	return a > b ? a : b;
}

void BFS(int hereY, int hereX, int hereH) {
	//6방향 탐색을 들어가자
	for (int i = 0; i < 6; i++) {
		int nextY = hereY + dirY[i], nextX = hereX + dirX[i], nextH = hereH + dirH[i];
		//범위를 넘지 않도록 조건을 넣어준다.
		if (nextY < Y&&nextX < X && nextY >= 0 && nextX >= 0 && nextH >= 0 && nextH < H) {
			if (tomatoBox[nextY][nextX][nextH] == 0) {
				tomatoBox[nextY][nextX][nextH] = tomatoBox[hereY][hereX][hereH] + 1;
				findHere.push({{ nextY, nextX }, nextH});
			}
		}

	}
}

int main() {
	cin >> X >> Y >> H;
	for (int h = 0; h < H; h++)
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
			{
				cin >> tomatoBox[y][x][h];
				if (tomatoBox[y][x][h] == 1)
					findHere.push({{ y,x }, h});
			}


	while (!findHere.empty()) {
		BFS(findHere.front().first.first, findHere.front().first.second, findHere.front().second);
		findHere.pop();
	}

	for (int h = 0; h < H; h++)
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
			{
				if (tomatoBox[y][x][h] == 0) {
					cout << -1;
					return 0;
				}
				MAX = Max(MAX, tomatoBox[y][x][h]);
			}

	cout << MAX - 1;
	return 0;
}