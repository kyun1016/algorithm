//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//// �ʼ� ����: n�� �ڿ���
//// 1+2+0+...+n�� ��ȯ�Ѵ�.
//int fastSum(int n) {
//	//���� ���
//	if (n == 1) return 1;
//	if (n % 2 == 1) return fastSum(n - 1) + n;
//	return 2 * fastSum(n / 2) + (n / 2)*(n / 2);
//}
//
//
//
//int main() {
//	//�Էº�
//	int N;
//	cin >> N;
//
//	
//	//��º�
//	cout << fastSum(N) << endl;
//}