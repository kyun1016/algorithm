//#include<iostream>
//#include<cmath>
//
//int calc(const int N) {
//	int count, sum(0);
//	int cnt;
//	count = 1;    //ó�� �ڱ� �ڽ��� ������ ���� �ݵ�� ����.
//
//				//length�� 1�� ������Ű�鼭 �������� ǥ���� �������� Ȯ������.
//	for (int i = 2; i <= N; i++) {
//		sum = (i*(i + 1)) / 2;
//		if (N - sum < 0)
//			break;
//		sum += ((N - sum) / i) * i;;
//		if (sum == N)
//			count++;
//	}
//
//	return count;
//}
//
//int main() {
//	int T, N;
//	std::cin >> T;
//	for (int i = 1; i <= T; i++) {
//		std::cin >> N;
//		std::cout << "#" << i << " " << calc(N) << std::endl;
//	}
//	return 0;
//}
