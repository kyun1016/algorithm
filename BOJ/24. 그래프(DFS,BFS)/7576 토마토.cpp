#include<iostream>
#include<queue>

using namespace std;

int tomatoBox[1003][1003];
int M, N, MAX;
int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };
queue<pair<int, int> > findHere;


int Max(int a, int b) {
	return a > b ? a : b;
}

//void find() {
//	int t =M*N;
//	while(t--)
//		for (int y = 1; y <= N; y++)
//			for (int x = 1; x <= M; x++) {
//				if (tomatoBox[y][x] > 0) {
//					for (int i = 0; i < 4; i++) {
//						if (tomatoBox[y + dirY[i]][x + dirX[i]] != 0)
//							continue;
//						tomatoBox[y + dirY[i]][x + dirX[i]] = tomatoBox[y][x] + 1;
//					}
//				}
//
//			}
//}

////�� ���ں��� ���� ���̶�� �ٷ� return�� �ع�����. �̹� �ű⼭ �߻��Ǵ� �͵��� �̹� �� Ž���� �Ϸ��߱� �����̴�.
//void DFS(int hereY, int hereX, int day=1) {
//	//���� ��� : �丶�䰡 ���� ���̶�� �ٷ� return���� Ž���� �����Ѵ�.
//	if (tomatoBox[hereY][hereX] == -1)
//		return;
//	//���� ��� : ���� ��¥���� �� ���� ��¥�� ����Ǿ� �ִٸ� Ž���� �����Ѵ�.
//	if (tomatoBox[hereY][hereX] < day && tomatoBox[hereY][hereX] != 0)
//		return;
//
//	//���� ��ʿ� �ɸ��� ���� �丶��� ���� ��¥�� �޾��ش�.(�ʹµ����� ���� �ּ��� �ð�)
//	tomatoBox[hereY][hereX] = day;
//	//Count++;
//	//4���� Ž���� ����
//	for (int i = 0; i < 4; i++) {
//		int nextY = hereY + dirY[i], nextX = hereX + dirX[i];
//		//������ ���� �ʵ��� ������ �־��ش�.
//		if (nextY < N&&nextX < M && nextY >= 0 && nextX >= 0)
//			DFS(nextY, nextX, day + 1);
//	}	
//}

void BFS(int hereY, int hereX) {
	//4���� Ž���� ����
	for (int i = 0; i < 4; i++) {
		int nextY = hereY + dirY[i], nextX = hereX + dirX[i];
		//������ ���� �ʵ��� ������ �־��ش�.
		if (nextY < N&&nextX < M && nextY >= 0 && nextX >= 0) {
			if (tomatoBox[nextY][nextX] == 0) {
				tomatoBox[nextY][nextX] = tomatoBox[hereY][hereX] + 1;
				findHere.push({ nextY, nextX });
			}
		}
			
	}	
}

int main() {
	cin >> M >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> tomatoBox[y][x];
			if (tomatoBox[y][x] == 1)
				findHere.push({ y,x });
		}

	//�丶�䰡 ����ִ� ���ڿ��� ��� Ž���� ����! Yes!
	/*for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if(tomatoBox[y][x] == 1)
				DFS(y,x);*/

	//for (int i = 0; i < hereIsRoot.size(); i++)
	//	DFS(hereIsRoot[i].first, hereIsRoot[i].second);


	while (!findHere.empty()) {
		BFS(findHere.front().first, findHere.front().second);
		findHere.pop();
	}


	//�丶�� ���� ���
	//for (int y = 0; y < N; y++) {
	//	for (int x = 0; x < M; x++)
	//		cout << tomatoBox[y][x] << " ";
	//	cout << endl;
	//}


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			//���� �;����� ���� �丶�䰡 �ִٸ� -1�� ����Ѵ�.
			if (tomatoBox[y][x] == 0) {
				cout << -1;
				return 0;
			}
			MAX = Max(MAX, tomatoBox[y][x]);
		}
	}


	cout << MAX - 1;
	return 0;
}