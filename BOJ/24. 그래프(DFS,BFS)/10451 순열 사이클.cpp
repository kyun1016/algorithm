#include<iostream>
#include<cstring>

using namespace std;

int arr[1001];
bool visited[1001];

//���� ������ ����Ž�� ����
void DFS(int i) {
	if (visited[i])
		return;
	visited[i] = true;
	DFS(arr[i]);
}

int findCycles(int N) {
	//�ʱ�ȭ�� ���ش�.
	memset(visited, false, sizeof(visited));
	int Count = 0;
	for (int i = 1; i <= N; i++) {
		//�迭�߿� ���� ������ �ȵ� ���� �ִٸ�,
		if (!visited[i]) {
			//����Ž���� �ؼ� ���� ���� ã�Ƴ���.
			DFS(i);
			//�׸��� ���� 1�� �߰�.
			Count++;
		}
	}

	//���� ���� ��ȯ
	return Count;
}

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		//������ ã���� ���ô�.
		cout << findCycles(N) << endl;

	}
}