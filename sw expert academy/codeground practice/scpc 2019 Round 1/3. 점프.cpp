//#include <iostream>
//#include<algorithm>
//
//using namespace std;
//typedef unsigned long long ull;
//
//ull cache[447500];
//
////O(1)
//void preCalc() {
//	int k = 1;
//	for (int i = 1; i < 447255; i++) {
//		cache[i] = k + cache[i-1];
//		k++;
//	}
//	//cout << cache[447250] << endl;
//}
//
//
//int binarySearch(const ull& N) {
//	int first = 1;
//	int last = 447250;
//	int mid = 1;
//	while (first <= last) {
//		mid = (first + last) / 2;
//		//cout << mid << endl;
//		if (cache[mid] <= N && cache[mid + 1] > N)
//			return mid;
//		else {
//			if (cache[mid] > N)
//				last = mid - 1;
//			else
//				first = mid + 1;
//		}
//	}
//	return -1;
//}
//
//
//int findHell(const ull& N) {
//	ull temp = N;
//	int count = 0;
//	while (temp) {
//		int k = binarySearch(temp);
//		temp -= cache[k];
//		count += k;
//	}
//	return count;
//}
//
//
////ull findCount(const ull& N) {
////	ull temp = N;
////	ull count = 0;
////	while (temp) {
////		if (temp <= 15) {
////			int i = 0;
////			for (i; cache[i] <= temp; i++);
////			count += i-1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 105) {
////			int i = 5;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 1035) {
////			int i = 14;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 10011) {
////			int i = 45;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 100128) {
////			int i = 141;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 1000405) {
////			int i = 447;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 10001628) {
////			int i = 1414;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 100005153) {
////			int i = 4472;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 1000006281) {
////			int i = 14142;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 10000020331) {
////			int i = 44721;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////		else if (temp <= 100000404505) {
////			int i = 141421;
////			for (i; cache[i] <= temp; i++);
////			count += i - 1;
////			temp -= cache[i - 1];
////		}
////	}
////	return count;
////}
//
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int T, test_case;
//	ull x, y;
//	cin >> T;
//	preCalc();
//
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		cin >> x >> y;
//		int Max = 0;
//		if (y - x >= 20000) {
//			for (ull i = y - 20000; i <= y; i++) {
//				Max = max(findHell(i), Max);
//			}
//		}
//		else
//			for (ull i = x; i <= y; i++) {
//				Max = max(findHell(i), Max);
//			}
//		
//		cout << "Case #" << test_case + 1 << "\n";
//		cout << Max << "\n";
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}
//
