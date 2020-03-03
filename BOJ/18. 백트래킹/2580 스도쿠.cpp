#include<iostream>
#include<vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> point;
bool print_once;

//�⺻ ������ ��Ģ�� �����ϴ��� Ȯ���Ѵ�.
bool check(int y, int x, int num) {
	//x,y�࿡ ������ ���� �����ϴ��� Ȯ��
	for (int i = 0;i < 9;i++) {
		if (board[y][i] == num)
			return false;
		else if (board[i][x] == num)
			return false;
	}
	//3*3ĭ�� ������ ���� �����ϴ��� Ȯ��
	for (int i = (y / 3) * 3;i < (y / 3) * 3 + 3;i++) {
		for (int j = (x / 3) * 3;j < (x / 3) * 3 + 3;j++) {
			if (board[i][j] == num)
				return false;
		}
	}
	//������ ���� ������ true�� ��ȯ
	return true;
}

//������ ���� �߰ߵ��� ���� ���� ������ŭ ��͹��� Ȱ���� �ذ��ϵ��� �Ͽ���.
void solve_sudoku(int N) {
	//���� N�� ������ �Ͽ��ٸ�, ��� ������ ������Ű�� �ش��̴�.
	//��, ����� �ϰ� �Լ��� �����Ѵ�.
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
		//�̹� ���� y,x��ǥ�� vector���� �����´�.
		int y = point[N].first;
		int x = point[N].second;
		//1~9���� ��� ���� �־��.
		for (int num = 1;num <= 9;num++) {
			//������ �����ϴ��� Ȯ��
			if (check(y, x, num)) {
				//������ �����ϸ� ���� �ְ�
				board[y][x] = num;
				//����Լ��� ȣ���Ѵ�.
				solve_sudoku(N + 1);
				//���� �Լ��� ����� ���Ŀ��� 0���� �ʱ�ȭ�� ���ش�.
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