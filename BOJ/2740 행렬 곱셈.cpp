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
//	//세로부분(행에 해당한다.)
//	for (int i = 0; i < aColumn; i++) {
//		//가로부분(열에 해당하고, 두개를 반복하는 이유는 (m*n) X (n*k)의 결과는 (m*K)의 행렬이 되기 때문이다.
//		for (int j = 0; j < bRow; j++) {
//			for (int k = 0; k < aRow; k++) {
//				//새로운 행렬의 원소는 곱해진 행렬의 열과 행의 곱을 모두 더한 값이다.
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