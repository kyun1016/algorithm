#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>	//memset()�� Ȱ���ϱ� ���ؼ�
#include<queue>

using namespace std;

//pair<int, int>���� x,y�� ��� �ڿ��� ��� ������ ��´�.
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
	//���� ���:�̹� �湮�Ͽ��ٸ� Ž���� �����Ѵ�.
	if (visited[hereOrder])
		return;
	visited[hereOrder] = true;
	for (int i = 0; i < N; i++) {
		//��� ���� ���� �����ϸ�, BFS�� Ž���� ����.
		if (!visited[i])
			if (calcDistance(here, enemy[i]))
				BFS(enemy[i], i);
	}
}

//DFS
void DFS(pair<pair<int, int>, int>& here, int hereOrder) {
	for (int i = 0; i < N; i++) {
		//��� ���� ���� �����ϸ�, ť�� �߰��Ѵ�.
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
		//BFS�� Ȱ���ؼ� �ذ�����
		int count = 0;
		memset(visited, false, sizeof(visited));
		//for (int i = 0; i < N; i++) {
		//	if (!visited[i]) {
		//		//cout << "here : " << i << endl;
		//		BFS(enemy[i], i);
		//		count++;
		//	}
		//}
		
		//DFS�� Ȱ���غ���
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