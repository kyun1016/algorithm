//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int Arr[500001];
//int Arr2[500001];
//
//void binarySearch(const int & N, const int & K) {
//	int first = 0;
//	int last = N - 1;
//	int mid = 1;
//	while (first <= last) {
//		mid = (first + last) / 2;
//		//cout << mid << endl;
//		if (Arr[mid] == K) {
//			cout << "1\n";
//			return;
//		}
//		else {
//			if (Arr[mid] > K)
//				last = mid - 1;
//			else
//				first = mid + 1;
//		}
//	}
//	cout << "0\n";
//	return;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N, M;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> Arr[i];
//	}
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> Arr2[i];
//	}
//
//	sort(Arr, Arr + N);
//	for (int i = 0; i < M; i++) {
//		binarySearch(N, Arr2[i]);
//	}
//
//}