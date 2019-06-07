#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int pos[500001];

//�� ���̻���� ù t���ڸ� �������� �� �׷� ��ȣ�� �־��� ��,
//�־��� �� ���̻縦 ù 2*t���ڸ� �������� ���Ѵ�.
//group[]�� ���̰� 0�� ���̻絵 �����Ѵ�.
struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {
	}
	bool operator() (int a, int b) {
		//ù t���ڰ� �ٸ��� �̵��� �̿��� ���Ѵ�.
		if (group[a] != group[b]) return group[a] < group[b];
		//�ƴ϶�� S[a+t..]�� S[b+t..]�� ù t���ڸ� ���Ѵ�.
		return group[a + t] < group[b + t];

	}
};


////�ڵ� 20.10 ���̻� �迭�� ����ϴ� �ǹ��� ���̾�� �˰���

//s�� ���̻� �迭�� ����Ѵ�.
vector<int> getSuffixArray(const string& s) {


	int n = s.size();
	//group[i]=���̻���� ù t���ڸ� �������� ������ ��,
	//			s[i..]�� ���� �׷� ��ȣ.
	//t=1�� ���� ������ �� ���� S[i..]�� ù ���ڷ� �׷� ��ȣ��
	//���� �൵ ���� ȿ���� �ִ�.
	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1;
	//��������� ���̻� �迭�� �� ��ȯ ��. �� �迭�� lg(n)�� �����Ѵ�.
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	while (t < n) {
		//group[]�� ù t���ڸ� �������� ����� �״�.
		//ù 2t���ڸ� �������� perm�� �ٽ� �����Ѵ�.
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		//2t���ڰ� n�� �Ѵ´ٸ� ���� ���̻� �迭 �ϼ�!
		t *= 2;
		if (t >= n)
			break;
		//2t���ڸ� �������� �� �׷� ������ �����.
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; i++)
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		group = newGroup;
	}
	return perm;
}



////�ڵ� 20.12 ���̻� �迭�� �̿��� �ٸ� �κ� ���ڿ��� ���� ���� �˰���

//s[i..]�� s[j..]�� ���� ���λ��� �ִ� ���̸� ����Ѵ�.
int commonPrefix(const string & s, int i, int j) {
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]) {
		i++; j++; k++;
	}
	return k;
}


//����� �ݺ��� ���̱� ���� ������ �غ���.
//���λ��� ���̸� ���� �� �Ź� �ڱ� �Ʒ��� ���� �񱳸� �ϴ� ����� �����Ѵ�.
//������, �ʿ� ���� �ݺ��� ��ӵȴٴ� ������ ���.
//�̰��� KMP���� pi�迭�� ����ϰ� ����� ���� �� �ִ� ����� ���� �� �� ����.
//��������� 
vector<int> LCPArray(const string& S, const vector<int>& suffixArray) {
	int N = S.size();
	vector<int> ret(N, 0);
	//���̰� �� ������� �񱳸� �� ���̴�.
	//�̸� ���� ������� �ڽ��� ��ġ�� ǥ�����ִ�
	//pos[]�迭�� ������־���.
	for (int i = 0; i < N; i++)
		pos[suffixArray[i]] = i;

	for (int i = 0, k=0; i < N; i++, k=max(k-1, 0)) {
		//suffixArray�� �������� �񱳰� �Ұ����ϴ�.
		if (pos[i] == N - 1) continue;

		//�ٷ� �Ʒ��� ���̻�� ���ؼ� �� ���� ���ڰ� ��ġ�ϴ��� ���Ѵ�.
		for (int j = suffixArray[pos[i] + 1]; S[i + k] == S[j + k]; k++);
		ret[pos[i]] = k;
	}
	return ret;
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string temp;
	cin >> temp;
	vector<int> suffix = getSuffixArray(temp);
	vector<int> LCP = LCPArray(temp, suffix);
	int N = temp.size();
	for (int i = 0; i < N; i++) {
		cout << suffix[i]+1 << " ";
	}
	cout << "\nx ";
	for (int i = 0; i < N-1; i++) {
		cout << LCP[i] << " ";
	}


	return 0;
}







