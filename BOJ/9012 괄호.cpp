//#include<iostream>
//#include<stack>
//#include<string>
//#include<algorithm>
//
//bool wellMatched(const std::string& formula) {
//	//여는 괄호 문자와 닫는 괄호 문자
//	const std::string opening("("), closing(")");
//	//열린 괄호들을 순서대로 담는 스택
//	std::stack<char> openStack;
//	for (int i = 0;i < formula.size();i++) {
//		//여는 괄호인지 닫는 괄호인지 확인한다.
//		if (opening.find(formula[i]) != -1)
//			//여는 괄호라면 무조건 스택에 집어넣는다.
//			openStack.push(formula[i]);
//		else {
//			//이 외의 경우 스택 맨 위의 문자와 맞춰보자.
//			//스택이 비어 있는 경우에는 실패
//			if (openStack.empty()) return false;
//			//서로 짝이 맞지 않아도 실패(사실 이 코드에서는 "({["과 ")}]"의 3개의 괄호가 사용되는 예제였다.
//			if (opening.find(openStack.top()) != closing.find(formula[i]))
//				return false;
//			//짝을 맞춘 괄호는 스택에서 뺀다.
//			openStack.pop();
//		}
//	}
//
//	//닫히지 않은 괄호가 없어야 성공
//	return openStack.empty();
//}
//
//int main() {
//	bool is_match;
//	int n;
//	std::string Parenthesis;
//	std::cin >> n;
//	for (int i = 0; i < n;i++) {
//		std::cin >> Parenthesis;
//		is_match = wellMatched(Parenthesis);
//		if (is_match)
//			std::cout << "YES\n";
//		else
//			std::cout << "NO\n";
//	}
//	
//}