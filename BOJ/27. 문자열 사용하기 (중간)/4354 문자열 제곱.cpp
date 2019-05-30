#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
using namespace std;
string S;



void KMP() {
	int m = S.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0, a=1;
	while (begin + matched < m) {
		if (S[begin + matched] == S[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
				a++;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched];
			}
		}
		if (matched == 1)
			a = begin + matched - 1;
	}
	
	//for (int i = 0; i < m; i++) {
	//	cout << pi[i] << " ";
	//}
	//cout << endl;

	/*cout << a << endl;*/

	if (m % a == 0) {
		cout << m / a << endl;
	}
	else {
		cout << 1 << endl;
	}


}

int main(void) {
	cin >> S;
	while (S != ".") {
		KMP();
		cin >> S;
	}
}