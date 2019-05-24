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
		//자신 이후에 들어오는 수들을 adj에 넣어준다.
		adj[a].push_back(b);
		//먼저 풀어야 하는 문제가 있는 노드의 진입차수를 1 증가시켜준다.
		Indegree[b]++;
	}

	//진입차수가 0인 노드들을 우선순위 큐에 넣어준다.
	for (int i = 1; i <= N; i++) 
		if (!Indegree[i]) minHeap.push(i);
	
	//모든 문제를 출력 할 때까지 반복한다.
	while (!minHeap.empty()) {
		//우선순위 큐 중에서 가장 작은 수를 출력한다.
		int printHere = minHeap.top();
		minHeap.pop();
		cout << printHere << " ";
		for (auto min : adj[printHere])
			if (--Indegree[min] == 0)
				minHeap.push(min);
	}

	return 0;
}
