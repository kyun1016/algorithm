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
//		//bfs�� Ž��
//		while (!qu.empty()) {
//			//ü���� ������ ��� ����� ����
//			if (qu.front().first == goal) {
//				cout << qu.front().second << '\n';
//				break;
//			}
//
//			//���� ��ġ
//			int x = qu.front().first.first, y = qu.front().first.second;
//			int depth = qu.front().second + 1;
//			qu.pop();
//
//			//���� ��� : �̹� ������ ���
//			if (visited[x][y])
//				continue;
//			visited[x][y] = true;
//
//			//ť�� ������ �߰�(8�������� �̵�)
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