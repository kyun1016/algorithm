//#include<iostream>
//
//using namespace std;
//
//int N;
//int arr[12];
////������� ����, ����, ����, ������ ����
//int oper[4];
//int MAX = -1000000007, MIN = 1000000007;
//
//void calc(int iter, int add, int sub, int mul, int div, int ret) {
//	//��� ������ ���� �����, �� ����� �ִ�, �ּڰ��� �Ѵ��� Ȯ�����ش�.
//	if (iter == N - 1) {
//		if (ret > MAX)
//			MAX = ret;
//		if (ret < MIN)
//			MIN = ret;
//	}
//	//�� ��ȣ�� ������ �����ִٸ�, �� ������ �������ش�.
//	//�̶�, �츮�� ��� ����� ���� ���� ���̹Ƿ�, 4���� �������� ���� ������ �����Ѵ�.
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
//	//�Էµ� ���ڸ� ����
//	for (int i = 0;i < N;i++) {
//		cin >> arr[i];
//	}
//	//��ȣ�� ���� ����
//	for (int i = 0;i < 4;i++) {
//		cin >> oper[i];
//	}
//
//	calc(0, 0, 0, 0, 0, arr[0]);
//
//	cout << MAX << "\n" << MIN << endl;
//}