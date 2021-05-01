//
////시발 항복
////개같은거
////아마 사분면으로 나눠서 sort 하고
////최댓값을 구해내는거지 않을까 싶다.
//
//
//#include<iostream>
//#include<utility>
//
//
//
//
//using namespace std;
//
//std::pair <int, int> card[30000];
//
//int hypotenuse(int i, int j) {
//	int a, b;
//
//	a = card[i].first + card[j].first;
//	b = card[i].second + card[j].second;
//
//	return a * a + b * b;
//}
//
//int calc(const int N) {
//	int ret = 0, i, j, temp;
//	for (i = 0; i < N-1; i++)
//		for (j = i+1; j < N; j++) {
//			temp = hypotenuse(i, j);
//			if(ret < temp)
//				ret = temp;
//		}
//
//	return ret;
//}
//
//int main() {
//	int T, N, a, b;
//	std::cin >> T;
//	for (int i = 1; i <= T; i++) {
//		std::cin >> N;
//		for (int j = 0; j < N; j++) {
//			cin >> card[j].first >> card[j].second;
//		}
//
//		std::cout << "#" << i << " " << calc(N) << std::endl;
//	}
//
//	return 0;
//}