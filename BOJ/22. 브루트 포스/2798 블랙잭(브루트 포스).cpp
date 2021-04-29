//#include<iostream>
//
//using namespace std;
//
//int N, M;
//int arr[101];
//
//int cache[101];
//
//int main() {
//	cin >> N >> M;
//	
//	for (int i = 0; i < N;i++) {
//		cin >> arr[i];
//	}
//
//	int ret = 0;
//
//	for (int i = 0; i < N; i++) 
//		for (int j = i + 1; j < N; j++) 
//			for (int k = j + 1; k < N; k++) 
//				if ((arr[i] + arr[j] + arr[k] > ret) &(arr[i] + arr[j] + arr[k] <= M))
//					ret = arr[i] + arr[j] + arr[k];
//
//	cout << ret << endl;
//
//	return 0;
//}