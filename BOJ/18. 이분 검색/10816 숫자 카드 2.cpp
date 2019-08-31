////#include <stdio.h>
////#include <algorithm>
////#include <unordered_map>
////
////using namespace std;
////
////int n, m, a, b;
////unordered_map <int, int> mmap;
////
////bool compare(int a, int b) {
////	return a < b;
////}
////
////int main() {
////	scanf("%d", &n);
////	for (int i = 0; i < n; i++) {
////		scanf("%d", &a);
////		mmap[a]++;
////	}
////	scanf("%d", &m);
////	for (int i = 0; i < m; i++) {
////		scanf("%d", &b);
////		printf("%d ", mmap[b]);
////	}
////}
//
//#include<cstdio>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, M, ret;
//int arr[500010];
//
//int main() {
//	scanf("%d", &N);
//
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &arr[i]);
//	}
//
//	sort(arr, arr + N);
//	vector<pair<int, int>> sum;
//
//	sum.push_back({ arr[0],1 });
//	for (int i = 1; i < N; i++) {
//		if (arr[i] == sum.back().first)
//			sum.back().second++;
//		else
//			sum.push_back({ arr[i], 1 });
//	}
//
//	scanf("%d", &M);
//	int temp;
//
//	for (int i = 0; i < M; i++) {
//		scanf("%d", &temp);
//		ret = 0;
//		int left = 0, right = sum.size() - 1;
//		while (left <= right) {
//			int mid = (left + right) / 2;
//			if (sum[mid].first > temp) {
//				right = mid - 1;
//			}
//			else if (sum[mid].first < temp) {
//				left = mid + 1;
//			}
//			else {
//				ret = sum[mid].second;
//				break;
//			}
//		}
//		printf("%d ", ret);
//	}
//}