//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int can_wear(int a, int wear_type_count[]) {
//	int ret(1);
//	for (int i = 0; i < a; i++) {
//		ret *= wear_type_count[i]+1;
//	}
//	return ret - 1;
//}
//
//int main() {
//	int T, N;
//	cin >> T;
//	string a, b;
//
//	while (T--) {
//		cin >> N;
//		int string_count(0);
//		string wear_type[31];
//		int wear_type_count[31] = {0};
//
//		for (int i = 0; i < N;i++) {
//			cin >> a >> b;
//			for (int j = 0; j <= string_count; j++) {
//				if (wear_type[j] == b) {
//					wear_type_count[j]++;
//					break;
//				}
//				if (j == string_count) {
//					wear_type[j] = b;
//					wear_type_count[j]++;
//					string_count++;
//					break;
//				}
//			}
//		}
//		cout << can_wear(string_count, wear_type_count) << endl;
//	}
//}