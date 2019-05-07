#include<iostream>
#include<vector>

using namespace std;

//�θ� ��尡 ������ ��������.
int treeNodeMother[100001];
vector<int> arr[100001];

//pair�迭�� ��� ��ȸ�ϸ鼭 �θ� ��带 ã�´�. ���� ������ �θ� ��� �����Ǿ����� �ʴ´ٸ� ������ ��� ����Ž���� �Ѵ�.
//���� ������ ã�Ƶ� ������ �ʴ´ٸ� �ڽ��� �θ� ����� ���̰�, ��� ���ʴ�� �θ��尡 �ǵ��� �������ְ�,
//������ �θ� ��尡 ������ �� ���ʴ�� �θ��带 �������ش�.
void connectMotherNode(int node) {
	//int flag = 0, k;
	//���� �̹� �ڱⰡ �θ� ��尡 �ִٸ�, ����� ������ �θ� ��带 �ڽ����� ���ش�.
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
	//	//ã�� �θ��尡 ���ٸ�, ����� ��� ��带 �湮�ϸ鼭 ���� �Ʒ��� ����� �Ѹ��� ��� Ž���Ѵ�.
	//	for (int i = 0; i < arr[node].size(); i++) {
	//		//���� Ž���� ����� true���, �ڽ��� �θ� ��带 arr[node][i]�� �����ְ�, Ž���� �����Ѵ�.
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