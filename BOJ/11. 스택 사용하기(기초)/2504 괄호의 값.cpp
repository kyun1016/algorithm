//#include<iostream>
//#include<stack>
//#include<string>
//#include<algorithm>
//
////�μ��� int * ret�� �޾� ��ȣ�� ���� ����.
//bool wellMatched(const std::string& formula, int& ret) {
//	//���� ��ȣ ���ڿ� �ݴ� ��ȣ ����
//	const std::string opening("(["), closing(")]");
//	std::stack<char> openStack;
//	//ret�� �ʱ�ȭ�Ѵ�.
//	ret = 0;
//	//������ ���̸� �����ϴ� �μ�
//	int depth(0);
//	//��ȣ�� ���̿� �ִ� ��ȣ�� ���� ������ �迭�� �����.
//	int sum[15] = { 0 };
//
//	for (int i = 0;i < formula.size();i++) {
//		//���� ��ȣ���� �ݴ� ��ȣ���� Ȯ���Ѵ�.
//		if (opening.find(formula[i]) != -1) {
//			openStack.push(formula[i]);
//			//��ȣ�� ���̸� �����ش�.
//			depth++;
//		}
//		else {
//			if (openStack.empty()) return false;
//			if (opening.find(openStack.top()) != closing.find(formula[i]))
//				return false;
//			//¦�� ���� ��ȣ�� ���ÿ��� ����.
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
//	//������ ���� ��ȣ�� ����� ����
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