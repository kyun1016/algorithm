#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

float arr[20003];

float calc(const int& N, const int& K) {
	float sum = 0;

	for (int i = 0; i < N; i++) {
		sum += (arr[i] / N);
	}

	for (int j = 0; j < K; j++) {
		float MAX = 0;
		bool find = false;
		for (int i = 0; i < N; i++) {
			if(!find)
				if (sum <= arr[i]) {
					MAX += (sum * i)/N;
					find = true;
				}
			if (find)
				MAX += arr[i] / N;
		}
		sum = MAX;
	}



	return sum;
}


int main() {
	int T;
	int N, K;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		cout << "Case #" << i << ": ";
		printf("%.6f\n", calc(N, K));
	}
}
