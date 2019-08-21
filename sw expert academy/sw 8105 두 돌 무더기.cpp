//#include<iostream>
//
//typedef unsigned long long ull;
//
//using namespace std;
//
//int Count;
//
//void counting(int x, int y) {	
//	if (x > y) {
//			Count += x / y;
//			x %= y;
//	}
//	else {
//			Count += y/x;
//			y %= x;
//	}
//	
//	if (x == 0 || y == 0) {
//		return;
//	}
//	counting(x, y);
//}
//
//void bestChoice(int x, int y, int order=0) {
//
//}
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int test_case;
//	int T;
//	int x, y;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		cin >> x >> y;
//		Count = 0;
//		counting(x, y);
//		cout << "#" << test_case << " ";
//		if (Count % 2 == 0) {
//			cout << "A" << endl;
//		}
//		else {
//			cout << "B" << endl;
//		}
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}