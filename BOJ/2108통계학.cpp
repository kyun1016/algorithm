//#include <cstdio>
//#include <algorithm>	//sort를 활용하자.
//#include <iostream>
//
//int number[500000];
//int count[8002];	//4001번이 0이다.
//int i;
//
//
//int sum(int n) {
//	int count = 0;
//	for (i = 0;i<n;i++) {
//		count += number[i];
//	}
//	return count;
//}
//
//int avr(int n) {
//	double ret(sum(n));
//	if (ret < 0) {
//		if ((sum(n) / n - ret / n) >= 0.5) return sum(n) / n - 1;
//		else return sum(n) / n;
//	}
//	else {
//		if ((ret / n - sum(n) / n) >= 0.5) return sum(n) / n + 1;
//		else return sum(n) / n;
//	}
//	
//}
//
//int mid(int n) {
//	return number[(n / 2)];
//}
//
////최빈값
//int mode(void) {
//	int cnt = 0;
//	int position(0);
//	for (i = 0;i<8002;i++) {
//		if (count[cnt] < count[i]) {
//			cnt = i;
//			position = 0;
//		}
//		else if (count[cnt] == count[i]) {
//			position++;
//			if (position == 1) {
//				cnt = i;
//			}
//		}
//	}
//	return cnt - 4000;
//}
//
//int range(int n) {
//	return number[n-1]-number[0];
//}
//
//int main() {
//	int n, i;
//	std::cin >> n;
//
//	for (i = 0;i<n;i++) {
//		std::cin >> number[i];
//		count[number[i] + 4000] ++;
//	}
//
//	std::sort(number, number + n);
//
//	printf("%d\n", avr(n));
//	printf("%d\n", mid(n));
//	printf("%d\n", mode());
//	printf("%d\n", range(n));
//}