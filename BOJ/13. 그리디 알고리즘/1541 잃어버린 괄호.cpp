//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	string N;
//	cin >> N;
//
//	int ret = 0;
//	bool flag = false;
//	int stack = 0;
//	for (int i = 0; i < N.length(); i++) {
//		if (N[i] == '+') {
//			if (flag) {
//				ret -= stack;
//				stack = 0;
//			}
//			else {
//				ret += stack;
//				stack = 0;
//			}
//		}
//		else if (N[i] == '-') {
//			if (flag) {
//				ret -= stack;
//				stack = 0;
//			}
//			else {
//				flag = true;
//				ret += stack;
//				stack = 0;
//			}
//		}
//		else {
//			stack *= 10;
//			stack += N[i] - 48;
//		}
//		//cout << stack << " " << ret << endl;
//	}
//	if (flag)
//		ret -= stack;
//	else
//		ret += stack;
//
//
//	cout << ret;
//
//	return 0;
//}