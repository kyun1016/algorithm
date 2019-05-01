//#include<iostream>
//#include<string>
//#include<deque>
//
//using namespace std;
//
//void AC(int n, string a, string b) {
//	b.erase(0, 1);
//	b.pop_back();
//	int temp(0);
//	deque<int> dq;
//
//	for (int i = 0; i < b.size(); i++) {
//		//','를 만나면 수를 저장하고, 버퍼를 0으로 초기화.
//		if (b[i] == ',') {
//			dq.push_back(temp);
//			temp = 0;
//		}
//		//버퍼에 수를 더해준다.("(char) 1 = (int) 49" 이므로 48을 빼주었다.)
//		else {
//			temp = (temp * 10) + (b[i]-48);
//		}
//	}
//	if (temp != 0)
//		dq.push_back(temp);
//
//	int count_R(0);
//	bool error = false;
//
//	for (int i = 0; i < a.size(); i++) {
//		if (a[i] == 'R')
//			count_R++;
//		else if (a[i] == 'D') {
//			//출력할 수가 없는 경우
//			if (dq.empty()) {
//				error = true;
//				break;
//			}
//			else {
//				//정방향이므로 앞에서 pop
//				if (count_R % 2 == 0) {
//					dq.pop_front();
//				}
//				//역방향이므로 뒤에서 pop
//				else {
//					dq.pop_back();
//				}
//			}
//
//		}
//	}
//
//	//에러였다면, 에러만 출력하도록 한다.
//	if (error) {
//		cout << "error\n";
//	}
//	else {
//		cout << '[';
//		int size = dq.size();
//		for (int i = 0; i < size; i++) {
//			//정방향인 경우 앞에서부터 출력한다.
//			if (count_R % 2 == 0) {
//				cout << dq.front();
//				dq.pop_front();
//				if (!dq.empty())
//					cout << ',';
//			}
//			//역방향이므로 뒤에서부터 출력.
//			else {
//				cout << dq.back();
//				dq.pop_back();
//				if (!dq.empty())
//					cout << ',';
//			}
//			
//		}
//		cout << "]\n";
//	}
//}
//
//
//int main() {
//	int t, n;
//	string a, b;
//
//	cin >> t;
//	while (t--) {
//		cin >> a >> n >> b;
//		AC(n, a, b);
//	}
//}