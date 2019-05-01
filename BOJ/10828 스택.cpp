//#include<iostream>
//#include<string>
//using namespace std;
//
//class Stack {
//private:
//	int ptr=0;
//	int stk[10050] = { 0 };
//
//public:
//	void push(int x) {
//		stk[ptr++] = x;
//	}
//	void pop() {
//		if (ptr <= 0)
//			cout << "-1\n";
//		else
//			cout << stk[--ptr]<< "\n";
//	}
//	void size() {
//		cout << ptr << "\n";
//	}
//	void empty() {
//		if (ptr <= 0)
//			cout << "1\n";
//		else
//			cout << "0\n";
//	}
//	void top() {
//		if (ptr <= 0)
//			cout << "-1\n";
//		else
//			cout << stk[ptr - 1] << "\n";
//	}
//};
//
//
//
//int main() {
//	int n, x,order;
//	string a;
//	Stack s;
//	cin >> n;
//	for (int i = 0;i < n;i++) {
//		cin >> a;
//		if (a == "push") order = 1;
//		else if (a == "pop") order = 2;
//		else if (a == "size") order = 3;
//		else if (a == "empty") order = 4;
//		else if (a == "top") order = 5;
//
//		switch (order)
//		{
//		case 1:
//			cin >> x;
//			s.push(x);
//			break;
//
//		case 2:
//			s.pop();
//			break;
//
//		case 3:
//			s.size();
//			break;
//
//		case 4:
//			s.empty();
//			break;
//
//		case 5:
//			s.top();
//			break;
//		}
//	}
//
//	return 0;
//}
//
