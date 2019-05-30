//#include<vector>
//#include<string>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//
////두 접미사의 시작 위치 i,j가 주어질 때 두 접미사 중 어느 쪽이 앞에 와야 할지 비교한다.
//struct SuffixComparator {
//	const string& s;
//	SuffixComparator(const string& s) : s(s) {}
//	bool operator()(int i, int j){
//		//s.substr() 대신에 strcmp()를 쓰면 임시 객체를 만드는 비용이 절약된다.
//		return strcmp(s.c_str + i, s.c_str + j) < 0;
//	}
//};
////s의 접미사 배열을 계산한다.
//vector<int> getSuffixArrayNaive(const string& s) {
//	//접미사 시작 위치를 담은 배열을 만든다.
//	vector<int> perm;
//	for (int i = 0; i < s.size(); i++) perm.push_back(i);
//	//접미사를 비교하는 비교자를 이용해 정렬하면 완성!
//	sort(perm.begin(), perm.end(), SuffixComparator(s));
//	return perm;
//
//}