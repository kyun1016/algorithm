#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[10050];
int cache[10050];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cache[0] = arr[0];
	cache[1] = arr[0] + arr[1];
	int ret = 0;
	for (int i = 2; i < N; i++) {
		cache[i] = max(cache[i - 2] + arr[i], cache[i - 3] + arr[i - 1] + arr[i]);
		cache[i] = max(cache[i - 1], cache[i]);
	}

	cout << max(cache[N-1], cache[N-2]) << endl;
}