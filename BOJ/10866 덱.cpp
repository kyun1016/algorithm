//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int deck[10001];
//int front_ptr;
//int back_ptr;
//int all_size;
//
//
//
//
//
//
//void push_front(int input) {
//	deck[front_ptr] = input;
//	front_ptr--;
//	all_size++;
//	if (front_ptr < 0)
//		front_ptr = 10000;
//}
//
//void push_back(int input) {
//	back_ptr++;
//	all_size++;
//	if (back_ptr > 10000)
//		back_ptr = 0;
//	deck[back_ptr] = input;
//	
//}
//
//void pop_front() {
//	if (all_size > 0) {
//		front_ptr++;
//		all_size--;
//		if (front_ptr > 10000)
//			front_ptr = 0;
//
//		cout << deck[front_ptr] << endl;
//		
//	}
//	else
//		cout << "-1\n";
//	
//}
//
//void pop_back() {
//	if (all_size > 0) {
//		cout << deck[back_ptr] << endl;
//
//		back_ptr--;
//		all_size--;
//		if (back_ptr < 0)
//			back_ptr = 10000;
//	}
//	else
//		cout << "-1\n";
//}
//
//void size() {
//	cout << all_size << endl;
//}
//
//void empty() {
//	if (all_size == 0)
//		cout << 1 << endl;
//	else
//		cout << 0 << endl;
//}
//
//void front() {
//	if (all_size > 0) {
//		if (front_ptr + 1 > 10000) {
//			cout << deck[0] << endl;
//		}
//		else
//			cout << deck[front_ptr + 1] << endl;
//	}
//	else
//		cout << "-1" << endl;
//}
//
//void back() {
//	if (all_size > 0) {
//		cout << deck[back_ptr] << endl;
//	}
//	else
//		cout << "-1" << endl;
//}
//
//
//void IF(string a) {
//	int input;
//	if (a == "push_front") {
//		cin >> input;
//		push_front(input);
//	}
//	else if (a == "push_back") {
//		cin >> input;
//		push_back(input);
//	}
//	else if (a == "pop_front") {
//		pop_front();
//	}
//	else if (a == "pop_back") {
//		pop_back();
//	}
//	else if (a == "size") {
//		size();
//	}
//	else if (a == "empty") {
//		empty();
//	}
//	else if (a == "front") {
//		front();
//	}
//	else if (a == "back") {
//		back();
//	}
//}
//
//
//
//int main() {
//	int n,input;
//	string a;
//
//	cin >> n;
//	while(n--) {
//		cin >> a;
//		IF(a);
//	}
//}