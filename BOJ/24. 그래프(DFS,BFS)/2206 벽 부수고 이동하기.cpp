#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N, M;
//arr[y][x];
int arr[1001][1001];
//qu.first.first = ���� x, qu.first.second = ���� y, qu.second = ���� �μ����°�?
queue<pair<pair<int, int>, pair<int, int> > > qu;
//visited[y][x][k] = y,x ��ġ�� �湮�Ͽ��°�, k�� ���� �μ������� ����
bool visited[1001][1001][2];

int bfs() {
	while (!qu.empty()) {
		pair<int, int> here = qu.front().first;
		int y = here.first;
		int x = here.second;
		int k = qu.front().second.first;
		int count = qu.front().second.second;
		qu.pop();

		if (visited[y][x][k])
			continue;

		visited[y][x][k] = true;

		if (y == N - 1 && x == M - 1)
			return count + 1;

		//�����¿�� �̵�
		//��
		if (y > 0) {
			if (arr[y - 1][x] == 0) {
				qu.push({ {y - 1,x}, {k, count + 1} });
			}
			else if (k == 0) {
				qu.push({ {y - 1,x}, {1, count + 1} });
			}
		}
		//��
		if (y < N - 1) {
			if (arr[y + 1][x] == 0) {
				qu.push({ {y + 1,x}, {k, count + 1} });
			}
			else if (k == 0) {
				qu.push({ {y + 1,x}, {1, count + 1} });
			}
		}
		//��
		if (x > 0) {
			if (arr[y][x - 1] == 0) {
				qu.push({ {y,x - 1}, {k, count + 1} });
			}
			else if (k == 0) {
				qu.push({ {y,x - 1}, {1, count + 1} });
			}
		}
		//��
		if (x < M - 1) {
			if (arr[y][x + 1] == 0) {
				qu.push({ {y,x + 1}, {k, count + 1} });
			}
			else if (k == 0) {
				qu.push({ {y,x + 1}, {1, count + 1} });
			}
		}
	}

	return -1;
}

int main() {
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j] - 48;
		}
	}

	qu.push({ {0,0}, {0,0} });

	cout << bfs() << endl;

	return 0;
}