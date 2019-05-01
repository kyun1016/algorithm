//#include<iostream>
//#include<stack>
//#include<string>
//#include<algorithm>
//
////인수로 int * ret을 받아 괄호의 값을 받자.
//bool wellMatched(const std::string& formula, int& ret) {
//	//여는 괄호 문자와 닫는 괄호 문자
//	const std::string opening("(["), closing(")]");
//	std::stack<char> openStack;
//	//ret을 초기화한다.
//	ret = 0;
//	//지금의 깊이를 측정하는 인수
//	int depth(0);
//	//괄호의 깊이에 있는 괄호의 값을 저장할 배열을 만든다.
//	int sum[15] = { 0 };
//
//	for (int i = 0;i < formula.size();i++) {
//		//여는 괄호인지 닫는 괄호인지 확인한다.
//		if (opening.find(formula[i]) != -1) {
//			openStack.push(formula[i]);
//			//괄호의 깊이를 더해준다.
//			depth++;
//		}
//		else {
//			if (openStack.empty()) return false;
//			if (opening.find(openStack.top()) != closing.find(formula[i]))
//				return false;
//			//짝을 맞춘 괄호는 스택에서 뺀다.
//			if (openStack.top() == '(') {
//				if (sum[depth] == 0)
//					sum[depth - 1] += 2;
//				else {
//					sum[depth - 1] += sum[depth] * 2;
//					sum[depth] = 0;
//				}
//			}
//			else {
//				if (sum[depth] == 0)
//					sum[depth - 1] += 3;
//				else {
//					sum[depth - 1] += sum[depth] * 3;
//					sum[depth] = 0;
//				}
//			}
//			depth--;
//			openStack.pop();
//		}
//	}
//	ret = sum[0];
//	//닫히지 않은 괄호가 없어야 성공
//	return openStack.empty();
//}
//
//int main() {
//	bool is_match;
//	int ret(0);
//	std::string Parenthesis;
//	std::cin >> Parenthesis;
//	is_match = wellMatched(Parenthesis, ret);
//	if (is_match)
//		std::cout << ret << "\n";
//	else
//		std::cout << 0 << "\n";
//
//}