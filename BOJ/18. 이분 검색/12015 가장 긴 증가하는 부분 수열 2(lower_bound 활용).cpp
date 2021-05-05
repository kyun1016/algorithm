#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000001], LIS[1000001], LIS_length;

//O(N^2)으로 해결


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int* pos = lower_bound(arr, arr + LIS_length, arr[i]);
		*pos = arr[i];
		if (pos - arr == LIS_length)
			LIS_length++;
	}

	cout << LIS_length << endl;

	return 0;
}