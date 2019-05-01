//#include <iostream>
//
//void ascending_order(int arr[], int size) {
//	int temp;
//	for (int t = size - 1;t > 0;t--) {
//		for (int i = 0;i < t;i++) {
//			if (arr[i] > arr[t]) {
//				temp = arr[i];
//				arr[i] = arr[t];
//				arr[t] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[1000000] = {};
//	int n;
//	std::cin >> n;
//
//	for (int t = 0;t < n;t++) {
//		std::cin >> arr[t];
//	}
//	ascending_order(arr, n);
//	for (int t = 0;t < n;t++) {
//		std::cout << arr[t] << std::endl;
//	}
//}