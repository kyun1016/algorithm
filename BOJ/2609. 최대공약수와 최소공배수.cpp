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
//	int a, b;
//	cin >> a >> b;
//	cout << gcd(a, b) << endl;
//	cout << lcm(a, b) << endl;
//}