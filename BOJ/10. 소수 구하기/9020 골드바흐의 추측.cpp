//#include<iostream>
//
//
////���� �ð��ʰ��� ����.
//
//bool is_prime[10002];
//int prime_arr[5000];
//
//
//void find_prime(const int n) {
//	int i, j;
//	for (i = 2;i <= n;i++) is_prime[i] = true;
//
//	for (i = 0;i < n;i++) {
//		if (i*i > n) break;
//		if (is_prime[i]) {
//			for (j = i + i;j < n;j += i) {
//				is_prime[j] = false;
//			}
//		}
//	}
//
//	int ptr = 0;
//	for (i = 2;i < n;i++) {
//		if (is_prime[i]) {
//			prime_arr[ptr++] = i;
//		}
//	}
//}
//
//void find_goldbach_conjecture(int n) {
//	int ptr_a(0), ptr_b(0);
//	int a(0), b(0),decreasing(99999);
//
//	for (ptr_a = 0;prime_arr[ptr_a] || prime_arr[ptr_a] == 0 < n;ptr_a++) {
//		for (ptr_b = 0; (prime_arr[ptr_b] < n || prime_arr[ptr_b] == 0); ptr_b++)
//			if (n == prime_arr[ptr_a] + prime_arr[ptr_b]) {
//				if (decreasing > prime_arr[ptr_b] - prime_arr[ptr_a]&& prime_arr[ptr_b] - prime_arr[ptr_a]>=0) {
//					decreasing = prime_arr[ptr_b] - prime_arr[ptr_a];
//					a = prime_arr[ptr_a];
//					b = prime_arr[ptr_b];
//				}
//				
//			}
//	}
//	
//
//	std::cout << a << " " << b << "\n";
//
//
//}
//
//
//
//int main() {
//	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
//	int T, n,t;
//	std::cin >> T;
//
//	//�̸� �ʿ��� �������� �Ҽ��� ã�Ƴ���.
//	find_prime(10000);
//
//	for (t = 0;t < T;t++) {
//		std::cin >> n;
//		find_goldbach_conjecture(n);
//	}
//}