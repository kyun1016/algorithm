//#include<iostream>
//
//using namespace std;
//
//int value[10001];
//int max_drink[10001];
//
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//
//void calc(int N) {
//	//초기값
//	max_drink[1] = value[1];
//	max_drink[2] = Max(value[2], max_drink[1] + value[2]);
//	for (int i = 3; i <= N; i++) {
//		//이전 계단 오르기와 같은 점화식
//		max_drink[i] = Max(max_drink[i - 2] + value[i], max_drink[i - 3] + value[i - 1] + value[i]);
//		//추가적으로, 마시지 않는 선택도 존재한다.
//		max_drink[i] = Max(max_drink[i - 1], max_drink[i]);
//	}
//}
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> value[i];
//	}
//
//	calc(N);
//	
//	cout << max_drink[N] << endl;
//}