//#include<iostream>
//#include<deque>
//#include<string>
//
//using namespace std;
//
//int N;
//string a;
//deque<int> arr;
//
//int main() {
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	cin >> N;
//	int temp;
//	for (int i = 0;i < N;i++) {
//		cin >> a;
//		if (a == "push") {
//			cin >> temp;
//			arr.push_back(temp);
//		}
//		else if (a == "pop") {
//			if (!arr.empty()) {
//				cout << arr.front() << "\n";
//				arr.pop_front();
//			}
//			else
//				cout << -1 << "\n";
//		}
//		else if (a == "size") {
//			cout << arr.size() << "\n";
//
//		}
//		else if (a == "empty") {
//			if (arr.empty())
//				cout << 1 << "\n";
//			else
//				cout << 0 << "\n";
//		}
//		else if (a == "front") {
//			if (arr.empty())
//				cout << -1 << "\n";
//			else
//				cout << arr.front() << "\n";
//		}
//		else if (a == "back") {
//			if (arr.empty())
//				cout << -1 << "\n";
//			else
//				cout << arr.back() << "\n";
//		}
//	}
//}