#include<iostream>
#include<string>
#include<vector>

using namespace std;

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


////�ڵ� 20.2 Ŀ����-�𸮽�-����(Knuth-Morris-Pratt) ���ڿ� �˻� �˰����� ����

//'¤����'H�� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ���� ��ġ���� ��ι�ȯ�Ѵ�.
vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	//pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
	vector<int> pi = getPartialMatch(N);

	//begin=matched=0�������� ��������.
	int begin = 0, matched = 0;
	while (begin <= n - m) {
		//���� ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			//��������� m���ڰ� ��� ��ġ�ߴٸ� �信 �߰��Ѵ�.
			if (matched == m) ret.push_back(begin);
		}
		else {
			//����: matched�� 0�� ��쿡�� ���� ĭ�������� ���
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				//begin�� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����.
				//�ű� ������ pi[matched-1]��ŭ�� �׻� ��ġ�ϱ� �����̴�.
				matched = pi[matched - 1];
			}
		}
	}

	return ret;

}



int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);

	vector<int> ret = kmpSearch(T, P);

	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] + 1 << endl;
	}

	return 0;
}

