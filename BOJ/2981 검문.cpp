//
////전체를 반복하면서 M으로 나눠 나머지가 같은지 확인하는 구성
//
////#include<iostream>
////#include<algorithm>
////
////using namespace std;
////
////int arr[102];
////
////void calc(int T) {
////	for (int M = 2; M < arr[1]; M++) {
////		int flag = 0;
////		int check = arr[0] % M;
////		for (int i = 1; i < T; i++) {
////			if (check != arr[i] % M) {
////				flag++;
////				break;
////			}
////		}
////		if (flag == 0)
////			cout << M << " ";
////	}
////	cout << endl;
////}
////
////
////int main() {
////	int T;
////	cin >> T;
////	for (int i = 0; i < T; i++) {
////		cin >> arr[i];
////	}
////	sort(arr, arr + T);
////	calc(T);
////}
//
//
//////수학적으로 계산을 통해 
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int arr[101];
//
//int sol[101];
//
//int gcd(int a, int b) {
//	return a % b ? gcd(b, a%b) : b;
//}
//
//
//int main() {
//	int n, include_m, i, count(0);
//	cin >> n;
//	for (i = 0; i < n; i++)
//		cin >> arr[i];
//	sort(arr, arr + n);
//
//	include_m = arr[1] - arr[0];
//	for (i = 2; i < n; i++)
//		include_m = gcd(include_m, arr[i] - arr[i - 1]);
//
//	for (i = 1; i*i <= include_m; i++)
//		if (include_m%i == 0) {
//			sol[count++] = i;
//			if (i != include_m / i) sol[count++] = include_m / i;
//		}
//
//	sort(sol, sol + count);
//	for (int i = 0; i < count; i++) 
//		if (sol[i] != 1)
//			cout << sol[i] << " ";
//	
//}