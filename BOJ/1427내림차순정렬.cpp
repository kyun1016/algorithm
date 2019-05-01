//#include<iostream>
//#include<string>
//
//int count[10];
//
//void counting_sort(const int request) {
//	int copy(request);
//	while (copy) {
//		count[copy % 10]++;
//		copy /= 10;
//	}
//}
//
//void print_descending_order(const int request) {
//	int n = std::to_string(request).length();
//	for (int i = 9;i >= 0;i--) {
//		for (int t = 0;t < count[i];t++) {
//			std::cout << i;
//		}
//	}
//}
//
//
//int main() {
//	int input;
//	std::cin >> input;
//	counting_sort(input);
//	print_descending_order(input);
//
//	return 0;
//}