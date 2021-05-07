#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

int T, S, E;
vector<int> V[20001];
int visited[20001];

int main() {
	cin >> T;
	while (T--) {
		//input
		cin >> S >> E;
		int a, b;
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}

		//calc
		memset(visited, -1, sizeof(visited));
		queue<pair<int, int> > qu;
		bool flag = true;

		for (int i = 1; i <= S; i++) {
			if (visited[i] == -1) {
				qu.push({ i,0 });
				while (!qu.empty()) {
					//������ �и�
					int here = qu.front().first, color = qu.front().second;
					qu.pop();

					//���� ��� : �̹� �湮�� ���
					if (visited[here] != -1) {
						continue;
					}

					visited[here] = color;
					if (color == 0)
						color = 1;
					else
						color = 0;

					for (int i = 0; i < V[here].size(); i++)
						qu.push({ V[here][i], color });
				}
			}
		}
		while (!qu.empty()) {
			//������ �и�
			int here = qu.front().first, color = qu.front().second;
			qu.pop();

			//���� ��� : �̹� �湮�� ���
			if (visited[here] != -1) {
				continue;
			}

			visited[here] = color;
			if (color == 0)
				color = 1;
			else
				color = 0;

			for (int i = 0; i < V[here].size(); i++)
				qu.push({ V[here][i], color });
		}
		
		for (int i = 1; i <= S; i++) {
			for (int j = 0; j < V[i].size(); j++) {
				if (visited[i] == visited[V[i][j]]) {
					flag = false;
					break;
				}
			}
		}

		//���� ������ �Ұ�
		for (int i = 1; i <= S; i++) {
			V[i].clear();
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}