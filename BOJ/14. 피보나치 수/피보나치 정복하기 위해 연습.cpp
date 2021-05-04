////https://www.acmicpc.net/blog/view/28
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int cache[100];
////O(2^n)
//int fibonacci(int n) {
//	if (n <= 1)
//		return n;
//	else
//		return fibonacci(n - 1) + fibonacci(n - 2);
//}
//
//
////O(n)
//int fibonacci_memo(int n) {
//	if (n <= 1)
//		return n;
//	else if (cache[n] != 0)
//		return cache[n];
//	else
//		return cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
//}
//
////피사노 주기 활용
////M = 10^k일 때, k>2리면, 주기는 항상 15*10^(k-1)이다.
//const int mod = 1000000;
//const int p = mod / 10 * 15;
//int fibo[p] = { 0,1 };
//int fibonacci_pisano_period() {
//	long long n;
//	cin >> n;
//
//	for (int i = 2; i < p; i++) {
//		fibo[i] = fibo[i - 1] + fibo[i - 2];
//		fibo[i] %= mod;
//	}
//
//	cout << fibo[n%p] << '\n';
//	return 0;
//}
//
//
////행렬 활용
////K제곱은 O(lgK)만에 구할 수 있다.
//typedef vector<vector<long long>> matrix;
//const long long INF = 1000000007LL;
//matrix operator * (const matrix &a, const matrix &b) {
//	int n = a.size();
//	matrix c(n, vector<long long>(n));
//	for(int i=0;i<n;i++)
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < n; k++) {
//				c[i][j] += a[i][k] * b[k][j];
//			}
//			c[i][j] %= INF;
//		}
//	return c;
//}
//
//
//int main() {
//	long long n;
//	cin >> n;
//	//cout << fibonacci(n) << '\n';
//
//	if (n <= 1) {
//		cout << n << '\n';
//		return 0;
//	}
//
//	matrix ans = { {1,0}, {0,1} };
//	matrix a = { {1,1}, {1,0} };
//
//	while (n > 0) {
//		if (n % 2 == 1) {
//			ans = ans * a;
//		}
//		a = a * a;
//		n /= 2;
//	}
//	//(Fn+2) =(1 1)(Fn+1)
//	//(Fn+1) =(1 0)(Fn  )
//
//	cout << ans[0][1] << '\n';
//
//	return 0;
//}
//
