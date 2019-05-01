//#include <iostream>
//
//int gcd(int a, int b) {
//	return a % b ? gcd(b, a%b) : b;
//}
//
//int calc(int a, int b) {
//	int i = 1, GCD;
//	while (a != 1) {
//		i = (b%a == 0) ? (b / a) : (b / a + 1);
//		a = a * i - b;
//		b = b * i;
//		GCD = gcd(a, b); a /= GCD; b /= GCD;
//	}
//	return b;
//}
//
//
//
//int main() {
//	int T, a, b;
//	std::cin >> T;
//	while (T--) {
//		std::cin >> a >> b;
//		std::cout << calc(a, b) << std::endl;
//	}
//}