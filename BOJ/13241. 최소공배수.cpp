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
//long long gcd(int a, int b) {
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
//long long lcm(long long a, long long b) {
//	return (a * b) / gcd(a, b);
//}
//
//
//int main() {
//	long long a, b;
//
//	cin >> a >> b;
//	cout << lcm(a, b) << endl;
//}