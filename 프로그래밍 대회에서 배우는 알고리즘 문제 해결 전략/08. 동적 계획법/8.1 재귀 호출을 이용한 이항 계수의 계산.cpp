//#include<iostream>
//
//using namespace std;
//
//int bino(int n, int r) {
//	//���� ���:n=r(��� ���Ҹ� �� ���� ���) Ȥ�� r=0(�� ���Ұ� ���� ���)
//	if (r == 0 || n == r) return 1;
//	return bino(n - 1, r - 1) + bino(n - 1, r);
//}
//
//int main() {
//	int n, r;
//	cout << "n�� �Է��ϼ��� : ";
//	cin >> n;
//	cout << "r�� �Է��ϼ��� : ";
//	cin >> r;
//	cout << bino(n, r);
//}