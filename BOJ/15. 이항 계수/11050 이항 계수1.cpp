//#include<cstdio>
//
//int bino(int a, int b) {
//	int ret(1);
//	for (int i = 1; i <= b; i++) {
//		ret *= a--;
//	}
//	while (b>0) {
//		ret /= b--;
//	}
//	return ret;
//}
//
//int main() {
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d", bino(a,b));
//}