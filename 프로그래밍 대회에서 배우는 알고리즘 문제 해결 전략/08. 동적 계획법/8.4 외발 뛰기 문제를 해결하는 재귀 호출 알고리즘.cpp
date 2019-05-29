//#include<iostream>
//
//using namespace std;
//
//int n, board[100][100];
//int cache[100][100];
//
//
//int jump(int x, int y) {
//	//기저 사례
//	if (y >= n || x >= n) return false;
//	if (x == n - 1 && y == n - 1) return true;
//
//	//메모이제이션
//	int &ret = cache[x][y];
//	if (ret != -1)
//		return ret;
//	
//	int jumpSize = board[x][y];
//	//직접 계산한 뒤 배열에 저장
//	return ret = (jump(x + jumpSize, y) || jump(x, y + jumpSize));
//}
//
//int main() {
//	int x, y;
//	cout << "x을 입력하세요 : "; cin >> x; cout << "y을 입력하세요 : "; cin >> y;
//
//	memset(cache, -1, sizeof(cache));
//
//	cout << jump(x, y);
//}