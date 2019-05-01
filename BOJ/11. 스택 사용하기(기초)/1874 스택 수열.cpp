//#include<iostream>
//#include<stack>
//
//int main() {
//	char sol[200050];
//	int solptr(0);
//	int n, x, max(0);
//	std::cin >> n;
//
//	std::stack<int> s;
//	while (n--) {
//		std::cin >> x;
//		if (x>max) {
//			for (int i = max + 1;i <= x;i++) {
//				s.push(i);
//				sol[solptr++] = '+';
//			}
//		}
//		else
//			if (s.top() != x) {
//				std::cout << "NO";
//				return 0;
//			}
//		s.pop();
//		sol[solptr++] = '-';
//		if (max < x) max = x;
//	}
//	for (int i = 0;i < solptr;i++) std::cout << sol[i] << "\n";
//
//	return 0;
//}

//#include<iostream>
//
//int main() {
//	int stack[100050];
//	char sol[200050];
//	int n, ptr(0),solptr(0),x, max(0);
//	scanf("%d",&n);
//
//	while (n--) {
//		scanf("%d", &x);
//		if (x>max) {
//			for (int i = max;i < x;i++) {
//				stack[ptr++] = i + 1;
//				sol[solptr++] = '+';
//			}
//		}
//		else
//			if (stack[ptr - 1] != x) {
//				std::cout << "NO";
//				return 0;
//			}
//		ptr--;
//		sol[solptr++] = '-';
//		if (max < x) max = x;
//	}
//	for (int i = 0;i < solptr;i++) std::cout << sol[i] << "\n";
//
//	return 0;
//}