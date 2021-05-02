#include<iostream>
#include<algorithm>

using namespace std;

int N;
int cache[1000007];

//활용시 시간이 너무 과도하게 소모되어 for문을 활용해 수정
int recursive_function(const int& depth) {
	int& ret = cache[depth];
	int temp=987654321;
	if (depth == 1)
		return ret = 0;
	if (depth % 3 == 0)
		temp = 1 + recursive_function(depth / 3);
	if (depth % 2 == 0)
		temp = 1 + min(recursive_function(depth / 2), temp);
	ret = min(1 + recursive_function(depth - 1), temp);

	return ret;
}

int main() {
	cin >> N;
	//cout << recursive_function(N) << endl;

	cache[1] = 0;
	cache[2] = 1;
	cache[3] = 1;
	for (int i = 4; i <= N; i++)
		cache[i] = min(cache[i - 1] + 1, min(cache[i / 2] + 1 + i % 2, cache[i / 3] + 1 + i % 3));
	cout << cache[N] << endl;
}