//#include<iostream>
//#include<stdio.h>
//
//int memo_0[50];
//int memo_1[50];
//
//void fibonacci() {
//	//�ʱⰪ ����
//	memo_0[0] = 1;
//	memo_0[1] = 0;
//	memo_1[0] = 0;
//	memo_1[1] = 1;
//
//	for (int i = 2; i < 42; i++) {
//		memo_0[i] = memo_0[i - 1] + memo_0[i - 2];
//		memo_1[i] = memo_1[i - 1] + memo_1[i - 2];
//	}
//}
//
//
//int main() {
//	int T, N;
//	scanf("%d", &T);
//	//�׳� ó���� ��� �� ���ع�����.
//	fibonacci();
//	while (T--) {
//		int count_0(0), count_1(0);
//		scanf("%d", &N);
//		printf("%d %d\n", memo_0[N], memo_1[N]);
//	}
//}