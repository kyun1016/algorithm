#include<iostream>
#include<vector>

using namespace std;

const int MAX_N = 501;
const int INF = 1000000007;

vector<pair<int, int> > adj[MAX_N];

void bellmanFord(int src, int N) {
	vector<int> upper(N + 1, INF);
	upper[src] = 0;
	bool updated = false;
	//N���� ��ȭ�� �ٷ� ������(���⼭ updated�� Ȱ���� ���ʿ��� �ݺ��� ���δ�.)
	for (int iter = 1; iter <= N; iter++) {
		updated = false;
		for (int here = 1; here <= N; here++) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		//���� ª������ �ʾҴٸ�
		if (!updated) {
			break;
		}
	}

	if (updated)
		cout << -1 << endl;
	else {
		for (int i = 2; i <= N; i++)
			if (upper[i] == INF)
				cout << -1 << endl;
			else
				cout << upper[i] << endl;
	}
}

int main() {
	int N, M;
	int A, B, cost;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> cost;
		adj[A].push_back({ B,cost });
	}
	bellmanFord(1, N);

	return 0;
}