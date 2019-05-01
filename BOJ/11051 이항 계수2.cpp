//#include<iostream>
//
//int cache[1002][1002];
//int INF = 10007;
//
//int bino(int r, int n) {
//	int & ret = cache[r][n];
//	if (ret != 0) {
//		return ret;
//	}
//	else if(r== n||n ==0){
//		return ret = 1;
//	}
//	else {
//		return ret = (bino(r - 1, n) + bino(r - 1, n - 1)) % INF;
//	}
//}
//
//
//
//int main() {
//	int n, r;
//	std::cin >> n >> r;
//	std::cout<<bino(n, r)%INF;
//}