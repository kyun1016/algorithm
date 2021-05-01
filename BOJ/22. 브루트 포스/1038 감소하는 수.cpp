#include<iostream>
#include<vector>
#include<algorithm>

typedef unsigned long long ull;

std::vector<ull> dec_num;

void downSizeingNum(int N) {
	if (N > 1022) {
		std::cout << "-1" << std::endl;
		return;
	}
		

	for (int i = 1; i <= 1023; i++) {
		ull num = 0;// i에 대응되는 감소하는 수
		int tmp_i = i;
		for (int idx = 9; idx >= 0; idx--) {
			if (tmp_i % 2 == 1)
				num = 10 * num + idx;
			tmp_i /= 2;
		}
		dec_num.push_back(num);
	}
	sort(dec_num.begin(), dec_num.end());
	std::cout << dec_num[N] << std::endl;
}

int main() {
	int N;
	std::cin >> N;
	downSizeingNum(N);

	return 0;
}