//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//
////���߱Ⱑ ������ �� �ִ� ����, ȭ���� ������ �����ϴ� �迭
//int can_trans[50];
//int cargo_weight[100000];
////ȭ������ �Ǹ��� ���� ������ �����ϴ� �迭, ���� ��ȭ�ϱ⿡ cache�� �̸��� �ٿ���.
//int cache[50];
//
//
////������ ����. O(M)�̴�.
//int transfer(const int N, const int M) {
//	int i, j(0);
//	int MAX(0), temp, count,flag(0);
//
//	//�������
//	if (cargo_weight[M-1] > can_trans[N-1])
//		return -1;
//
//	//cache�� �ʱ�ȭ����.
//	memset(cache, 0, sizeof(cache));
//	for (i = 0; i < M; i++) {
//		//������ ���߱⿡ �ִ��� ���� �����ش�.
//		if (can_trans[j] >= cargo_weight[i])
//			cache[j]++;
//		//���߱Ⱑ �δ��� �� ���ԵǸ�, �� ���� ���߱⸦ ã�´�.
//		else {
//			while (can_trans[j] < cargo_weight[i]) {
//				j++;
//			}
//			//ã�� ���߱⿡ ���� �ƴ´�.
//			cache[j]++;
//		}
//	}
//	
//
//	//������ ȭ������ ���� ȭ���� ���� ����ȭ ��Ű�� ���ؼ�, ������ ���� ���� �� ������� ���� ȭ������ �Űܽƴ´�.
//	for (int i = N - 1; i >0; i--) {
//		//������ ���߱⿡ ���� �� ������ ������ �ݺ��Ѵ�.
//		while (cache[i - 1] > cache[i]) {
//			//���� �ű�� �۾��� �ߴٸ�, flag�� �����.
//			flag = 1;
//			//���� ���������� �� ū ���߱�� �ű��.
//			for (j = i; j < N; j++) {
//				if (cache[j - 1] > cache[j]) {
//					temp = cache[j - 1] - cache[j];
//					if (temp % 2) {
//						cache[j - 1] -= temp / 2 + 1;
//						cache[j] += temp / 2 + 1;
//					}
//					else {
//						cache[j - 1] -= temp / 2;
//						cache[j] += temp / 2;
//					}
//				}
//			}
//		}
//		//�̹��� ���� �Ű���ٸ�, �ٽ� ó������ ���ư��� Ȯ���� �ٽ�����.
//		if (flag) {
//			i = N - 1;
//			flag = 0;
//		}
//		//flag�� 0�̶��, �̹� �ݺ��� �������ȴ�.
//	}
//
//	//���� ���� ���� �Ǹ� ���߱⸦ ã�´�.
//	for (i = 0; i < N; i++) {
//		MAX = max(MAX, cache[i]);
//	}	
//
//	//������ ��ȯ.
//	return MAX;
//}
//
//int main() {
//	int T, N, M;
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//		cin >> N;
//		for (int j = 0; j < N; j++) {
//			cin >> can_trans[j];
//		}
//
//		cin >> M;
//		for (int j = 0; j < M; j++) {
//			cin >> cargo_weight[j];
//		}
//		sort(can_trans, can_trans + N);
//		sort(cargo_weight, cargo_weight + M);
//
//		cout << "#" << i << " " << transfer(N, M) << endl;
//	}
//	return 0;
//}