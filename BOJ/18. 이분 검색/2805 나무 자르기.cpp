#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000001];

int N, MAX=0, M;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int low = 0, mid, high = 0, ret = 0;
	long long sum;

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		if (high < arr[i])
			high = arr[i];
	}

	while (low <= high) {
		mid = (high + low) / 2;
		sum = 0;
		for (int i = 0;i < N;i++)
			if (arr[i] - mid > 0)
				sum += arr[i] - mid;
		if (sum >= M) {
			if (ret < mid)
				ret = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << ret;
}