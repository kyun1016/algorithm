//#include<iostream>
//
//using namespace std;
//
//int n, board[100][100];
//int cache[100][100];
//
//
//int jump(int x, int y) {
//	//���� ���
//	if (y >= n || x >= n) return false;
//	if (x == n - 1 && y == n - 1) return true;
//
//	//�޸������̼�
//	int &ret = cache[x][y];
//	if (ret != -1)
//		return ret;
//	
//	int jumpSize = board[x][y];
//	//���� ����� �� �迭�� ����
//	return ret = (jump(x + jumpSize, y) || jump(x, y + jumpSize));
//}
//
//int main() {
//	int x, y;
//	cout << "x�� �Է��ϼ��� : "; cin >> x; cout << "y�� �Է��ϼ��� : "; cin >> y;
//
//	memset(cache, -1, sizeof(cache));
//
//	cout << jump(x, y);
//}