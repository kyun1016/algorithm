#include<iostream>
#include<cmath>

using namespace std;
//
//int N;
//int cache[105];
//
//bool is_possible(const int& N) {
//	int temp = N;
//	while (temp > 10) {
//		int a = temp % 10;
//		int b = (temp / 10) % 10;
//		if (abs(a - b) != 1)
//			return false;
//		temp /= 10;
//	}
//
//	return true;
//}
//
//int main() {
//	cin >> N;
//	int count = 0;
//	for (int i = pow(10, N-1); i < pow(10, N); i++) {
//		if (is_possible(i))
//			count++;
//		count = count % 1000000000;
//	}
//
//	cout << count << endl;
//}


int N;
int cache[101][10];

int main() {
	cin >> N;
	for (int i = 1; i < 10; i++) {
		cache[1][i] = 1;
	}
	for (int depth = 1; depth <= N; depth++) {
		for (int num = 0; num < 10; num++) {
			if (num + 1 < 10) {
				cache[depth + 1][num + 1] += cache[depth][num];
				cache[depth + 1][num + 1] %= 1000000000;
			}
				
			if (num - 1 >= 0) {
				cache[depth + 1][num - 1] += cache[depth][num];
				cache[depth + 1][num - 1] %= 1000000000;
			}
				
		}
	}
	int ret = 0;
	for (int num = 0; num < 10; num++) {
		ret += cache[N][num];
		ret %= 1000000000;
	}
	cout << ret;
}