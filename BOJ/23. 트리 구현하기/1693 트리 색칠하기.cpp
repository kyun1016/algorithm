#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> adj[100001];
bool visited[100001];
int cache[100001][19];
const int INF = 10000007;

int Min(int a, int b) {
	return a < b ? a : b;
}

int dp(int here, int beforeNode,int color) {
	//메모이제이션을 활용하자.
	int& ret = cache[here][color];
	//기저 사례 : 이미 색칠이 된 경우 바로 리턴
	if (ret != 0) 
		return ret;
	int colorSum = 0;

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		int min = INF;
		if (there != beforeNode) {
			for (int nextColor = 1; nextColor <= 18; nextColor++)
				if (color != nextColor)
					min = Min(min, dp(there, here, nextColor));
			colorSum += min;
		}
		
	}
	return ret = colorSum + color;
}

//
//int find(int here, int before) {
//	//아름다운 총천연 십팔색을 우선 칠해주자!
//	for (int i = 0; i < 18; i++) cache[here][i] += i+1;
//	//xor연산자 : ^
//	for (int there : adj[here]) 
//		// 사실 블로그좀 참조해봤는데, ^연산자를 활용하길래 나도 써봤다. 근데 유용한지는? 그닥?
//		if (there != before) {
//			//자신과 이어진 노드를 탐색한다.
//			find(there, here);
//
//			//가장 cost가 작게든 색상 2가지를 뽑자.
//			int first = 1, second = 0;
//			for (int color = 0; color < 18; color++) {
//				if (cache[there][second] > cache[there][color]) second = color;
//				if (cache[there][first] > cache[there][second]) swap(first, second);
//			}
//			for (int color = 0; color < 18; color++)
//				//이번
//				cache[here][color] += cache[there][first != color ? first : second];
//		}
//}



//void DFS(int here, int thisColor) {
//	//기저 사례 : 이미 방문한 곳이면 바로 종료
//	if (visited[here])
//		return;
//	visited[here] = true;
//
//	//다음 컬러를 결정하자.
//	int thereColor = thisColor - 1;
//	if (thereColor == 0)
//		thereColor = 2;
//	
//	cost += thisColor;
//
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		
//		DFS(there, thereColor);
//	}
//}

int main() {
	int N,a,b;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	/*memset(visited, false, sizeof(visited));
	DFS(a, 1);
	int max = cost;
	cout << cost << endl;
	memset(visited, false, sizeof(visited));
	cost = 0;
	DFS(a, 2);
	cout << cost << endl;
	max = Max(max, cost);
*/
	int min = INF;
	for (int i = 1; i <= 18; i++) {
		cout << i << " : " << dp(1, 0,i) << endl;
		min = Min(min, dp(1,0,i));
	}

	cout << min;

	return 0;
}