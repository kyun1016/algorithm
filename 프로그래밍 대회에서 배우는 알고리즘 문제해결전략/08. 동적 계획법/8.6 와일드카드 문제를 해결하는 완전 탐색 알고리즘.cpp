////#include<iostream>
////#include<string>
////
////using namespace std;
////
//////완전 탐색 알고리즘
////bool match(const string& w, const string& s) {
////	//w[pos]와 s[pos]를 맞춰나간다.
////	int pos = 0;
////	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
////		pos++;
////	
////	if (pos == w.size())
////		return pos == s.size();
////
////	if (w[pos] == '*')
////		for (int skip = 0; pos + skip <= s.size(); ++skip)
////			if (match(w.substr(pos + 1), s.substr(pos + skip)))
////				return true;
////
////	return false;
////}
////
//////동적 계획법 알고리즘(시간 복잡도 O(n*n*n)이다)
////int cache[101][101];
////string W, S;
////
////bool matchMemoized(int w, int s) {
////	//메모이제이션
////	int& ret = cache[w][s];
////	if (ret != -1) return ret;
////	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
////		++s;
////		++w;
////	}
////	
////	if (w == W.size())
////		return ret = (s == S.size());
////
////	if (W[w] == '*')
////		for (int skip = 0; s + skip <= S.size(); ++skip)
////			if (match(W.substr(w + 1), S.substr(s + skip)))
////				return ret = 1;
////
////	return ret = 0;
////
////
////}
////
//////시간 복잡도 O(n2)
////bool matchMemoized_jegui(int w, int s) {
////	//메모이제이션
////	int& ret = cache[w][s];
////	if (ret != -1) return ret;
////	if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
////		return ret = matchMemoized_jegui(w + 1, s + 1);
////
////	if (w == W.size())
////		return ret = (s == S.size());
////
////	if (W[w] == '*')
////		if(matchMemoized_jegui(w+1, s) || (s < S.size() && matchMemoized_jegui(w, s+1)))
////			return ret = 1;
////
////	return ret = 0;
////
////
////}