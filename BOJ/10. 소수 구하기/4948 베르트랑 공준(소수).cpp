//#include <iostream>
//
//bool eratosthenes_sieve[300002];
//
//void count_prime(const int begin) {
//	const int end(begin * 2);
//	int i, j,count(0);
//
//	//배열 초기화
//	for (i = 2; i <= end;i++) {
//		eratosthenes_sieve[i] = true;
//	}
//
//	//소수 탐색
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
//	//범위 내의 true의 값을 출력
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