//#include<iostream>
//
//using namespace std;
//
//int N;
//int arr[12];
////순서대로 덧셈, 뺄셈, 곱셈, 나눗셈 개수
//int oper[4];
//int MAX = -1000000007, MIN = 1000000007;
//
//void calc(int iter, int add, int sub, int mul, int div, int ret) {
//	//모든 연산이 끝난 경우라면, 그 결과가 최댓값, 최솟값을 넘는지 확인해준다.
//	if (iter == N - 1) {
//		if (ret > MAX)
//			MAX = ret;
//		if (ret < MIN)
//			MIN = ret;
//	}
//	//각 부호의 연산이 남아있다면, 그 연산을 수행해준다.
//	//이때, 우리는 모든 경우의 수를 따질 것이므로, 4가지 방향으로 전부 연산을 시행한다.
//	else {
//		if (add < oper[0]) {
//			calc(iter + 1, add + 1, sub, mul, div, ret + arr[iter + 1]);
//		}
//		if (sub < oper[1]) {
//			calc(iter + 1, add, sub + 1, mul, div, ret - arr[iter + 1]);
//		}
//		if (mul < oper[2]) {
//			calc(iter + 1, add, sub, mul + 1, div, ret * arr[iter + 1]);
//		}
//		if (div < oper[3]) {
//			calc(iter + 1, add, sub, mul, div + 1, ret / arr[iter + 1]);
//		}
//	}
//}
//
//int main() {
//	cin >> N;
//	//입력된 숫자를 저장
//	for (int i = 0;i < N;i++) {
//		cin >> arr[i];
//	}
//	//부호의 개수 저장
//	for (int i = 0;i < 4;i++) {
//		cin >> oper[i];
//	}
//
//	calc(0, 0, 0, 0, 0, arr[0]);
//
//	cout << MAX << "\n" << MIN << endl;
//}