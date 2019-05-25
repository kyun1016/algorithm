#include<iostream>
#include<algorithm>

using namespace std;

//�۳� ����
int LastRank[501];
//�ڽ��� �տ� �ִ� ����� ��
int Count[501];
//���� ������ ���Ҷ� Ȱ��.
pair<int, int> Rank[501];

int main() {
	int T, N, M;
	int a, b;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			//������� �Է��� �޾Ƽ�
			cin >> a;
			//�̹� ������ �տ� �ִ� ����� ���� i�̴�.
			Count[a] = i;
			//�׸��� �̹� ������ ����Ѵ�.(i+1)
			LastRank[a] = i + 1;
		}

		//�����ϴ� ������
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			//�� ������ �� ���Ҵٸ�, count�� �״�� �ݿ�������.
			if (LastRank[a] > LastRank[b]) {
				Count[a]--;
				Count[b]++;
			}
			else {
				Count[a]++;
				Count[b]--;
			}
		}

		//�� �̸�?�� �������ֱ� ���ؼ� pair�� ������ ���ش�. ���� Count �ڴ� �� �̸�
		for (int i = 0; i < N; i++) {
			Rank[i] = { Count[i+1], i + 1 };
		}

		//first�� �������� �������� ����, �� ������� �迭�� ���ĵȴ�.
		sort(Rank, Rank + N);

		//�̹� �迭�߿� ������ Ȯ������ �� �ִ��� Ȯ���Ѵ�.
		bool isPossible = true;
		for (int i = 0; i < N; i++) {
			//���� �̹� ������ Count�� i�� ���� �ʴٸ�,
			if (Rank[i].first != i) {
				//�Ұ����� �迭�̰� �ݺ��� �����Ѵ�.
				isPossible = false;
				break;
			}
		}

		if (!isPossible) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		//������ �迭�̶�� ������� �̸��� ������ָ� �ϼ�!
		for (int i = 0; i < N; i++) {
			cout << Rank[i].second << " ";
		}
		cout << endl;
	}


	return 0;
}