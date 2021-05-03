#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1001];
int up_cache[1001], down_cache[1001];

int lis(int start) {
	int& ret = up_cache[start];
	if (ret != 0)
		return ret;
	ret = 1;
	for (int next = start - 1; next >= 0; next--)
		if (arr[start] > arr[next])
			ret = max(ret, lis(next) + 1);
	return ret;
}

int lis2(int start) {
	int& ret = down_cache[start];
	if (ret != 0)
		return ret;
	ret = 1;
	for (int next = start + 1; next < N; next++)
		if (arr[start] > arr[next])
			ret = max(ret, lis2(next) + 1);
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret = max(ret, lis(i) + lis2(i) - 1);
	}

	for (int i = 0; i < N; i++) {
		cout << up_cache[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << down_cache[i] << endl;
	}



	cout << ret << endl;

	return 0;
}