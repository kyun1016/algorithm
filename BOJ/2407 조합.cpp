//#include<iostream>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
////전역변수로 메모이제이션 선언.
//string cache[102][102];
//
////사용되는 변수가 변하지 않도록 const로 선언하였다.
//string string_add(const string num1, const string num2) {
//	long long sum = 0;
//	//num을 copy에 복사하였다.
//	string copy1(num1), copy2(num2);
//	string ret;
//
//	//copy1, copy2, sum이 모두 비어있을때까지 계산을 계속한다.
//	while (!copy1.empty() || !copy2.empty() || sum) {
//		if (!copy1.empty()) {
//			//copy1에 있는 마지막 문자는 char형태로 저장되어있으므로(ascii형식) '0'을 빼주어 정수화 해주었다.
//			sum += copy1.back() - '0';
//			copy1.pop_back();
//		}
//		if (!copy2.empty()) {
//			sum += copy2.back() - '0';
//			copy2.pop_back();
//		}
//		//sum의 일의 자릿수를 ret에 넣어주자.(이때, char형으로 들어가므로 다시 '0'을 더해준다)
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
//	//메모이제이션을 활용해 계산을 줄인다.
//	string & ret = cache[r][n];
//
//	//초기값 선언.
//	if (ret != "") {
//		//이미 계산이 끝난 경우 바로 리턴한다.
//		return ret;
//	}
//	else if(r== n||n ==0){
//		//r==n이거나 n==0인 경우 '1'(char로 선언)을 리턴한다.
//		return ret = '1';
//	}
//	else {
//		//재귀호출을 하여 반복한다.
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