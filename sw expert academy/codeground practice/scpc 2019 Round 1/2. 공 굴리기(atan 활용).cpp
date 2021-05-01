//#include <iostream>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//const double Pi = 3.14159265358979323846;
//vector<pair< int, pair<int, int> > > V;
//
//int main(int argc, char** argv)
//{
//	int T, test_case, N;
//	double R, S, E;
//	double xs, xe, h;
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		double ret = 0;
//		cin >> R >> S >> E >> N;
//		ret = E - S;
//		for (int i = 0; i < N; i++) {
//			cin >> xs >> xe >> h;
//			if (h >= R) {
//				ret += Pi * R;
//				ret += h * 2;
//				ret -= R * 4;
//			}
//			else {
//				double x = sqrt(R * R - (R - h)*(R - h));
//				ret -= x * 2;
//				double angle = atan((R-h) / x) * 2/Pi;
//				ret += Pi * (1 - angle) * R;
//			}
//		}
//		
//
//		 // Print the answer to standard output(screen).
//		cout << "Case #" << test_case + 1 << endl;
//		printf("%.12f\n", ret);
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}