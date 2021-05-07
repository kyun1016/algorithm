//#include<iostream>
//#include<string>
//#include<queue>
//
//using namespace std;
//
//int N, M;
//bool arr[1001][1001];
//bool visited[1001][1001][2];
//string temp;
//queue<pair<pair<int, int>, pair<int, int> > > qu;
//
//int main() {
//	cin >> N >> M;
//	for (int y = 0; y < N; y++) {
//		cin >> temp;
//		for (int x = 0; x < M; x++)
//			if (temp[x] == '0')
//				arr[y][x] = false;
//			else
//				arr[y][x] = true;
//	}
//	
//	qu.push({ {0,0}, {0,0} });
//		
//	while (!qu.empty()) {
//		int y = qu.front().first.first, x = qu.front().first.second, depth = qu.front().second.second;
//		int crash = qu.front().second.first;
//		qu.pop();
//
//		if (visited[y][x][crash])
//			continue;
//
//		visited[y][x][crash] = true;
//		//cout << x << " " << y << " " << depth << endl;
//
//		if (y == N-1 && x == M-1) {
//			cout << depth+1 << endl;
//			return 0;
//		}
//
//		depth++;
//
//		//상
//		if (y > 0) {
//			//벽이 존재하는 경우
//			if (arr[y - 1][x]) {
//				if (crash == 0) {
//					qu.push({ {y - 1, x}, {1, depth} });
//				}
//			}
//			//벽이 존재하지 않는 경우
//			else {
//				qu.push({ {y - 1, x}, {crash, depth } });
//			}
//		}
//		//하
//		if (y < N-1) {
//			//벽이 존재하는 경우
//			if (arr[y + 1][x]) {
//				if (crash == 0) {
//					qu.push({ {y + 1, x}, {1, depth} });
//				}
//			}
//			//벽이 존재하지 않는 경우
//			else {
//				qu.push({ {y + 1, x}, {crash, depth } });
//			}
//		}
//		//좌
//		if (x > 0) {
//			//벽이 존재하는 경우
//			if (arr[y][x-1]) {
//				if (crash == 0) {
//					qu.push({ {y, x - 1}, {1, depth } });
//				}
//			}
//			//벽이 존재하지 않는 경우
//			else {
//				qu.push({ {y, x-1}, {crash, depth } });
//			}
//		}
//		//우
//		if (x < M - 1) {
//			//벽이 존재하는 경우
//			if (arr[y][x+1]) {
//				if (crash == 0) {
//					qu.push({ {y, x + 1}, {1, depth} });
//				}
//			}
//			//벽이 존재하지 않는 경우
//			else {
//				qu.push({ {y, x+1}, {crash, depth } });
//			}
//		}
//	}
//
//	cout << "-1\n";
//
//	return 0;
//}