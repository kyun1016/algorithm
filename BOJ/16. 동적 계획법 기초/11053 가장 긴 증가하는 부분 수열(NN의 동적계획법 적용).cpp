#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[1001], lis[1001],cache[1001],lis_length,N;

int lis2(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < N; next++) 
		if (arr[start] < arr[next])
			ret = max(ret, lis2(next) + 1);
	return ret;
}


int main() {
	cin >> N;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int* pos = lower_bound(lis, lis + lis_length, arr[i]);
		*pos = arr[i];
		if (pos == lis_length + lis)
			lis_length++;
	}

	//cout << lis_length << endl;

	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret = max(ret, lis2(i));
	}
	cout << ret << endl;

	

	return 0;
}