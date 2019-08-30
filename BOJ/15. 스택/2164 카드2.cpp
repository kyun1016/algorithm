//#include<iostream>
//#include<algorithm>
//#include<deque>
//#include<vector>
//#include<stack>
//
//using namespace std;
//
//int calc(const int& N) {
//	deque<int> de;
//	for (int i = 1; i <= N; i++) {
//		de.push_back(i);
//	}
//	while (de.size() >= 2) {
//		de.pop_front();
//		de.push_back(de[0]);
//		de.pop_front();
//	}
//
//	return de[0];
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N;
//	cin >> N;
//	
//	cout << calc(N);
//}