#include<iostream>
#include<vector>

using namespace std;

//�θ� ��尡 ������ ��������.
int treeNodeMother[100001];
vector<int> arr[100001];

//pair�迭�� ��� ��ȸ�ϸ鼭 �θ� ��带 ã�´�. ���� ������ �θ� ��� �����Ǿ����� �ʴ´ٸ� ������ ��� ����Ž���� �Ѵ�.
//���� ������ ã�Ƶ� ������ �ʴ´ٸ� �ڽ��� �θ� ����� ���̰�, ��� ���ʴ�� �θ��尡 �ǵ��� �������ְ�,
//������ �θ� ��尡 ������ �� ���ʴ�� �θ��带 �������ش�.
void connectMotherNode(int node = 1) {
	//1���� Ž���� �ϹǷ�
	for (int i = 0; i < arr[node].size(); i++) {
		if (treeNodeMother[arr[node][i]] == 0) {
			treeNodeMother[arr[node][i]] = node;
			connectMotherNode(arr[node][i]);
		}
	}
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

	connectMotherNode();

	for (int i = 2; i <= N; i++) {
		cout << treeNodeMother[i] << "\n";
	}
}