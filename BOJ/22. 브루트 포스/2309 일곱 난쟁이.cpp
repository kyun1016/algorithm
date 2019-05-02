#include<iostream>
#include<algorithm>

using namespace std;

int height[9];

void findNangangi() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += height[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						cout << height[k] << endl;
				}
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}

	sort(height, height + 9);

	findNangangi();

	return 0;
}