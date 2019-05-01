//////#include <algorithm>	//sort를 활용하자.
//////#include <iostream>
//////
//////
//////int node[1001][1001] = { 0 };
//////int print[1001] = { 0 };
//////
//////void dfs(int size,int start) {
//////	for (int i = start+1; i <= size; i++) {
//////		if (node[start][i] >= 1) {
//////			if (print[start] == 0) {
//////				std::cout << start << " ";
//////				print[start] ++;
//////			}
//////			dfs(size, i);
//////		}
//////	}
//////}
//////
//////void bfs(int size, int start) {
//////	for (int i = 1; i <= size; i++) {
//////		std::cout << i << " ";
//////	}
//////}
//////
//////
//////
//////
//////int main() {
//////	int size, node_count, start, a, b;
//////	std::cin >> size >> node_count >> start;
//////	
//////	for (int i = 0; i < node_count; i++) {
//////		std::cin >> a >> b;
//////		if (a > b) {
//////			node[b][a]++;
//////		}
//////		else {
//////			node[a][b]++; 
//////		}
//////	}
//////	dfs(size,start);
//////	std::cout <<"\n" << start << " ";
//////	bfs(size,start);
//////
//////	return 0;
//////}
////
////
////
//
///////////////////////////////
////아래의 문장은 블로그에서 가져온 것이다.
//
//
//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//const int MAX = 1000 + 1;
//
//int adjacent[MAX][MAX];
//bool visited[MAX];
//
//queue<int> q;
//
//void DFS(int idx, int node)
//{
//	visited[idx] = 1;
//	cout << idx << " ";
//	for (int i = 1; i <= node; i++)
//		if (adjacent[idx][i] && !visited[i])
//		{
//			//인접한 노드에 대해서 또 다시 DFS
//			DFS(i,node);
//		}
//}
//
//
//
//void BFS(int idx,int node)
//{
//	q.push(idx);
//	visited[idx] = 1;
//
//	while (!q.empty())
//	{
//		idx = q.front();
//		q.pop();
//		cout << idx << " ";
//		//BFS는 해당 노드에 인접한 노드들을 모두 추가한 뒤 BFS 진행
//		for (int i = 1; i <= node; i++)
//			if (adjacent[idx][i] && !visited[i])
//			{
//				visited[i] = 1;
//				q.push(i);
//			}
//	}
//}
//
//
//
//int main(void)
//
//{
//	int node, line, start;
//	cin >> node >> line >> start;
//	for (int i = 0; i < line; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		adjacent[from][to] = 1;
//		adjacent[to][from] = 1;
//	}
//	DFS(start, node);
//	cout << endl;
//	memset(visited, false, sizeof(visited));
//	BFS(start,node);
//	cout << endl;
//	return 0;
//}