//#include<iostream>
//#include<string>
//
//using namespace std;
//
//string star[10000];
//
//void makeStar(const int N) {
//	if (N == 1) {
//		cout << "*";
//		return;
//	}
//
//	int count = N;
//
//	star[0] = "***";
//	star[1] = "* *";
//	star[2] = "***";
//	string space = "   ";
//	int i = 3;
//	int k = 0;
//	while (count>3) {
//		for (k = 0; k < i; k++) {
//			star[k] = star[k];
//			star[k + i] = star[k];
//			star[k + 2 * i] = star[k];
//		}
//		for (k = 0; k < i; k++) {
//			star[k] = star[k] + star[k] + star[k];
//			star[k + i] = star[k + i] + space + star[k+ i];
//			star[k + 2 * i] = star[k];
//		}
//		space = space + space + space;
//		i *= 3;
//		count /= 3;
//	}
//
//	for (i = 0; i < N; i++) {
//		cout << star[i] << endl;
//	}
//	
//}
//
//int main() {
//	int N;
//	cin >> N;
//
//	makeStar(N);
//
//	return 0;
//}