//#include<iostream>
//
//using namespace std;
//
//int mylower_bound(int * arr, int n, int key) {
//	int start = 0;
//	int end = n;
//
//	int mid = n;
//	while (end - start > 0) {
//		mid = (start + end) / 2;
//		if (arr[mid] < key)
//			start = mid + 1;
//		else
//			end = mid;
//	}
//	return end + 1;
//}
//
//int main() {
//	int arr[10] = { 1,2,3,4,5,6,7,7,7,9 };
//}