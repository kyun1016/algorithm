//#include<iostream>
//#include<deque>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	int n, m, input, count(0);
//	cin >> n >> m;
//	deque<int> dq;
//	for (int i = 1; i <= n; i++) {
//		dq.push_back(i);
//	}
//	
//	deque<int>::iterator iter = dq.begin();
//	while (m--) {
//		cin >> input;
//		deque<int>::iterator backward = iter;
//		deque<int>::iterator forward = iter;
//		int count_forward(0), count_backward(0);
//		
//		while (*backward != input) {
//			if (*backward == dq.front())
//				while (*backward != dq.back())
//					backward++;
//			else
//				backward--;
//			count_backward++;
//		}
//		while (*forward != input) {
//			if (*forward == dq.back())
//				forward = dq.begin();
//			else
//				forward++;
//			count_forward++;
//		}
//
//		count += min(count_forward, count_backward);
//
//		if (*backward == dq.back()) {
//			if (dq.size() == 1) {
//				dq.pop_back();
//				break;
//			}
//			iter = dq.begin();
//			dq.pop_back();
//		}
//		else
//			iter = dq.erase(backward);
//	}
//	cout << count;
//}