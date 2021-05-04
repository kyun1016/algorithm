#include<iostream>

using namespace std;

int a, b;

int main() {
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			exit(0);
		if (a < b) {
			if (b % a == 0)
				cout << "factor" << endl;
			else
				cout << "neither" << endl;
		}
		else {
			if (a % b == 0)
				cout << "multiple" << endl;
			else
				cout << "neither" << endl;
		}
	}

	return 0;
}