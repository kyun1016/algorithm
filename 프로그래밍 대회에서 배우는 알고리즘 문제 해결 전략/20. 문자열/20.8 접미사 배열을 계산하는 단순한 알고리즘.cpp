//#include<vector>
//#include<string>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//
////�� ���̻��� ���� ��ġ i,j�� �־��� �� �� ���̻� �� ��� ���� �տ� �;� ���� ���Ѵ�.
//struct SuffixComparator {
//	const string& s;
//	SuffixComparator(const string& s) : s(s) {}
//	bool operator()(int i, int j){
//		//s.substr() ��ſ� strcmp()�� ���� �ӽ� ��ü�� ����� ����� ����ȴ�.
//		return strcmp(s.c_str + i, s.c_str + j) < 0;
//	}
//};
////s�� ���̻� �迭�� ����Ѵ�.
//vector<int> getSuffixArrayNaive(const string& s) {
//	//���̻� ���� ��ġ�� ���� �迭�� �����.
//	vector<int> perm;
//	for (int i = 0; i < s.size(); i++) perm.push_back(i);
//	//���̻縦 ���ϴ� ���ڸ� �̿��� �����ϸ� �ϼ�!
//	sort(perm.begin(), perm.end(), SuffixComparator(s));
//	return perm;
//
//}