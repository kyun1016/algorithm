//#include<cstdio>
//
//long long bino(int N, int K) {
//	long long ret(1);
//	int Denominator(1);
//	if (N - K < K)
//		K = N - K;
//	if (N == K || K == 0)
//		return 1;
//	while (K--) {
//		ret *= N--;
//		ret /= Denominator++;
//	}
//	return ret;
//}
//
//
//int main() {
//	
//
//	int N, K;
//
//	while(1) {
//		scanf("%d %d", &N, &K);
//		if (N == 0 && K == 0)
//			break;
//		printf("%d\n", bino(N, K));
//	}
//}