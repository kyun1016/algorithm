#include<iostream>
#include<queue>

using namespace std;

const int MAX = 32001;
int N, M;
int Indegree[MAX];
vector<int> adj[MAX];
priority_queue<int, vector<int>, greater<int> > minHeap;


int main() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		//�ڽ� ���Ŀ� ������ ������ adj�� �־��ش�.
		adj[a].push_back(b);
		//���� Ǯ��� �ϴ� ������ �ִ� ����� ���������� 1 ���������ش�.
		Indegree[b]++;
	}

	//���������� 0�� ������ �켱���� ť�� �־��ش�.
	for (int i = 1; i <= N; i++) 
		if (!Indegree[i]) minHeap.push(i);
	
	//��� ������ ��� �� ������ �ݺ��Ѵ�.
	while (!minHeap.empty()) {
		//�켱���� ť �߿��� ���� ���� ���� ����Ѵ�.
		int printHere = minHeap.top();
		minHeap.pop();
		cout << printHere << " ";
		for (auto min : adj[printHere])
			if (--Indegree[min] == 0)
				minHeap.push(min);
	}

	return 0;
}
