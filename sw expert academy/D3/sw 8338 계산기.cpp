//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int test_case;
//	int T, N;
//	
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		cin >> N;
//		int ret = 0;
//		int temp;
//		for (int i = 0; i < N; i++) {
//			cin >> temp;
//			ret = max(ret + temp, ret * temp);
//		}
//
//		cout << "#" << test_case << " " << ret << "\n";
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}