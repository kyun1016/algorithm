//#include<iostream>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//int N;
//ull B;
//int matrix[6][6];
//int temp[6][6];
//int cache[50][6][6];
//bool visited[50];
//int ret[6][6];
//
//void calc() {
//	int power = 0;
//	while (B > 1) {
//		//B�� 2������ ��ȯ�Ͽ� ��ȯ�Ǵ� 2���� �κ��� visited�迭�� �������־���.
//		if (B % 2)
//			visited[power] = true;
//
//		//temp����� �ʱ�ȭ���ش�.
//		for (int y = 0; y < N; y++) {
//			for (int x = 0; x < N; x++) {
//				temp[y][x] = 0;
//			}
//		}
//
//		//����� 2^power�� ������ ���� cache�� �̸� ���� ���־���.(B�� ũ�Ⱑ 100,000,000,000 �����̹Ƿ� power�� 40�� ���� �ʴ´�.)
//		//����� ������ ���� temp�� ����ش�.
//		for (int bra = 0; bra < N; bra++) {
//			for (int ket = 0; ket < N; ket++) {
//				for (int i = 0; i < N; i++) {
//					temp[bra][ket] += cache[power][bra][i] * cache[power][i][ket];
//					temp[bra][ket] %= 1000;
//				}
//			}
//		}
//
//		//������ ���������ְ�, cache�� temp�� ���� �Ű� ����־���.
//		power++;
//		for (int y = 0; y < N; y++) {
//			for (int x = 0; x < N; x++) {
//				cache[power][y][x] = temp[y][x];
//			}
//		}
//
//		B /= 2;
//	}
//	visited[power] = true;
//
//	//ret����� ������ķ� ������ش�.
//	for (int i = 0; i < N; i++) {
//		ret[i][i] = 1;
//	}
//
//	for (int i = 0; i <= power; i++) {
//		if (visited[i]) {
//			//temp����� �ʱ�ȭ���ش�.
//			for (int y = 0; y < N; y++) {
//				for (int x = 0; x < N; x++) {
//					temp[y][x] = 0;
//				}
//			}
//
//			//ret�� cache�� �����ش�.
//			for (int bra = 0; bra < N; bra++) {
//				for (int ket = 0; ket < N; ket++) {
//					for (int j = 0; j < N; j++) {
//						temp[bra][ket] += ret[bra][j] * cache[i][j][ket];
//						temp[bra][ket] %= 1000;
//					}
//				}
//			}
//			for (int y = 0; y < N; y++) {
//				for (int x = 0; x < N; x++) {
//					ret[y][x] = temp[y][x];
//				}
//			}
//		}
//	}
//
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cout << ret[y][x] << " ";
//		}
//		cout << "\n";
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> B;
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cin >> matrix[y][x];
//			cache[0][y][x] = matrix[y][x];
//		}
//	}
//
//	calc();
//
//	return 0;
//}