//#include<iostream>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
////���������� �޸������̼� ����.
//string cache[102][102];
//
////���Ǵ� ������ ������ �ʵ��� const�� �����Ͽ���.
//string string_add(const string num1, const string num2) {
//	long long sum = 0;
//	//num�� copy�� �����Ͽ���.
//	string copy1(num1), copy2(num2);
//	string ret;
//
//	//copy1, copy2, sum�� ��� ������������� ����� ����Ѵ�.
//	while (!copy1.empty() || !copy2.empty() || sum) {
//		if (!copy1.empty()) {
//			//copy1�� �ִ� ������ ���ڴ� char���·� ����Ǿ������Ƿ�(ascii����) '0'�� ���־� ����ȭ ���־���.
//			sum += copy1.back() - '0';
//			copy1.pop_back();
//		}
//		if (!copy2.empty()) {
//			sum += copy2.back() - '0';
//			copy2.pop_back();
//		}
//		//sum�� ���� �ڸ����� ret�� �־�����.(�̶�, char������ ���Ƿ� �ٽ� '0'�� �����ش�)
//		ret.push_back((sum % 10) + '0');
//		sum /= 10;
//	}
//
//	reverse(ret.begin(), ret.end());
//	return ret;
//}
//
//
//string bino(const int r, const int n) {
//	//�޸������̼��� Ȱ���� ����� ���δ�.
//	string & ret = cache[r][n];
//
//	//�ʱⰪ ����.
//	if (ret != "") {
//		//�̹� ����� ���� ��� �ٷ� �����Ѵ�.
//		return ret;
//	}
//	else if(r== n||n ==0){
//		//r==n�̰ų� n==0�� ��� '1'(char�� ����)�� �����Ѵ�.
//		return ret = '1';
//	}
//	else {
//		//���ȣ���� �Ͽ� �ݺ��Ѵ�.
//		return ret = string_add(bino(r - 1, n), bino(r - 1, n - 1));
//	}
//}
//
//
//
//int main() {
//	int n, r;
//	std::cin >> n >> r;
//
//	std::cout << bino(n, r);
//}