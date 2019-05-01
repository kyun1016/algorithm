//#include<iostream>
//#include<string>
//
//class queue {
//private:
//	int front =0 , rear = 0,num = 0;
//	int que[10000] = { 0 };
//
//public:
//	void push(int x) {
//		num++;
//		que[rear++] = x;
//	}
//	void pop() {
//		if(num <= 0)
//			std::cout << "-1\n";
//		else {
//			std::cout << que[front++] << "\n";
//			num--;
//		}
//	}
//	void size() {
//		std::cout << num << "\n";
//	}
//	void empty() {
//		if (num > 0)
//			std::cout << "0\n";
//		else
//			std::cout << "1\n";
//	}
//	void fron() {
//		if (num <= 0)
//			std::cout << "-1\n";
//		else
//			std::cout << que[front] << "\n";
//	}
//	void back() {
//		if (num <= 0)
//			std::cout << "-1\n";
//		else
//			std::cout << que[rear-1] << "\n";
//	}
//};
//
//int main() {
//	int n, x;
//	queue q;
//	std::string order;
//	std::cin >> n;
//	while (n--) {
//		std::cin >> order;
//
//		if (order == "push") {
//			std::cin >> x;
//			q.push(x);
//		}
//		else if (order == "pop")
//			q.pop();
//		else if (order == "size")
//			q.size();
//		else if (order == "empty")
//			q.empty();
//		else if (order == "front")
//			q.fron();
//		else if (order == "back")
//			q.back();
//	}
//
//}