//#include<iostream>
//
//using namespace std;
//
//const int MAX_INT = 100;
//
//int matrixA[MAX_INT][MAX_INT];
//int matrixB[MAX_INT][MAX_INT];
//int matrixRet[MAX_INT][MAX_INT];
//
//void matrixMultiplication(int aColumn, int aRow, int bColumn, int bRow) {
//	
//	//���κκ�(�࿡ �ش��Ѵ�.)
//	for (int i = 0; i < aColumn; i++) {
//		//���κκ�(���� �ش��ϰ�, �ΰ��� �ݺ��ϴ� ������ (m*n) X (n*k)�� ����� (m*K)�� ����� �Ǳ� �����̴�.
//		for (int j = 0; j < bRow; j++) {
//			for (int k = 0; k < aRow; k++) {
//				//���ο� ����� ���Ҵ� ������ ����� ���� ���� ���� ��� ���� ���̴�.
//				matrixRet[i][j] += matrixA[i][k] * matrixB[k][j];
//			}
//			cout << matrixRet[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//
//int main() {
//	int aN, aM, bN,bM;
//	cin >> aN >> aM;
//	for (int column = 0; column < aN; column++) 
//		for (int row = 0; row < aM; row++)
//			cin >> matrixA[column][row];
//
//	cin >> bN >> bM;
//	for (int column = 0; column < bN; column++)
//		for (int row = 0; row < bM; row++)
//			cin >> matrixB[column][row];
//
//	matrixMultiplication(aN, aM, bN, bM);
//
//	return 0;
//}