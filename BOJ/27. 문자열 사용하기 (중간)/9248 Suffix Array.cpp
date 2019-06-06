//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<cstring>		//stacmp()�� ����ϱ� ���ؼ�
//
//using namespace std;
//
////�ڵ� 20.8 ���̻� �迭�� ����ϴ� �ܼ��� �˰���
//
////�� ���̻��� ���� ��ġ i,j�� �־��� �� �� ���̻� �� ��� ���� �տ� �;� ���� ���Ѵ�.
//struct SuffixComparator {
//	const string & s;
//	SuffixComparator(const string& s) : s(s) {}
//	bool operator () (int i, int j) {
//		//s.substr() ��ſ� strcmp()�� ���� �ӽ� ��ü�� ����� ����� ����ȴ�.
//		//strcmp(���۹��� ��ġ, ����) = [���۹���, ���۹��� + count) �� ��ȯ�ȴ�.
//		//s.c_str()�� ó�� ���� ��ġ�� �����ͷ� ��Ÿ����.
//		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
//	}
//};
//
////s�� ���̻� �迭�� ����Ѵ�.
//vector<int> getSuffixArrayNaive(const string& s) {
//	//���̻� ���� ��ġ�� ���� �迭�� �����.
//	vector<int> perm;
//	for (int i = 0; i < s.size(); i++)
//		perm.push_back(i);
//	//���̻縦 ���ϴ� ���ڸ� �̿��� �����ϸ� �ϼ�!
//	sort(perm.begin(), perm.end(), SuffixComparator(s));
//	return perm;
//}
//
//vector<int> KMP(const string &s) {
//	int N = s.size();
//	vector<int> pi(N, 0);
//	int begin = 1, matched = 0;
//	while (begin + matched < N) {
//		if (s[begin + matched] == s[matched]) {
//			matched++;
//			pi[begin + matched - 1] = matched;
//		}
//		else {
//			if (matched == 0)
//				begin++;
//			else {
//				begin += pi[matched - 1];
//				matched = pi[matched];
//			}
//		}
//	}
//	return pi;
//}
//
//int preKMP(const string &s, int start) {
//	int N = s.size();
//	int ret = 0;
//	vector<int> pi(N, 0);
//	int begin = 1 + start, matched = 0;
//	while (begin + matched < N) {
//		if (s[begin + matched] == s[matched + start]) {
//			matched++;
//			pi[begin + matched - 1] = matched;
//			if (matched > ret) ret = matched;
//		}
//		else {
//			if (matched == 0)
//				begin++;
//			else {
//				begin += matched + pi[matched - 1];
//				matched = pi[matched];
//			}
//		}
//	}
//	return ret;
//}
//
//
//
//
//void suffixArray(const string &S) {
//	int N = S.length();
//	vector<int> pi(N, 0);
//}
//
//void LCPArray(const string &S) {
//	int N = S.length();
//}
//
//int main() {
//	string S;
//	cin >> S;
//
//	vector<int> ret = getSuffixArrayNaive(S);
//	for (int i = 0; i < ret.size(); i++) {
//		cout << ret[i] + 1 << " ";
//	}
//	cout << "\nx ";
//	for (int i = 1; i < ret.size(); i++) {
//		cout << preKMP(S, ret[i]) << " ";
//	}
//
//	return 0;
//}


#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

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

////�ڵ� 20.11 ���̻� �迭�� ����� ���� ���ڿ� ������ �ذ��ϴ� �˰����� ����

//���������� ���� �տ� ���� s�� ȸ�� ����� ���Ѵ�.
string minShift(const string & s) {
	string s2 = s + s;
	vector<int> a = getSuffixArray(s2);
	for (int i = 0; i < a.size(); i++)
		if (a[i] <= s.size())
			return s2.substr(a[i], s.size());
	//����� �� ���� ����� �Ѵ�.
	return "__oops__";
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

//s�� ���� �ٸ� �κ� ���ڿ��� ���� ����.
int countSubstrings(const string & s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	int n = s.size();
	for (int i = 0; i < a.size(); i++) {
		int cp = 0;
		if (i > 0) cp = commonPrefix(s, a[i - 1], a[i]);
		//a[i]�� (n-a[i])���� ���λ�� �߿��� cp���� �ߺ��̴�.
		ret += n - a[i] - cp;
	}
	return ret;
}



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	vector<int> sol = getSuffixArray(input);

	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] + 1 << " ";
	}
	cout << "\nx ";
	for (int i = 1; i < sol.size(); i++) {
		int count = 0;
		//��... �ð��ʰ��� ���µ�, n^2�� �����̶� �׷� �� �ϴ�.
		//������ �̹� ���� �����͸� Ȱ�� �� ������ �غ���.
		//pi[]�� Ȱ���ϸ� �� �� �ѵ�.
		//������� Ȱ���ؾ� �Ϸ���.
		//pi[i]�� ũ�⸸ŭ �ڿ� ���θ� �����ϸ� �����ϳ�?
		//������ �� �غ���.
		while ((sol[i - 1] + count) < sol.size() && (sol[i] + count) < sol.size()) {
			if (input[sol[i - 1] + count] == input[sol[i] + count])
				count++;
			else
				break;
		}
		cout << count << " ";
		
	}


	return 0;
}