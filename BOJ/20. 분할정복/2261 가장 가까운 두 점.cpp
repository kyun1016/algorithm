//#include<iostream>
//#include<utility>	//pair()
//#include<algorithm>
//
//using namespace std;
//
//pair<int, int> dot[100000];
//
//void printDistant(int N) {
//	int ret = 1000000000;
//	int beforeX, beforeY,distant;
//	for (int i = 0; i < N - 1; i++) {
//		beforeX = dot[i].first;
//		beforeY = dot[i].second;
//		for (int j = i + 1; j < N; j++) {
//			distant = (dot[j].first - beforeX)*(dot[j].first - beforeX)
//				+ (dot[j].second - beforeY)*(dot[j].second - beforeY);
//			ret = min(ret, distant);
//		}
//	}
//	cout << ret;
//}
//
//int main() {
//	int N, x, y;
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> dot[i].first >> dot[i].second;
//	}
//
//	printDistant(N);
//
//	return 0;
//}