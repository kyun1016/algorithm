#include<iostream>
#include<algorithm>

typedef unsigned long long ull;

using namespace std;

ull Arr[10001];

ull binarySearch(const int & K, const int & N) {
	ull first = 1;
	ull last = 0;
	ull ret = 0;
	for (int i = 0; i < K; i++) {
		last += Arr[i];
	}
	last /= N;
	
	ull mid = 1;
	while (first <= last) {
		mid = (first + last) / 2;
		ull temp = 0;
		for (int i = 0; i < K; i++) {
			temp += Arr[i] / mid;
		}
		//cout << mid << endl;
		if (temp >= N) {
			ret = max(ret, mid);
			first = mid + 1;
		}
		else 
			last = mid - 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> Arr[i];
	}

	sort(Arr, Arr + K);
	cout << binarySearch(K, N);
}