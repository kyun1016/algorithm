#include<iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int E, S, M;
	int max_E = 15, max_S = 28, max_M = 19;
	cin >> E >> S >> M;

	while (1) {
		if ((E == S) && (E == M) && (S == M))
			break;
		else {
			if (E <= S && E <= M)
				E += max_E;
			else if (S <= E && S <= M)
				S += max_S;
			else
				M += max_M;
		}
	}
	cout << E;



	return 0;
}