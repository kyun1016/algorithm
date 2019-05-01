//#include<iostream>
//#include<stack>
//#include<string>
//#include<algorithm>
//
//bool wellMatched(const std::string& formula) {
//	//���� ��ȣ ���ڿ� �ݴ� ��ȣ ����
//	const std::string opening("("), closing(")");
//	//���� ��ȣ���� ������� ��� ����
//	std::stack<char> openStack;
//	for (int i = 0;i < formula.size();i++) {
//		//���� ��ȣ���� �ݴ� ��ȣ���� Ȯ���Ѵ�.
//		if (opening.find(formula[i]) != -1)
//			//���� ��ȣ��� ������ ���ÿ� ����ִ´�.
//			openStack.push(formula[i]);
//		else {
//			//�� ���� ��� ���� �� ���� ���ڿ� ���纸��.
//			//������ ��� �ִ� ��쿡�� ����
//			if (openStack.empty()) return false;
//			//���� ¦�� ���� �ʾƵ� ����(��� �� �ڵ忡���� "({["�� ")}]"�� 3���� ��ȣ�� ���Ǵ� ��������.
//			if (opening.find(openStack.top()) != closing.find(formula[i]))
//				return false;
//			//¦�� ���� ��ȣ�� ���ÿ��� ����.
//			openStack.pop();
//		}
//	}
//
//	//������ ���� ��ȣ�� ����� ����
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