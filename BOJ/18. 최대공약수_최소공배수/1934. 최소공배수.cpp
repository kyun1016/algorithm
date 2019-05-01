//#include<iostream>
//
//using namespace std;
//
//void swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int gcd(int a, int b) {
//	int temp;
//	if (a < b)
//		swap(a, b);
//	while (b != 0) {
//		temp = a % b;
//		a = b;
//		b = temp;
//	}
//	return a;
//}
//
//int lcm(int a, int b) {
//	return (a * b) / gcd(a, b);
//}
//
//
//int main() {
//	int T, a, b;
//	cin >> T;
//	while (T--)
//	{
//		cin >> a >> b;
//		cout << lcm(a, b) << endl;
//	}
//}