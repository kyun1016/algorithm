#include<iostream>

using namespace std;

int sol[1000001];

void makeDigitGenerator() {
	int sum, k;
	for (int i = 1; i <= 1000000; i++) {
		sum = i;
		k = i;
		while (k) {
			sum += k % 10;
			k /= 10;
		}
		sol[i] = sum;
	}
}

void findDigitGenerator(int N) {
	for (int i = 0; i <= 1000000; i++) {
		if (sol[i] == N) {
			cout << i << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int main() {
	int N;
	cin >> N;
	makeDigitGenerator();
	findDigitGenerator(N);

	return 0;
}
