//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//// ��������� ǥ���ϴ� SquareMatrix Ŭ������ �ִٰ� ��������.
//class SquareMatrix;
////n*n ũ���� �׵� ���(identity matrix)�� ��ȯ�ϴ� �Լ�
//SquareMatrix identity(int n);
////A^m�� ��ȯ�Ѵ�.
//SquareMatrix pow(const SquareMatrix& A, int m) {
//	//���� ���:A^0 = I
//	if (m == 0) return identity(A.size());
//	if (m % 2 > 0) return pow(A, m - 1) *A;
//	SquareMatrix half = pow(A, m / 2);
//	// A^m = (A^(m/2))*(A^(m/2))
//	return half * half;
//}
//
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