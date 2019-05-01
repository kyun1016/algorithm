//#include<iostream>
//#include<string>
//
//using namespace std;
//
//const int MAX_INT = 64;
//
//int arr[MAX_INT][MAX_INT];
//
//int quadTree(int N, int y, int x) {
//	//기저 사례: N이 1인 경우 자기 자신을 반환
//	if (N == 1) {
//
//		cout <<arr[y][x];
//		return 0;
//	}
//	
//	int find = arr[y][x];
//	int half = N / 2;
//	for (int i = y; i < y + N; i++) 
//		for (int j = x; j < x + N; j++) {
//			//기저 사례: 만일 구간 내에 자신과 다른 인자가 있는 경우, 4개로 나누어 압축한다.
//			if (find != arr[i][j]) {
//				cout << "(";
//				quadTree(half, y, x);
//				quadTree(half, y, x + half);
//				quadTree(half, y + half, x);
//				quadTree(half, y + half, x + half);
//				cout << ")";
//				return 0;
//			}
//		}
//	//모든 인자가 같은 경우이므로 자기 자신을 출력
//	cout << find;
//	return 0;
//}
//
//int main() {
//	int N;
//	string num;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> num;
//		for (int j = 0; j < N; j++)
//			arr[i][j] = num[j] - '0';
//	}
//
//	quadTree(N, 0, 0);
//
//
//	return 0;
//}