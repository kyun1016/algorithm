//////#include<iostream>
//////#include<vector>
//////
//////using namespace std;
//////
////////�θ� ��尡 ������ ��������.
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
////////pair�迭�� ��� ��ȸ�ϸ鼭 �θ� ��带 ã�´�. ���� ������ �θ� ��� �����Ǿ����� �ʴ´ٸ� ������ ��� ����Ž���� �Ѵ�.
////////���� ������ ã�Ƶ� ������ �ʴ´ٸ� �ڽ��� �θ� ����� ���̰�, ��� ���ʴ�� �θ��尡 �ǵ��� �������ְ�,
////////������ �θ� ��尡 ������ �� ���ʴ�� �θ��带 �������ش�.
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
////////����ü �̿�
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
////////pair�̿�
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
//////�θ� ��尡 ������ ��������.
////vector<int> arr[100001];
////vector<int> arrlength[100001];
////int cache[100001];
////
////int Max(int a, int b) {
////	return a > b ? a : b;
////}
////
//////Ʈ���� root�� 1�� ��������.
//////���� 3������ ���������Եȴ�.
//////1. ������ Ž���Ѵ�.
//////Ž���� �ϸ鼭 ���� �� ���̸� ��ȯ�ϰ� �ȴ�.
//////2. �������� Ž���Ѵ�.
//////Ž���� �ϸ鼭 ���� �� ���̸� ��ȯ�ϰ� �ȴ�.
//////3. �ΰ��� ���̸� ���ļ� ������̸� ��ȯ�ϰ� �ȴ�.
//////�㳪 �������� �����ϴµ�,
//////root�� ������ 1�� ��� ������̿� ������ �ʴ� branch�κ��̾��� ����̴�.
//////�� ���� ��� �ؾ��ұ�? ��~���� �˷���.
////int findTreeLength(int beforeNode = 1, int nextNode = 1) {
////	//�޸������̼��� Ȱ������.
////	int ret = cache[nextNode];
////
////	//�������: �̹� Ž���� ��ģ���̶�� �ٷ� ��ȯ�Ѵ�.
////	if (ret != 0)
////		return ret;
////	
////	for (int i = 0; i < arr[nextNode].size(); i++) {
////		//���� Ž���ϸ鼭 ���� �� ���̸� ��ȯ����.
////		ret = Max(ret, findTreeLength(nextNode, arr[nextNode][i]));
////	}
////
////	//���� ���� ���� ����� ���̸� �����ش�.
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
//	//���� ���:�̹� �湮�� ��
//	if (visited[node])
//		return;
//
//	visited[node] = true;
//
//	//���� ������Ʈ
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
//	//��Ʈ���� ���� �� ���� ã��
//	DFS(1, 0);
//	//�ش� �������� ���� �� ���������� �Ÿ��� Ʈ�� ������ ����
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