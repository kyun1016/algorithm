//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//// 필수 조건: n은 자연수
//// 1+2+0+...+n을 반환한다.
//int fastSum(int n) {
//	//기저 사례
//	if (n == 1) return 1;
//	if (n % 2 == 1) return fastSum(n - 1) + n;
//	return 2 * fastSum(n / 2) + (n / 2)*(n / 2);
//}
//
//
//
//int main() {
//	//입력부
//	int N;
//	cin >> N;
//
//	
//	//출력부
//	cout << fastSum(N) << endl;
//}