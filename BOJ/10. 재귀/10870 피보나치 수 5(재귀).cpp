//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//int cache[50];
//
//int build_fibo(const int& n) {
//	if (n < 0)
//		return 0;
//	int& ret = cache[n];
//	if (cache[n] != -1)
//		return ret;
//	
//	return ret = build_fibo(n - 1) + build_fibo(n - 2);
//}
//
//int main() {
//	memset(cache, -1, sizeof(cache));
//	cache[0] = 0; cache[1] = 1;
//
//	int N;
//	cin >> N;
//	cout << build_fibo(N) << endl;
//
//	return 0;
//}