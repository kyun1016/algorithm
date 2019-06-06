//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<cstring>		//stacmp()를 사용하기 위해서
//
//using namespace std;
//
////코드 20.8 접미사 배열을 계산하는 단순한 알고리즘
//
////두 접미사의 시작 위치 i,j가 주어질 때 두 접미사 중 어느 쪽이 앞에 와야 할지 비교한다.
//struct SuffixComparator {
//	const string & s;
//	SuffixComparator(const string& s) : s(s) {}
//	bool operator () (int i, int j) {
//		//s.substr() 대신에 strcmp()를 쓰면 임시 객체를 만드는 비용이 절약된다.
//		//strcmp(시작문자 위치, 길이) = [시작문자, 시작문자 + count) 가 반환된다.
//		//s.c_str()은 처음 문자 위치를 포인터로 나타낸다.
//		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
//	}
//};
//
////s의 접미사 배열을 계산한다.
//vector<int> getSuffixArrayNaive(const string& s) {
//	//접미사 시작 위치를 담은 배열을 만든다.
//	vector<int> perm;
//	for (int i = 0; i < s.size(); i++)
//		perm.push_back(i);
//	//접미사를 비교하는 비교자를 이용해 정렬하면 완성!
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

//각 접미사들의 첫 t글자를 기준으로 한 그룹 번호가 주어질 때,
//주어진 두 접미사를 첫 2*t글자를 기준으로 비교한다.
//group[]은 길이가 0인 접미사도 포함한다.
struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {
	}
	bool operator() (int a, int b) {
		//첫 t글자가 다르면 이들을 이용해 비교한다.
		if (group[a] != group[b]) return group[a] < group[b];
		//아니라면 S[a+t..]와 S[b+t..]의 첫 t글자를 비교한다.
		return group[a + t] < group[b + t];

	}
};



////코드 20.10 접미사 배열을 계산하는 맨버와 마이어스의 알고리즘

//s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s) {


	int n = s.size();
	//group[i]=접미사들을 첫 t글자를 기준으로 정했을 때,
	//			s[i..]가 들어가는 그룹 번호.
	//t=1일 때는 정렬할 것 없이 S[i..]의 첫 글자로 그룹 번호를
	//정해 줘도 같은 효과가 있다.
	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1;
	//결과적으로 접미사 배열이 될 반환 값. 이 배열을 lg(n)번 정렬한다.
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	while (t < n) {
		//group[]은 첫 t글자를 기준으로 계산해 뒀다.
		//첫 2t글자를 기준으로 perm을 다시 정렬한다.
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		//2t글자가 n을 넘는다면 이제 접미사 배열 완성!
		t *= 2;
		if (t >= n)
			break;
		//2t글자를 기준으로 한 그룹 정보를 만든다.
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

////코드 20.11 접미사 배열을 사용해 원형 문자열 문제를 해결하는 알고리즘의 구현

//사전순으로 가장 앞에 오는 s의 회전 결과를 구한다.
string minShift(const string & s) {
	string s2 = s + s;
	vector<int> a = getSuffixArray(s2);
	for (int i = 0; i < a.size(); i++)
		if (a[i] <= s.size())
			return s2.substr(a[i], s.size());
	//여기로 올 일은 없어야 한다.
	return "__oops__";
}



////코드 20.12 접미사 배열을 이용해 다른 부분 문자열의 수를 세는 알고리즘

//s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string & s, int i, int j) {
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]) {
		i++; j++; k++;
	}
	return k;
}

//s의 서로 다른 부분 문자열의 수를 센다.
int countSubstrings(const string & s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	int n = s.size();
	for (int i = 0; i < a.size(); i++) {
		int cp = 0;
		if (i > 0) cp = commonPrefix(s, a[i - 1], a[i]);
		//a[i]의 (n-a[i])개의 접두사들 중에서 cp개는 중복이다.
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
		//음... 시간초과가 나는데, n^2의 구현이라 그런 듯 하다.
		//이전에 이미 구한 데이터를 활용 할 구상을 해보자.
		//pi[]를 활용하면 될 듯 한데.
		//어떤식으로 활용해야 하려나.
		//pi[i]의 크기만큼 뒤에 전부를 차감하면 가능하나?
		//생각을 더 해보자.
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