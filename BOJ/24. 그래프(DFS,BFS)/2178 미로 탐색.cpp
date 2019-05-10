#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int Y, X;
int dirY[4] = { 0,0,1,-1 };
int dirX[4] = { 1,-1,0,0 };
vector<string> maze;
queue<pair<int, int> > findHere;
bool visited[101][101];
int mazeDay[101][101];


void BFS(int hereY, int hereX) {
	for (int i = 0; i < 4; i++) {
		int nextY = hereY + dirY[i], nextX = hereX + dirX[i];
		if (nextY >= 0 && nextY < Y&&nextX >= 0 && nextX < X)
			if (!visited[nextY][nextX] && maze[nextY][nextX] == '1') {
				findHere.push({ nextY, nextX });
				visited[nextY][nextX] = true;
				mazeDay[nextY][nextX] = mazeDay[hereY][hereX] + 1;
			}
	}
}

int main() {
	cin >> Y >> X;
	string temp;
	for (int y = 0; y < Y; y++) {
		cin >> temp;
		maze.push_back(temp);
	}

	//초기 설정
	findHere.push({ 0,0 });
	mazeDay[0][0] = 1;
	visited[0][0] = true;
	
	while (!findHere.empty()) {
		BFS(findHere.front().first, findHere.front().second);
		findHere.pop();
	}


	cout << mazeDay[Y-1][X-1];

}