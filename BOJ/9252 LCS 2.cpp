//#include<iostream>
//#include<string>
//#include<cstring>	//memsetÈ°¿ë
//
//std::string a, b;
//
//int cache[1001][1001];
//
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//
//int LCS(int size_of_a, int size_of_b) {
//	int &ret = cache[size_of_a][size_of_b];
//	if (ret != -1)
//		return ret;
//	if (size_of_a == 0 || size_of_b == 0)
//		return ret = 0;
//	else if (a[size_of_a - 1] == b[size_of_b - 1]) {
//		return ret = LCS(size_of_a - 1, size_of_b - 1) + 1;
//
//	}
//	else if (a[size_of_a-1] != b[size_of_b-1])
//		return ret = Max(LCS(size_of_a, size_of_b - 1), LCS(size_of_a - 1, size_of_b));
//}
//
//int main() {
//	std::cin >> a >> b;
//	memset(cache, -1, sizeof(cache));
//	std::cout << LCS(a.size(), b.size()) << std::endl;
//	int i = a.size();
//	int j = b.size();
//	std::string ret;
//	while (cache[i][j] != 0) {
//		if (cache[i][j] == cache[i - 1][j]) {
//			i--;
//		}
//		else if (cache[i][j] == cache[i][j - 1]) {
//			j--;
//		}
//		else {
//			ret = a.at(i - 1) + ret;
//			i--;
//			j--;
//		}
//	}
//
//	std::cout << ret << std::endl;
//}