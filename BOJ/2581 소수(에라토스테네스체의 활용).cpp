//#include <iostream>
//
//bool eratosthenes_sieve[1000002];
//
//void count_prime(const int begin, const int end) {
//	int i, j;
//
//	//�迭 �ʱ�ȭ
//	for (i = 2; i <= end;i++) {
//		eratosthenes_sieve[i] = true;
//	}
//
//	//�Ҽ� Ž��
//	for (i = 2;i <= end;i++) {
//		if (i*i >= end)
//			break;
//		if (eratosthenes_sieve[i]) {
//			for (j = i * i;j <= end;j += i)
//				eratosthenes_sieve[j] = false;
//		}
//		
//	}
//
//	//���� ���� true�� ���� ���
//	for (i = begin;i <= end;i++) {
//		if(eratosthenes_sieve[i])
//			std::cout << i << "\n";
//	}
//}
//
//int main() {
//	int test,n;
//	std::cin >> m >> n;
//	count_prime(m, n);
//
//	return 0;
//}