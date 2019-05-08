//////#include<iostream>
//////#include<vector>
//////
//////using namespace std;
//////
////////부모 노드가 들어가도록 설계하자.
//////vector<int> arr[100001];
//////vector<int> arrLength[100001];
//////int cache[100001];
//////
//////
//////int Max(int a, int b) {
//////	return a > b ? a : b;
//////}
//////
//////
////////pair배열을 모두 순회하면서 부모 노드를 찾는다. 만일 양쪽의 부모가 모두 결정되어있지 않는다면 양쪽을 모두 깊이탐색을 한다.
////////만일 끝까지 찾아도 나오지 않는다면 자신이 부모 노드인 것이고, 모두 차례대로 부모노드가 되도록 설계해주고,
////////위에서 부모 노드가 나오면 또 그쪽대로 부모노드를 연결해준다.
//////int connectMotherNode(int node = 1) {
//////	int ret = cache[node];
//////	if(arr[node].size() == 0)
//////
//////	for (int i = 0; i < arr[i].size(); i++) {
//////		ret = Max(ret,connectMotherNode(arr[node][i]));
//////
//////	}
//////	return ret;
//////}
//////
//////
//////int main() {
//////	int N;
//////	int a, b,flag=0;
//////	cin >> N;
//////
//////	for (int i = 0; i < N; i++) {
//////		cin >> a;
//////		while (b != -1) {
//////			if (flag == 0) {
//////				cin >> b;
//////				flag++;
//////				arr[a].push_back(b);
//////			}
//////			else if (flag == 1) {
//////				cin >> b;
//////				flag--;
//////				arrLength[a].push_back(b);
//////			}
//////		}
//////	}
//////
//////	connectMotherNode();
//////
//////	for (int i = 2; i <= N; i++) {
//////		cout << treeNodeMother[i] << "\n";
//////	}
//////}
////
//////
//////#include <iostream>
//////#include <vector>
//////#include <queue>
//////using namespace std;
//////
//////#define MAX 10001
//////#define max(a,b) a>b?a:b
//////
//////struct Node {
//////	int m_node;
//////	int m_weight;
//////	Node(int node, int weight)
//////		: m_node(node), m_weight(weight) {
//////
//////	}
//////};
////
////
////////구조체 이용
//////vector<Node> d[MAX];
//////bool c[MAX];
//////int dist[MAX];
//////
//////void bfs(int start) {
//////	for (int i = 0; i < MAX; i++) {
//////		c[i] = false;
//////		dist[i] = 0;
//////	}
//////	queue<int> q;
//////	q.push(start);
//////	c[start] = true;
//////
//////	while (!q.empty()) {
//////		int x = q.front();
//////		q.pop();
//////
//////		for (int i = 0; i < d[x].size(); i++) {
//////			Node n = d[x][i];
//////			if (c[n.m_node] == false) {
//////				c[n.m_node] = true;
//////				dist[n.m_node] = dist[x] + n.m_weight;
//////				q.push(n.m_node);
//////			}
//////		}
//////	}
//////}
//////
//////
//////int main() {
//////	int n;
//////	cin >> n;
//////
//////	for (int i = 0; i < n - 1; i++) {
//////		int v, u, w;
//////		cin >> v >> u >> w;
//////
//////		d[v].push_back(Node(u, w));
//////		d[u].push_back(Node(v, w));
//////	}
//////
//////	bfs(1);
//////	int start = 1;
//////	for (int i = 2; i <= n; i++) {
//////		if (dist[start] < dist[i]) {
//////			start = i;
//////		}
//////	}
//////
//////	bfs(start);
//////	int ans = dist[1];
//////	for (int i = 2; i <= n; i++) {
//////		ans = max(ans, dist[i]);
//////	}
//////	cout << ans << endl;
//////
//////	return 0;
//////}
////
//////
//////
////////pair이용
//////
//////#include <iostream>
//////#include <vector>
//////#include <queue>
//////using namespace std;
//////
//////#define MAX 10001
//////#define max(a,b) a>b? a:b
//////
//////vector<pair<int, int>> d[MAX];
//////bool c[MAX];
//////int dist[MAX];
//////
//////void bfs(int start) {
//////	for (int i = 0; i < MAX; i++) {
//////		c[i] = false;
//////		dist[i] = 0;
//////	}
//////	queue<int> q;
//////	q.push(start);
//////	c[start] = true;
//////
//////	while (!q.empty()) {
//////		int x = q.front();
//////		q.pop();
//////
//////		for (int i = 0; i < d[x].size(); i++) {
//////			int next_node = d[x][i].first;
//////			int weight = d[x][i].second;
//////			if (c[next_node] == false) {
//////				c[next_node] = true;
//////				dist[next_node] = dist[x] + weight;
//////				q.push(next_node);
//////			}
//////		}
//////	}
//////}
//////
//////int main() {
//////	int n;
//////	cin >> n;
//////
//////	for (int i = 0; i < n - 1; i++) {
//////		int v, u, w;
//////		cin >> v >> u >> w;
//////
//////		d[v].push_back(make_pair(u, w));
//////		d[u].push_back(make_pair(v, w));
//////	}
//////
//////	bfs(1);
//////	int start = 1;
//////	for (int i = 2; i <= n; i++) {
//////		if (dist[start] < dist[i])
//////			start = i;
//////	}
//////
//////	bfs(start);
//////	int ans = 1;
//////	for (int i = 2; i <= n; i++) {
//////		ans = max(ans, dist[i]);
//////	}
//////	cout << ans << endl;
//////
//////	return 0;
//////}
////
////
////#include<iostream>
////#include<vector>
////
////
////using namespace std;
////
//////부모 노드가 들어가도록 설계하자.
////vector<int> arr[100001];
////vector<int> arrlength[100001];
////int cache[100001];
////
////int Max(int a, int b) {
////	return a > b ? a : b;
////}
////
//////트리의 root는 1로 고정하자.
//////경우는 3가지로 나누어지게된다.
//////1. 왼쪽을 탐색한다.
//////탐색을 하면서 가장 긴 길이를 반환하게 된다.
//////2. 오른쪽을 탐색한다.
//////탐색을 하면서 가장 긴 길이를 반환하게 된다.
//////3. 두개의 길이를 합쳐서 최장길이를 반환하게 된다.
//////허나 문제점이 존재하는데,
//////root로 고정한 1이 사실 최장길이에 속하지 않는 branch부분이었을 경우이다.
//////이 경우는 어떻게 해야할까? 정~답을 알려줘.
////int findTreeLength(int beforeNode = 1, int nextNode = 1) {
////	//메모이제이션을 활용하자.
////	int ret = cache[nextNode];
////
////	//기저사례: 이미 탐색을 마친곳이라면 바로 반환한다.
////	if (ret != 0)
////		return ret;
////	
////	for (int i = 0; i < arr[nextNode].size(); i++) {
////		//밑을 탐색하면서 가장 긴 길이를 반환하자.
////		ret = Max(ret, findTreeLength(nextNode, arr[nextNode][i]));
////	}
////
////	//이전 노드와 다음 노드의 길이를 더해준다.
////	ret += ? ? ? ;
////	return ret;
////}
////
////
////int main() {
////
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring> //memset
//
//using namespace std;
//
//const int MAX = 100000 + 1;
//
//int V;
//bool visited[MAX];
//vector<pair<int, int>> graph[MAX];
//
//int diameter = 0;
//int farthestNode = 0;
//
//void DFS(int node, int cost) {
//	//기저 사례:이미 방문한 곳
//	if (visited[node])
//		return;
//
//	visited[node] = true;
//
//	//지름 업데이트
//	if (diameter < cost)
//	{
//		diameter = cost;
//		farthestNode = node;
//	}
//
//	for (int i = 0; i < graph[node].size(); i++)
//		DFS(graph[node][i].first, cost + graph[node][i].second);
//}
//
//int main() {
//	int node;
//	int node2, cost;
//	cin >> V;
//
//	for (int i = 0; i < V; i++) {
//		cin >> node; {
//			while (1) {
//				cin >> node2;
//				if (node2 == -1)
//					break;
//				cin >> cost;
//				graph[node].push_back({ node2, cost });
//			}
//		}
//	}
//
//	memset(visited, false, sizeof(visited));
//	//루트에서 가장 먼 정점 찾고
//	DFS(1, 0);
//	//해당 정점에서 가장 먼 정점까지의 거리가 트리 지름의 정해
//	memset(visited, false, sizeof(visited));
//	diameter = 0;
//	DFS(farthestNode, 0);
//
//	cout << diameter << "\n";
//	return 0;
//
//
//
//}