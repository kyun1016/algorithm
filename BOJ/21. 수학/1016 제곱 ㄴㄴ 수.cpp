//#include<iostream>
//
//using namespace std;
//
//void calc(long long min, long long max) {
//	long long count=0;
//	long long i = 1;
//	long long square;
//	
//	for (i = 1; i <= 2000000; i++) {
//		square = i * i;
//		if (square >= min && square <= max) {
//			count++;
//			cout << square << endl;
//		}
//			
//	}
//
//	cout << max - min - count + 1 << endl;
//}
//
//int main() {
//	long long m, n;
//	cin >> m >> n;
//	calc(m, n);
//
//
//	return 0;
//
//
//}