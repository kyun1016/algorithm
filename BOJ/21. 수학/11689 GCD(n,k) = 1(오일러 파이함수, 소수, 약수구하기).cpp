//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//typedef unsigned long long ull;
//
////���� ������
//void coprime(ull N) {
//	//�̹����� ���Ϸ��� �����Լ��� Ȱ���Ͽ� ������ ������ ���̴�.
//	//�����Լ��� Ȱ���ϱ� ���ؼ���
//	//1. N�� ����� ������ �Ҽ��� ��� ���ؾ� �Ѵ�.
//	//�̸� ���ؼ� ����� ã�� �ڵ带 Ȱ���� ���̴�.
//	if (N == 1) {
//		cout << 1;
//		return;
//	}
//
//	ull i, j, k=0;
//	ull prime[10000];
//
//	ull ret = N;
//
//	//N^0.5�� ������ �Ѵ�.
//	for (i = 1; i*i <= N; i++) {
//		if (i*i == N)
//			prime[k++] = i;
//		else if (N%i == 0) {
//			prime[k++] = i;
//			prime[k++] = N / i;
//		}
//		
//	}
//
//	//������������ �������ش�.
//	sort(prime, prime+k);
//	//���� ����� �迭 �߿��� �Ҽ��� �ƴ� ���� �ִٸ�, �����ش�.(-1�� �ٲپ� �� ���̴�.)
//	//����� ������ 500�� �����̹Ƿ�, �ִ� 250000���� ������ �� ���̴�.
//	//prime[1]���� �����ϴ� ������ prime[0]=1���� Ư�����̽��̱� ������ ����� ���־���.
//	for (i = 1; i < k-1; i++) {
//		ull temp = prime[i];
//		for (j = i + 1; j < k; j++) {
//			if (temp == -1)
//				break;
//			if (prime[j] != -1 && prime[j] % temp == 0) {
//				prime[j] = -1;
//			}
//				
//		}
//	}
//
//	//���� ���Ϸ� �����Լ��� Ȱ������.
//	//prime�� ��� ���� Ȱ������.
//	for (i = 1; i < k; i++) {
//		if (prime[i] != -1) {
//			ret *= prime[i] - 1;
//			ret /= prime[i];
//		}
//	}
//
//	cout << ret << endl;
//
//}
//
//
//int main() {
//	ull N;
//	std::cin >> N;
//
//	coprime(N);
//	return 0;
//}
