//#include <iostream>
//
//int main() {
//	int i, n;
//	int prime[500];
//	int ptr = 0;
//	prime[ptr++] = 2;
//	for (n = 3;n <= 1000;n += 2) {
//		for (i = 1; i <ptr; i++) {
//			if (n%prime[i] == 0)
//				break;
//		}
//		if (ptr == i) {
//			prime[ptr++] = n;
//		}
//	}
//	std::cin >> n;
//	int input[101],count(0);
//	for (i = 0;i < n;i++) {
//		std::cin >> input[i];
//		for (int t = 0;t < input[i];t++) {
//			if (input[i] == prime[t]) count++;
//		}
//	}
//
//	std::cout << count;
//
//	return 0;
//}