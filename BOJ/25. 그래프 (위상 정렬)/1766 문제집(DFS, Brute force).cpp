#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
vector<int> adj[32001];
int indegree[32001];
bool visited[32001];
int Count;

void DFS(int here) {
	cout << here << " ";
	Count++;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		indegree[there]--;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && indegree[i] == 0)
			DFS(i);
	}
}

int main() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= N; i++) {
		if(adj[i].size()>1)
			sort(adj[i].begin(), adj[i].end());
	}

	while(Count < N)
		for (int i = 1; i <= N; i++) {
			if (!visited[i]&& indegree[i] == 0)
				DFS(i);
		}

	return 0;
}
