#include<iostream>
#include<string>
#include<vector>

using namespace std;

string T, P;

vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP�� �ڱ� �ڽ��� ã�´�.
	//N�� N���� ã�´�. begin=0�̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵ�!
	int begin = 1, matched = 0;
	//���� ���ڰ� N�� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ����Ѵ�.
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
	//���� ������ ������ ��
	int matched = 0;
	//¤������ �� ���ڸ� ��ȸ�Ѵ�.
	for (int i = 0; i < n; i++) {
		//matched�� ���ڿ� ¤������ �ش� ���ڰ� ����ġ�� ���,
		//���� ������ ������ ���� pi[matched-1]�� ���δ�.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		//���ڰ� ������ ���
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

