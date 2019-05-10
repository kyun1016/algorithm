#include<iostream>
#include<queue>

using namespace std;

int tomatoBox[1003][1003];
int M, N, MAX;
int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };
queue<pair<int, int> > findHere;


int Max(int a, int b) {
	return a > b ? a : b;
}

//void find() {
//	int t =M*N;
//	while(t--)
//		for (int y = 1; y <= N; y++)
//			for (int x = 1; x <= M; x++) {
//				if (tomatoBox[y][x] > 0) {
//					for (int i = 0; i < 4; i++) {
//						if (tomatoBox[y + dirY[i]][x + dirX[i]] != 0)
//							continue;
//						tomatoBox[y + dirY[i]][x + dirX[i]] = tomatoBox[y][x] + 1;
//					}
//				}
//
//			}
//}

////내 일자보다 작은 일이라면 바로 return을 해버린다. 이미 거기서 발생되는 것들은 이미 다 탐색을 완료했기 때문이다.
//void DFS(int hereY, int hereX, int day=1) {
//	//기저 사례 : 토마토가 없는 곳이라면 바로 return으로 탐색을 종료한다.
//	if (tomatoBox[hereY][hereX] == -1)
//		return;
//	//기저 사례 : 지금 날짜보다 더 작은 날짜가 저장되어 있다면 탐색을 종료한다.
//	if (tomatoBox[hereY][hereX] < day && tomatoBox[hereY][hereX] != 0)
//		return;
//
//	//기저 사례에 걸리지 않은 토마토는 지금 날짜를 달아준다.(익는데까지 가장 최소의 시간)
//	tomatoBox[hereY][hereX] = day;
//	//Count++;
//	//4방향 탐색을 들어가자
//	for (int i = 0; i < 4; i++) {
//		int nextY = hereY + dirY[i], nextX = hereX + dirX[i];
//		//범위를 넘지 않도록 조건을 넣어준다.
//		if (nextY < N&&nextX < M && nextY >= 0 && nextX >= 0)
//			DFS(nextY, nextX, day + 1);
//	}	
//}

void BFS(int hereY, int hereX) {
	//4방향 탐색을 들어가자
	for (int i = 0; i < 4; i++) {
		int nextY = hereY + dirY[i], nextX = hereX + dirX[i];
		//범위를 넘지 않도록 조건을 넣어준다.
		if (nextY < N&&nextX < M && nextY >= 0 && nextX >= 0) {
			if (tomatoBox[nextY][nextX] == 0) {
				tomatoBox[nextY][nextX] = tomatoBox[hereY][hereX] + 1;
				findHere.push({ nextY, nextX });
			}
		}
			
	}	
}

int main() {
	cin >> M >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> tomatoBox[y][x];
			if (tomatoBox[y][x] == 1)
				findHere.push({ y,x });
		}

	//토마토가 들어있는 상자에서 모두 탐색을 하자! Yes!
	/*for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if(tomatoBox[y][x] == 1)
				DFS(y,x);*/

	//for (int i = 0; i < hereIsRoot.size(); i++)
	//	DFS(hereIsRoot[i].first, hereIsRoot[i].second);


	while (!findHere.empty()) {
		BFS(findHere.front().first, findHere.front().second);
		findHere.pop();
	}


	//토마토 상자 출력
	//for (int y = 0; y < N; y++) {
	//	for (int x = 0; x < M; x++)
	//		cout << tomatoBox[y][x] << " ";
	//	cout << endl;
	//}


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			//만일 익어있지 않은 토마토가 있다면 -1을 출력한다.
			if (tomatoBox[y][x] == 0) {
				cout << -1;
				return 0;
			}
			MAX = Max(MAX, tomatoBox[y][x]);
		}
	}


	cout << MAX - 1;
	return 0;
}