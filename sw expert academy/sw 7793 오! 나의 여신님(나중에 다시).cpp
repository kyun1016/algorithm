#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;


//����� ������ 0, �Ǹ��� 1, �Ұ�ħ������ 2
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
			//�����̳� ���� �ִ� ������ �Ұ�ħ�����̴�.
			if (arr[y][x] == 'D') {
				virusPos[0][y][x] = 3;
				angel_x = x;
				angel_y = y;
			}
			else if(arr[y][x] == 'X')
				virusPos[0][y][x] = 2;
			//�Ǹ��� �ִ°��� 1
			else if (arr[y][x] == '*')
				virusPos[0][y][x] = 1;
			else if (arr[y][x] == 'S') {
				virusPos[0][y][x] = 0;
				me_x = x;
				me_y = y;
			}
			//�ٸ� ���� 0;
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
					//4������ Ž������.
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
		//�ֱ⸦ �����ش�.
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
	//�ʱ�ȭ�Ѵ�.
	if (!qu.empty())
		qu.pop();
	memset(visited, false, sizeof(visited));
	//�ʱⰪ�� �־��ش�.
	qu.push({ 0, {me_y, me_x} });
	visited[me_y][me_x] = true;
	pair<int, pair<int, int> > here;
	while (!qu.empty()) {
		//ť �Ǿ��� �����͸� �����´�.
		here = qu.front();
		qu.pop();
		int cycle = here.first;
		int y = here.second.first;
		int x = here.second.second;
		//cout << y << " " << x  << " " << cycle << endl;
		
		//õ�翡 �����Ͽ�����, �ɸ� �ð��� ����Ѵ�.
		if (y == angel_y && x == angel_x) {
			cout << cycle << endl;
			return;
		}
			
		cycle++;
		
		//4�������� Ž���Ѵ�.
		//�ּ� �ð��� Ž���ϹǷ�, �ѹ� �湮�� ��Ҹ� �ٽ� �湮�ϴ� ���ɼ��� 0�̴�.
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