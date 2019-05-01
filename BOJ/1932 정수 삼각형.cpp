//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int tri[502][502];
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= i; j++) {
//			cin >> tri[i][j];
//			tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
//		}
//	}
//	int ret = 0;
//	for (int i = 1; i <= N; i++) {
//		ret = max(ret, max(tri[N][i], tri[N][i + 1]));
//	}
//	cout << ret << endl;
//}