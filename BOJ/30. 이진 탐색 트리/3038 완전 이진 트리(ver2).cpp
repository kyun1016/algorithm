//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector<int> arr[16];
//vector<int> depth[16];
//
//void preCalc() {
//	arr[1].push_back(1);
//	depth[1].push_back(1);
//	for (int i = 2; i <= 15; i++) {
//		arr[i].resize((1 << i) - 1);
//		arr[i][0] = 1;
//		depth[i].resize((1 << i) - 1);
//		depth[i][0] = 1;
//		for (int j = 1; j < (1 << (i - 1)); j++) {
//			depth[i][j] = depth[i - 1][j - 1] + 1;
//			depth[i][(1<<(i - 1)) + j - 1] = depth[i - 1][j - 1] + 1;
//			if (depth[i][j] != i) {
//				arr[i][j] = arr[i - 1][j - 1] * 2 + 1;
//				arr[i][(1 << (i - 1)) + j - 1] = arr[i - 1][j - 1] * 2;
//			}
//			else {
//				arr[i][j] = arr[i - 1][j - 1] * 2;
//				arr[i][(1 << (i - 1)) + j - 1] = arr[i - 1][j - 1] * 2 + 1;
//			}
//		}
//	}
//
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int N;
//	cin >> N;
//
//	preCalc();
//
//	for (int i = 0; i < (1 << N) - 1; i++) {
//		cout << arr[N][i] << " ";
//	}
//
//
//	return 0;
//}