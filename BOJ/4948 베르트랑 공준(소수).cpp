//#include <iostream>
//
//bool eratosthenes_sieve[300002];
//
//void count_prime(const int begin) {
//	const int end(begin * 2);
//	int i, j,count(0);
//
//	//�迭 �ʱ�ȭ
//	for (i = 2; i <= end;i++) {
//		eratosthenes_sieve[i] = true;
//	}
//
//	//�Ҽ� Ž��
//	for (i = 2;i <= end;i++) {
//		if (i*i > end)
//			break;
//		if (eratosthenes_sieve[i]) {
//			for (j = i * i;j <= end;j += i)
//				eratosthenes_sieve[j] = false;
//		}
//
//	}
//
//	//���� ���� true�� ���� ���
//	for (i = begin+1;i <= end;i++) {
//		if (eratosthenes_sieve[i])
//			count++;
//	}
//	std::cout << count << "\n";
//}
//
//int main() {
//	int n;
//	while(1) {
//		std::cin >> n;
//		if(n==0) break;
//		count_prime(n);
//	} 
//	
//	
//
//	return 0;
//}