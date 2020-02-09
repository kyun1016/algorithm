#include<iostream>
#include<vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> point;
bool print_once;

//기본 스도쿠 규칙을 만족하는지 확인한다.
bool check(int y, int x, int num) {
	//x,y축에 동일한 수가 존재하는지 확인
	for (int i = 0;i < 9;i++) {
		if (board[y][i] == num)
			return false;
		else if (board[i][x] == num)
			return false;
	}
	//3*3칸에 동일한 수가 존재하는지 확인
	for (int i = (y / 3) * 3;i < (y / 3) * 3 + 3;i++) {
		for (int j = (x / 3) * 3;j < (x / 3) * 3 + 3;j++) {
			if (board[i][j] == num)
				return false;
		}
	}
	//동일한 수가 없으면 true를 반환
	return true;
}

//스도쿠에 아직 발견되지 않은 수의 개수만큼 재귀법을 활용해 해결하도록 하였다.
void solve_sudoku(int N) {
	//만일 N에 도달할 하였다면, 모든 조건을 만족시키는 해답이다.
	//즉, 출력을 하고 함수를 종료한다.
	if (N == point.size()) {
		if (!print_once) {
			for (int i = 0;i < 9;i++) {
				for (int j = 0; j< 9;j++)
					cout << board[i][j] << " ";
				cout << endl;
			}
			print_once = true;
		}
	}
	else {
		//이번 수의 y,x좌표를 vector에서 가져온다.
		int y = point[N].first;
		int x = point[N].second;
		//1~9까지 모든 수를 넣어본다.
		for (int num = 1;num <= 9;num++) {
			//조건을 만족하는지 확인
			if (check(y, x, num)) {
				//조건을 만족하면 수를 넣고
				board[y][x] = num;
				//재귀함수를 호출한다.
				solve_sudoku(N + 1);
				//이후 함수가 종료된 이후에는 0으로 초기화를 해준다.
				board[y][x] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0;i < 9;i++) {
		for (int j = 0; j< 9;j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				point.push_back({ i,j });
		}
	}

	solve_sudoku(0);
}