#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool check_palindrome(const string& N) {
	int size = N.size();
	for (int i = 0; i < size / 2; i++) {
		if (N[i] != N[size - i - 1])
			return false;
	}

	return true;
}

int check_not_palindrome(const string& N) {
	int size = N.size();
	for (int i = 0; i < size / 2; i++) {
		if (N[i] != N[size - i - 1])
			return size;
	}
	
	for (int i = 1; i < size; i++) {
		if (N[0] != N[i]) {
			return size - 1;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string N;

	cin >> N;

	/*if (check_palindrome(N))
		cout << "is Palindrome" << endl;
	else
		cout << "is not Palindrome" << endl;*/

	cout << check_not_palindrome(N);

	return 0;
}