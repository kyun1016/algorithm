#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;


//평범한 지역은 0, 악마는 1, 불가침영역은 2
int virusPos[2501][51][51];
bool visited[51][51];
string arr[51];
//first = cycle, second.first = y, second.second = x;
queue<pair<int, pair<int, int> > > qu;
int me_y, me_x, angel_y, angel_x;

void spreadVirus(const int& N, const int& M) {
	memset(virusPos, false, sizeof(virusPos));
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			//여신이나 돌이 있는 영역은 불가침공간이다.
			if (arr[y][x] == 'D') {
				virusPos[0][y][x] = 3;
				angel_x = x;
				angel_y = y;
			}
			else if(arr[y][x] == 'X')
				virusPos[0][y][x] = 2;
			//악마가 있는곳은 1
			else if (arr[y][x] == '*')
				virusPos[0][y][x] = 1;
			else if (arr[y][x] == 'S') {
				virusPos[0][y][x] = 0;
				me_x = x;
				me_y = y;
			}
			//다른 곳은 0;
			else
				virusPos[0][y][x] = 0;
		}

	int cycle = 0;
	while (1) {
		bool change = false;
		/*cout << cycle << endl;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++)
				cout << virusPos[cycle][y][x];
			cout << endl;
		}
		cout << endl;*/
		
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (virusPos[cycle][y][x] == 1) {
					virusPos[cycle + 1][y][x] = 1;
					//4방향을 탐색하자.
					if (y + 1 < N && virusPos[cycle][y + 1][x] == 0) {
						change = true;
						virusPos[cycle + 1][y + 1][x] = 1;
					}
					if (x + 1 < M && virusPos[cycle][y][x + 1] == 0) {
						change = true;
						virusPos[cycle + 1][y][x + 1] = 1;
					}
					if (y - 1 >= 0 && virusPos[cycle][y - 1][x] == 0) {
						change = true;
						virusPos[cycle + 1][y - 1][x] = 1;
					}
					if (x - 1 >= 0 && virusPos[cycle][y][x - 1] == 0) {
						change = true;
						virusPos[cycle + 1][y][x - 1] = 1;
					}
				}
				else if (virusPos[cycle][y][x] == 2)
					virusPos[cycle + 1][y][x] = 2;
				else if(virusPos[cycle][y][x] == 3)
					virusPos[cycle + 1][y][x] = 3;
		//주기를 더해준다.
		if (change == false) {
			for (int k = cycle + 1; k <= 2500; k++) 
				for (int y = 0; y < N; y++)
					for (int x = 0; x < M; x++)
						virusPos[k][y][x] = virusPos[k - 1][y][x];
			break;
		}
		
		cycle++;
		
	}
}


void BFS(const int& N, const int& M) {
	//초기화한다.
	if (!qu.empty())
		qu.pop();
	memset(visited, false, sizeof(visited));
	//초기값을 넣어준다.
	qu.push({ 0, {me_y, me_x} });
	visited[me_y][me_x] = true;
	pair<int, pair<int, int> > here;
	while (!qu.empty()) {
		//큐 맨앞의 데이터를 가져온다.
		here = qu.front();
		qu.pop();
		int cycle = here.first;
		int y = here.second.first;
		int x = here.second.second;
		//cout << y << " " << x  << " " << cycle << endl;
		
		//천사에 도달하였으면, 걸린 시간을 출력한다.
		if (y == angel_y && x == angel_x) {
			cout << cycle << endl;
			return;
		}
			
		cycle++;
		
		//4방향으로 탐색한다.
		//최소 시간을 탐색하므로, 한번 방문한 장소를 다시 방문하는 가능성은 0이다.
		if (y + 1 < N && (virusPos[cycle][y + 1][x] == 0|| virusPos[cycle][y + 1][x] == 3)&& !visited[y + 1][x]) {
			visited[y + 1][x] = true;
			qu.push({ cycle, {y + 1, x} });
		}
		if (x + 1 < M && (virusPos[cycle][y][x + 1] == 0 || virusPos[cycle][y][x + 1] == 3) && !visited[y][x + 1]) {
			visited[y][x + 1] = true;
			qu.push({ cycle, {y, x + 1} });
		}
		if (y - 1 >= 0 && (virusPos[cycle][y - 1][x] == 0 || virusPos[cycle][y - 1][x] == 3) && !visited[y - 1][x]) {
			visited[y - 1][x] = true;
			qu.push({ cycle, {y - 1, x} });
		}
		if (x - 1 >= 0 && (virusPos[cycle][y][x - 1] == 0 || virusPos[cycle][y][x - 1] == 3) && !visited[y][x - 1]) {
			visited[y][x - 1] = true;
			qu.push({ cycle, {y, x - 1} });
		}

	}
	cout << "GAME OVER" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, N, M;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		spreadVirus(N, M);
		cout << "#" << i << " ";
		BFS(N, M);
	}
	return 0;
}