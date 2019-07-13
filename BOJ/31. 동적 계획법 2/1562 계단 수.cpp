////#include<iostream>
////#include<string>
////
////using namespace std;
////
////typedef unsigned long long ull;
////
////int N;
////const ull INF = 1000000000;
////
////ull sum;
////
//////앞은 N,뒤는 앞 뒤 맨 마지막 수를 나타낸다.
////ull cache[101][101];
////ull NUM[101];
////
////ull makeStair(int N) {
////	if (N < 9)
////		return 0;
////	ull& ret = NUM[N];
////	if (ret != 0)
////		return ret;
////	if (NUM[N - 1] == 0)
////		makeStair(N - 1);
////	for (int i = 10; i < 101; i++) {
////		if (cache[N - 1][i] == 0)
////			continue;
////		int begin = i / 10;
////		int end = i % 10;
////		if (begin == 9) {
////			cache[N][i - 10] += cache[N - 1][i];
////			ret += cache[N - 1][i] % INF;
////		}
////		else if (begin == 1) {
////			cache[N][i + 10] += cache[N - 1][i];
////			ret += cache[N - 1][i];
////		}
////		else {
////			cache[N][i + 10] += cache[N - 1][i];
////			cache[N][i - 10] += cache[N - 1][i];
////			ret += cache[N - 1][i];
////			ret += cache[N - 1][i];
////		}
////
////		
////
////		if (end == 9) {
////			cache[N][i - 1] += cache[N - 1][i];
////			ret += cache[N - 1][i];
////		}
////		else if (end == 0) {
////			cache[N][i + 1] += cache[N - 1][i];
////			ret += cache[N - 1][i];
////		}
////		else {
////			cache[N][i + 1] += cache[N - 1][i];
////			cache[N][i - 1] += cache[N - 1][i];
////			ret += cache[N - 1][i];
////			ret += cache[N - 1][i];
////		}
////
////		ret %= INF;
////		cache[N][i - 10] %= INF;
////		cache[N][i + 10] %= INF;
////		cache[N][i + 1] %= INF;
////		cache[N][i - 1] %= INF;
////	}
////
////	return ret;
////}
////
////int main() {
////	ios_base::sync_with_stdio(0);
////	cin.tie(0);
////
////
////	cin >> N;
////
////	cache[10][90] = 1;
////	NUM[10] = 1;
////
////
////
////	cout << makeStair(N) << endl;
////	//for (int i = 0; i <= 40; i++) {
////	//	sum += NUM[i];
////	//}
////	//cout << sum << endl;
////
////	return 0;
////}
//
//#include<iostream>
//
//using namespace std;
//
//const int INF = 1000000000;
//int N;
//int cache[101][10][1 << 10];
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//
//	for (int i = 1; i < 10; i++) {
//		cache[1][i][1 << i] = 1;
//	}
//
//	//for (int order = 2; order <= N; order++) {
//	//	for (int num = 0; num < 10; num++) {
//	//		for (int visited = 0; visited < (1 << 10); visited++) {
//	//			if (num == 0) {
//	//				cache[order][num][visited | (1 << num)] = (cache[order][num][visited | (1 << num)] + cache[order - 1][num + 1][visited]) % INF;
//	//			}
//	//			else if (num == 9) {
//	//				cache[order][num][visited | (1 << num)] = (cache[order][num][visited | (1 << num)] + cache[order - 1][num - 1][visited]) % INF;
//	//			}
//	//			else {
//	//				cache[order][num][visited | (1 << num)] = (cache[order][num][visited | (1 << num)] + cache[order - 1][num - 1][visited]) % INF;
//	//				cache[order][num][visited | (1 << num)] = (cache[order][num][visited | (1 << num)] + cache[order - 1][num + 1][visited]) % INF;
//	//			}
//	//			
//	//		}
//	//	}
//	//}
//
//	for (int order = 1; order < N; order++) {
//		for (int num = 0; num < 10; num++) {
//			for (int visited = 0; visited < (1 << 10); visited++) {
//				if (cache[order][num][visited] == 0)
//					continue;
//				if (num == 0) {
//					cache[order + 1][1][visited | (1 << 1)] = (cache[order + 1][1][visited | (1 << 1)] + cache[order][num][visited]) % INF;
//				}
//				else if (num == 9) {
//					cache[order + 1][8][visited | (1 << 8)] = (cache[order + 1][8][visited | (1 << 8)] + cache[order][num][visited]) % INF;
//				}
//				else {
//					cache[order + 1][num + 1][visited | (1 << (num + 1))] = (cache[order + 1][num + 1][visited | (1 << (num + 1))] + cache[order][num][visited]) % INF;
//					cache[order + 1][num - 1][visited | (1 << (num - 1))] = (cache[order + 1][num - 1][visited | (1 << (num - 1))] + cache[order][num][visited]) % INF;
//				}
//
//			}
//		}
//	}
//
//	int ret = 0;
//
//	for (int i = 0; i < 10; i++) {
//		ret = (ret + cache[N][i][(1 << 10) - 1]) % INF;
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}