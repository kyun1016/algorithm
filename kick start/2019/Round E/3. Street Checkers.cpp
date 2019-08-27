//#include<iostream>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
//int L, R;
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int T;
//	cin >> T;
//	
//	for (int i = 0; i < T; i++) {
//		cin >> L >> R;
//		
//		int ret = 0;
//		
//		for (int i = L; i <= R; i++) {
//			int N = i;
//			int odd = 1;
//			int even = 0;
//			while (N % 2 == 0) {
//				even++;
//				N /= 2;
//			}
//
//			if (even > 1) {
//				if (N != 1)
//					continue;
//				else {
//					if (even <= 3)
//						ret++;
//					else
//						continue;
//				}
//			}
//			else if (even == 1) {
//				ret++;
//				continue;
//			}
//			else {
//				for (int j = 3; j <= N; j++) {
//					int temp = 0;
//					while (N % j == 0) {
//						temp++;
//						N /= j;
//					}
//					if (temp)
//						odd *= (temp + 1);
//					if (odd > 2)
//						break;
//				}
//				if (odd == 2) {
//					ret++;
//				}
//			}
//			
//
//		}
//
//		cout << "Case #" << i + 1 << ": " << ret << endl;
//	}
//
//}