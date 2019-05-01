//#include<iostream>
//
//int count[1000002];
//
//int Min(int a, int b) {
//	return a < b ? a : b;
//}
//
//void calc(const int N) {
//	for (int i = 4; i <= N; i++) {
//		count[i] = Min(count[i - 1] + 1, Min(count[i / 2] + i % 2 + 1, count[i / 3] + i % 3 + 1));
//	}
//}
//
//int main() {
//	int N;
//	std::cin >> N;
//	count[1] = 0;
//	count[2] = 1;
//	count[3] = 1;
//	calc(N);
//	std::cout << count[N];
//
//}