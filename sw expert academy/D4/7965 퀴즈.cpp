#include<iostream>

using namespace std;

typedef unsigned long long ull;
const int INF = 1000000007;

int cache[1000001];

int pow(const int& k) {
	ull ret = 1;
	ull factor = k;
	int exp = k;
	while (exp) {
		if(exp & 1) {
			ret *= factor;
		}
		exp >>= 1;
		factor *= factor;
		factor %= INF;
		ret %= INF;
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	cache[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		cache[i] = (cache[i - 1] + pow(i)) % INF;
	}
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << "#" << i + 1 << " " << cache[N] << "\n";
	}


	return 0;
}