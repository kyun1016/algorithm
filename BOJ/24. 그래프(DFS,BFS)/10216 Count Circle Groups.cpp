#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>	//memset()을 활용하기 위해서
#include<queue>

using namespace std;

//pair<int, int>에는 x,y를 담고 뒤에는 통신 범위를 담는다.
vector<pair<pair<int, int>, int> > enemy;
bool visited[3000];
int N;
queue<int> nextFind;

bool calcDistance(pair<pair<int, int>, int>& here, pair<pair<int, int>, int>& there) {
	int x = here.first.first - there.first.first;
	int y = here.first.second - there.first.second;
	x = x*x; y = y*y;
	//cout << "sqrt = " << sqrt(x + y) << " x = :" << x << " y = " << y <<endl;
	double ret = sqrt(x + y) - here.second - there.second;
	//cout << "ret : " << ret << endl;
	if (ret <= 0)
		return true;
	
	return false;
}

//BFS
void BFS(pair<pair<int, int>, int>& here, int hereOrder) {
	//기저 사례:이미 방문하였다면 탐색을 종료한다.
	if (visited[hereOrder])
		return;
	visited[hereOrder] = true;
	for (int i = 0; i < N; i++) {
		//통신 범위 내에 존재하면, BFS로 탐색을 들어간다.
		if (!visited[i])
			if (calcDistance(here, enemy[i]))
				BFS(enemy[i], i);
	}
}

//DFS
void DFS(pair<pair<int, int>, int>& here, int hereOrder) {
	for (int i = 0; i < N; i++) {
		//통신 범위 내에 존재하면, 큐에 추가한다.
		if (!visited[i])
			if (calcDistance(here, enemy[i])) {
				nextFind.push(i);
				visited[i] = true;
			}
	}
}



int main() {
	int T, x,y,range;
	cin >> T;
	while (T--) {
		cin >> N;
		enemy.clear();
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> range;
			enemy.push_back({ {x,y},range });
		}
		//BFS를 활용해서 해결하자
		int count = 0;
		memset(visited, false, sizeof(visited));
		//for (int i = 0; i < N; i++) {
		//	if (!visited[i]) {
		//		//cout << "here : " << i << endl;
		//		BFS(enemy[i], i);
		//		count++;
		//	}
		//}
		
		//DFS를 활용해보자
		while (1) {
			
			if (nextFind.empty()) {
				for (int i = 0; i < N; i++) {
					if (!visited[i]) {
						nextFind.push(i);
						visited[i] = true;
						count++;
						break;
					}
				}
				if (nextFind.empty())
					break;
			}
			DFS(enemy[nextFind.front()], nextFind.front());
			nextFind.pop();
		}
		cout << count << endl;

	}
	

	


	return 0;
}