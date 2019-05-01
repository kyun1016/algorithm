//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int INF = 1000000000;
//
//long long count_step[101][10];
//
//void calc(int N) {
//	for (int i = 0; i <= 9; i++) {
//		if(i == 9)
//			count_step[N][i] = count_step[N - 1][i - 1] % INF;
//		else if(i == 0)
//			count_step[N][i] = count_step[N - 1][i + 1] % INF;
//		else
//			count_step[N][i] = (count_step[N - 1][i - 1] + count_step[N - 1][i + 1])% INF;
//	}
//	
//}
//
//int main() {
//	int N;
//	std::cin >> N;
//	for (int i = 1; i <= 9; i++) {
//		count_step[1][i] = 1;
//	}
//	for (int i = 2; i <= N; i++) {
//		calc(i);
//	}
//	long long sum = count_step[N][0];
//	for (int i = 1; i <= 9; i++) {
//		sum += (count_step[N][i] % INF);
//	}
//	std::cout << sum % INF << std::endl;
//}