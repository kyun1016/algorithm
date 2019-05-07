#include<iostream>
#include<vector>

using namespace std;

//부모 노드가 들어가도록 설계하자.
int treeNodeMother[100001];
vector<int> arr[100001];

//pair배열을 모두 순회하면서 부모 노드를 찾는다. 만일 양쪽의 부모가 모두 결정되어있지 않는다면 양쪽을 모두 깊이탐색을 한다.
//만일 끝까지 찾아도 나오지 않는다면 자신이 부모 노드인 것이고, 모두 차례대로 부모노드가 되도록 설계해주고,
//위에서 부모 노드가 나오면 또 그쪽대로 부모노드를 연결해준다.
void connectMotherNode(int node) {
	//int flag = 0, k;
	//만일 이미 자기가 부모 노드가 있다면, 연결된 노드들의 부모 노드를 자신으로 해준다.
	//if (treeNodeMother[node] != 0) {
		for (int i = 0; i < arr[node].size(); i++) {
			if (treeNodeMother[arr[node][i]] == 0) {
				treeNodeMother[arr[node][i]] = node;
				connectMotherNode(arr[node][i]);
			}
		}
	/*true;*/
	//}
	//else {
	//	//찾은 부모노드가 없다면, 연결된 모든 노드를 방문하면서 위와 아래로 연결된 뿌리를 모두 탐색한다.
	//	for (int i = 0; i < arr[node].size(); i++) {
	//		//만일 탐색한 결과가 true라면, 자신의 부모 노드를 arr[node][i]로 맞춰주고, 탐색을 종료한다.
	//		if (connectMotherNode(arr[node][i])) {
	//			treeNodeMother[node] = arr[node][i];
	//			flag = 1;
	//			k = i;
	//			break;
	//		}
	//	}
	//}	
	//
	//if (flag) {
	//	for (int i = 0; i < arr[node].size(); i++) {
	//		if (i != k)
	//			treeNodeMother[arr[node][i]] = node;
	//	}
	//	return true;
	//}

	//return false;
}


int main() {
	int N;
	int a, b;
	cin >> N;
	treeNodeMother[1] = 1;

	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		arr[a].push_back(b); arr[b].push_back(a);
		/*if (treeNodeMother[a] != 0)
			treeNodeMother[b] = a;
		else if (treeNodeMother[b] != 0)
			treeNodeMother[a] = b;*/
	}

	connectMotherNode(1);

	for (int i = 2; i <= N; i++) {
		cout << treeNodeMother[i] << "\n";
	}
}