#include<iostream>
#include<string>
#include<vector>

using namespace std;

string T, P;

vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP로 자기 자신을 찾는다.
	//N을 N에서 찾는다. begin=0이면 자기 자신을 찾아버리니까 안됨!
	int begin = 1, matched = 0;
	//비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch2(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	//현재 대응된 글자의 수
	int matched = 0;
	//짚더미의 각 글자를 순회한다.
	for (int i = 0; i < n; i++) {
		//matched번 글자와 짚더미의 해당 글자가 불일치할 경우,
		//현재 대응된 글자의 수를 pi[matched-1]로 줄인다.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		//글자가 대응될 경우
		if (H[i] == N[matched]) {
			matched++;
			if (matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}



int main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0);*/

	getline(cin, T);
	getline(cin, P);

	/*cout << T << endl;
	cout << P << endl;*/
	
	vector<int> ret;
	ret = kmpSearch2(T, P);

	cout << ret.size() << "\n";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] + 1 << "\n";
	}

	return 0;
}

