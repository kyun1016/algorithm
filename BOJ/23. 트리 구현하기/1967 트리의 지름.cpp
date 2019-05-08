#include<iostream>
#include<vector>

using namespace std;

//pair<int, int>의 first는 자손 노드, second는 그의 가중치이다.
vector<pair<int, int> > myBabyNode[10001];

bool visited[10001];

int diameter;
int farthestNode;

int Max(int a, int b) {
	return a > b ? a : b;
}

void DFS(int here, int cost) {
	//기저 사례 : 이미 방문한 곳
	if (visited[here])
		return;

	visited[here] = true;

	//지름 업데이트
	if (diameter < cost) {
		diameter = cost;
		farthestNode = here;
	}

	for (int i = 0; i < myBabyNode[here].size(); i++) {
		DFS(myBabyNode[here][i].first, cost + myBabyNode[here][i].second);
	}
	

	//int length = 0;
	//visited[here] = true;
	//if (myBabyNode[here].size() == 0) {
	//	terminalNode = here;
	//	return 0;
	//}
	//	
	////모든 인접 정점을 순회하면서
	//for (int i = 0; i < myBabyNode[here].size(); i++) {
	//	//다음 깊이탐색을 할 노드를 정한다.
	//	int there = myBabyNode[here][i].first;
	//	if (!visited[there]) {
	//		length = Max(length, myBabyNode[here][i].second + findDiameter(there));
	//	}
	//		
	//}
	//return length;
}

int main() {
	int N;
	cin >> N;
	int a, b, c;

	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		myBabyNode[a].push_back({ b,c });
		myBabyNode[b].push_back({ a,c });
		
	}
	
	memset(visited, false, sizeof(visited));
	DFS(1,0);
	memset(visited, false, sizeof(visited));
	diameter = 0;
	DFS(farthestNode,0);
	cout << diameter;
	return 0;
}