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
//		//','�� ������ ���� �����ϰ�, ���۸� 0���� �ʱ�ȭ.
//		if (b[i] == ',') {
//			dq.push_back(temp);
//			temp = 0;
//		}
//		//���ۿ� ���� �����ش�.("(char) 1 = (int) 49" �̹Ƿ� 48�� ���־���.)
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
//			//����� ���� ���� ���
//			if (dq.empty()) {
//				error = true;
//				break;
//			}
//			else {
//				//�������̹Ƿ� �տ��� pop
//				if (count_R % 2 == 0) {
//					dq.pop_front();
//				}
//				//�������̹Ƿ� �ڿ��� pop
//				else {
//					dq.pop_back();
//				}
//			}
//
//		}
//	}
//
//	//�������ٸ�, ������ ����ϵ��� �Ѵ�.
//	if (error) {
//		cout << "error\n";
//	}
//	else {
//		cout << '[';
//		int size = dq.size();
//		for (int i = 0; i < size; i++) {
//			//�������� ��� �տ������� ����Ѵ�.
//			if (count_R % 2 == 0) {
//				cout << dq.front();
//				dq.pop_front();
//				if (!dq.empty())
//					cout << ',';
//			}
//			//�������̹Ƿ� �ڿ������� ���.
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