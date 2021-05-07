//#include<iostream>
//#include<queue>
//#include<cstring>
//
//using namespace std;
//
//int T, L;
//pair<int, int> start, goal;
//bool visited[301][301];
//
//int main() {
//	cin >> T;
//	while (T--) {
//		//input
//		cin >> L;
//		cin >> start.first >> start.second;
//		cin >> goal.first >> goal.second;
//
//		//calc
//		queue<pair<pair<int, int>, int> > qu;
//		memset(visited, false, sizeof(visited));
//		qu.push({ start, 0 });
//
//		//bfs로 탐색
//		while (!qu.empty()) {
//			//체스로 도착한 경우 출력후 종료
//			if (qu.front().first == goal) {
//				cout << qu.front().second << '\n';
//				break;
//			}
//
//			//현재 위치
//			int x = qu.front().first.first, y = qu.front().first.second;
//			int depth = qu.front().second + 1;
//			qu.pop();
//
//			//기저 사례 : 이미 도착한 경우
//			if (visited[x][y])
//				continue;
//			visited[x][y] = true;
//
//			//큐에 데이터 추가(8방향으로 이동)
//			if (x + 2 < L && y + 1 < L)
//				qu.push({ {x + 2, y + 1}, depth });
//			if (x + 1 < L && y + 2 < L)
//				qu.push({ {x + 1, y + 2}, depth });
//
//			if (x + 2 < L && y - 1 >= 0)
//				qu.push({ {x + 2, y - 1}, depth });
//			if (x + 1 < L && y - 2 >= 0)
//				qu.push({ {x + 1, y - 2}, depth });
//
//			if (x - 2 >= 0 && y - 1 >= 0)
//				qu.push({ {x - 2, y - 1}, depth });
//			if (x - 1 >= 0 && y - 2 >= 0)
//				qu.push({ {x - 1, y - 2}, depth });
//
//			if (x - 2 >= 0 && y + 1 < L)
//				qu.push({ {x - 2, y + 1}, depth });
//			if (x - 1 >= 0 && y + 2 < L)
//				qu.push({ {x - 1, y + 2}, depth });
//		}
//	}
//
//	return 0;
//}