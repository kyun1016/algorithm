//#include <iostream>
//using namespace std;
//
//int calc_max[301], score[301];
//
//int max(int a, int b) {
//	return a > b ? a : b;
//}
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> score[i];
//	}
//
//	calc_max[0] = score[0];
//	calc_max[1] = max(score[0] + score[1], score[1]);
//	calc_max[2] = max(score[0] + score[2], score[1] + score[2]);
//
//	for (int i = 3; i < N; i++) {
//		calc_max[i] = max(calc_max[i - 2] + score[i], score[i - 1] + score[i] + calc_max[i - 3]);
//	}
//
//	cout << calc_max[N - 1] << '\n';
//
//	return 0;
//}
