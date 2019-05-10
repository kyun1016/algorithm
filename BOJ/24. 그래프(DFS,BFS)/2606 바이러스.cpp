#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[101];
int nodeNum,virus;
//bool virus[101];
bool visited[101];
queue<int> findHere;

////DFS
//void DFS(int here) {
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		if (!visited[there]) {
//			visited[there] = true;
//			virus++;
//			findHere.push(there);
//		}
//	}
//}


//BFS
void BFS(int here) {
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) {
			visited[there] = true;
			virus++;
			BFS(there);
		}
	}
}



int main() {
	int N,a,b;
	cin >> nodeNum;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	////DFS;
	//visited[1] = true;
	//findHere.push(1);
	//while (!findHere.empty()) {
	//	DFS(findHere.front());
	//	findHere.pop();
	//}
	//cout << virus;

	//BFS
	visited[1] = true;
	BFS(1);
	cout << virus;

	return 0;
}