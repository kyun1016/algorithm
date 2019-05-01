//#include<iostream>
//
//long long a[91];
//
//
//long long fibonacci(int n) {
//	a[0] = 0;
//	a[1] = 1;
//	for (int i = 0; i < n; i++) {
//		a[i + 2] = a[i + 1] + a[i];
//	}
//	return a[n];
//}
//
//int main() {
//	int n;
//	std::cin >> n;
//	std::cout << fibonacci(n) << "\n";
//
//}