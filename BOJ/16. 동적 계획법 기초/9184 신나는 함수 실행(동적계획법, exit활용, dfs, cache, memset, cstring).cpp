#include<iostream>
#include<cstring>

using namespace std;

int a, b, c, w;

int cache[101][101][101];

int dfs(const int& a, const int& b, const int& c) {
	int& ret = cache[a + 50][b + 50][c + 50];

	if (ret != -1)
		return ret;

	if (a <= 0 || b <= 0 || c <= 0)
		return ret = 1;
	if (a > 20 || b > 20 || c > 20)
		return ret = dfs(20, 20, 20);
	if (a < b && b < c) 
		return ret = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
	return ret = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
}

int main() {
	memset(cache, -1, sizeof(cache));
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			exit(0);

		cout << "w\(" << a << ", " << b << ", " << c << "\) = " << dfs(a, b, c) << endl;
	}
}