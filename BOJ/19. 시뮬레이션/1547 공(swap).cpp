//#include<iostream>
//
//using namespace std;
//
//int arr[3];
//
//void move_cup(int a, int b) {
//	if (arr[a-1] == 1 || arr[b-1] == 1) {
//		swap(arr[a-1], arr[b-1]);
//	}
//}
//
//int main() {
//	int M, a, b;
//	cin >> M;
//	arr[0] = 1;
//	while (M--) {
//		cin >> a >> b;
//		move_cup(a, b);
//	}
//	for (int i = 0; i < 3; i++) {
//		if (arr[i])
//			cout << i + 1 << endl;
//	}
//}