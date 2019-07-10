//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector<int> arr;
//int ret;
//int MAX;
//
//void calc(const int& N, const int& depth) {
//	bool check_this = false;
//	for (int i = 0; i < (1 << depth); i++) {
//		int temp_MAX = 0;
//		for (int j = i * (1 << (N - depth)); j < (i + 1) * (1 << (N - depth)); j++) {
//			temp_MAX = max(temp_MAX, arr[j]);
//			if (temp_MAX == MAX)
//				break;
//		}
//		if (temp_MAX == MAX)
//			continue;
//		ret += (MAX - temp_MAX);
//		for (int j = i * (1 << (N - depth)); j < (i + 1) * (1 << (N - depth)); j++) {
//			arr[j] += (MAX - temp_MAX);
//		}
//		if (MAX != temp_MAX && !check_this)
//			check_this = true;
//	}
//	if (check_this && N > depth)
//		calc(N, depth + 1);
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int N, temp;
//	cin >> N;
//
//	arr.resize((1 << N));
//	
//	for (int i = 1; i <= N; i++) {
//		for (int j = 0; j < (1 << i); j++) {
//			cin >> temp;
//			ret += temp;
//			for (int k = j * (1 << (N - i)); k < (j + 1) * (1 << (N - i)); k++) {
//				arr[k] += temp;
//			}
//		}
//	}
//
//	//for (int i = 0; i < (1<<N); i++) {
//	//	cout << arr[i] << " ";
//	//}
//	for (int i = 0; i < (1<<N); i++) {
//		MAX = max(MAX, arr[i]);
//	}
//
//
//	calc(N, 1);
//
//	cout << ret;
//
//	return 0;
//}