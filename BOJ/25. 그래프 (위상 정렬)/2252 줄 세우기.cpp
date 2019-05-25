#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

//vector�� �迭�� �����ϰ�, �� �迭���� �ڽ� �տ� ���� �� ���� �����?
queue<int> myFront[32001];
queue<int> myBack[32001];
//�׸��� bool �迭�� ���� �� ���� ���Ǿ����� Ȯ���� ������.
bool visited[32001];
//�̹��� ��� �� ��ȣ�� queue�� ��������.
queue<int> PrintME;


//BFS�� Ȱ���ؼ� ������ ����.
void BFS(int N) {
	//�켱 �� �ڿ� �ִ� ������ ó��������.
	while(!myBack[N].empty()) {
		int next = myBack[N].front();
		myBack[N].pop();
		bool nextHere=true;
		//���� ������ �ִ� ���� ��µǾ����� ���� ��쿡
		if(!visited[next])
			//���� ���� ���� ������� ������
			while(!myFront[next].empty()) {
				//�ڽ��� ���� ���� �̹� ��µǾ��ٸ� queue�� �ϳ� ��Ʈ����.
				if (visited[myFront[next].front()])
					myFront[next].pop();
				//���� �ڽ��� �տ� ���� ������ �ݺ� Ż��
				else {
					nextHere = false;
					break;
				}
			}
		//���� ���� ��� �� �� �ִٸ�,
		if (nextHere&& !visited[next]) {
			visited[next] = true;
			PrintME.push(next);
		}
	}
	cout << N << " ";
}



int main() {
	int N, M;
	int a, b;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		myFront[b].push(a);
		myBack[a].push(b);
	}

	//int count = 0;
	//
	//while (count < N) {
	//	for (int i = 1; i <= N; i++) {
	//		if (visited[i])
	//			continue;
	//		bool printIt = true;
	//		//�ڽ��� �տ� �ʿ��� ������ ���� ������ �ʾҴٸ� �������� �Ѿ��.
	//		for (int j = 0; j < myFront[i].size(); j++) {
	//			//���� �湮���� �ʾҴٸ�,
	//			if (!visited[myFront[i][j]]) {
	//				printIt = false;
	//				break;
	//			}
	//		}

	//		if (printIt) {
	//			cout << i << " ";
	//			visited[i] = true;
	//			count++;
	//		}
	//	}
	//}
	
	//�켱 BFS�� �� ������ queue�� �������.
	for (int i = 1; i <= N; i++) {
		if (myFront[i].empty()) {
			PrintME.push(i);
			visited[i] = true;
		}
	}

	//queue�� ������ �� ������ ���� Ž���� �ݺ��Ѵ�.
	while (!PrintME.empty()) {
		BFS(PrintME.front());
		PrintME.pop();
	}
	

	return 0;
}