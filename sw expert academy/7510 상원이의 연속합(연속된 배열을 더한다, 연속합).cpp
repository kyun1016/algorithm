//#include<iostream>
//#include<cmath>
//
//int calc(const int N) {
//	int count, sum(0);
//	int cnt;
//	count = 1;    //처음 자기 자신을 가지는 것은 반드시 존재.
//
//				//length를 1씩 증가시키면서 연속합의 표현이 가능한지 확인하자.
//	for (int i = 2; i <= N; i++) {
//		sum = (i*(i + 1)) / 2;
//		if (N - sum < 0)
//			break;
//		sum += ((N - sum) / i) * i;;
//		if (sum == N)
//			count++;
//	}
//
//	return count;
//}
//
//int main() {
//	int T, N;
//	std::cin >> T;
//	for (int i = 1; i <= T; i++) {
//		std::cin >> N;
//		std::cout << "#" << i << " " << calc(N) << std::endl;
//	}
//	return 0;
//}
