//#include<iostream>
//#include<cstring>		//memset활용 
//
//int height[503][503];
//int Count[503][503];
//int M, N;
//
//using namespace std;
//
//int move(int x, int y) {
//	int &ret = Count[x][y];
//	//기저사례
//	if (x == M && y == N)
//		return 1;
//	if (ret != -1)
//		return ret;
//
//	ret = 0;
//	if (x <= M && y <= N && x > 0 && y > 0) {
//		if (height[x][y] > height[x][y - 1]) {
//			ret += move(x, y - 1);
//		}
//		if (height[x][y] > height[x][y + 1]) {
//			ret += move(x, y + 1);
//		}
//		if (height[x][y] > height[x - 1][y]) {
//			ret += move(x - 1, y);
//		}
//		if (height[x][y] > height[x + 1][y]) {
//			ret += move(x + 1, y);
//		}
//	}
//		
//	return ret;
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> height[j][i];
//		}
//	}
//	
//	memset(Count, -1, sizeof(Count));
//	cout << move(1, 1);
//}