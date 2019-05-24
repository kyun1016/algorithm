#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int Time[501];
vector<int> NeedHere[501];
int cache[501];
bool visited[501];

int Max(int a, int b) {
	return a > b ? a : b;
}

//int DFS(int Here) {
//	int& ret = cache[Here];
//	visited[Here] = true;
//	if (ret != 0) {
//		for (int i = 0; i < NeedHere[Here].size(); i++) {
//			int there = NeedHere[Here][i];
//			if (visited[there])
//				ret -= Time[there];
//			else
//				visited[there] = true;
//		}
//		return ret;
//		
//	}
//	
//	for (int i = 0; i < NeedHere[Here].size(); i++) {
//		int there = NeedHere[Here][i];
//		if(!visited[there])
//			ret += DFS(there);
//	}
//
//	return ret += Time[Here];
//}


//지금 해야하는 목표
//두가지 노드로 갈라지면 두개를 각각 더하는 것이 아니라
//노드 중 더 큰 값을 반환해야한다.
int BFS(int N) {
	int& ret = cache[N];
	if (ret != 0)
		return ret;
	for (int i = 0; i < NeedHere[N].size(); i++) {
		int there = NeedHere[N][i];
		ret = Max(ret, BFS(there));
	}

	return ret += Time[N];
}




int main() {
	int N,a;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Time[i];
		cin >> a;
		while (a != -1) {
			NeedHere[i].push_back(a);
			cin >> a;
		}
	}

	/*for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		cout << DFS(i) << endl;
	}*/

	for (int i = 1; i <= N; i++) {
		cout << BFS(i) << endl;
	}

	return 0;
}