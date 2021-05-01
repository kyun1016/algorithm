//#include<iostream>
//
//typedef unsigned long long ull;
//
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int test_case;
//	int T, N, K;
//	
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		cin >> N >> K;
//
//		cout << "#" << test_case << " ";
//		int ret = 0;
//		if (N % 2 == 0) {
//			ret = N * (N*K + 1) / 2;
//			for (int i = 0; i < K; i++) {
//				cout << ret << " ";
//			}
//		}
//		else {
//			ret = (N - 1)*((N - 1)*K + 1) / 2;
//			ret += (N - 1)*K + 1;
//			for (int i = 0; i < K; i++) {
//				cout << ret++ << " ";
//			}
//		}
//		cout << endl;
//		
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}