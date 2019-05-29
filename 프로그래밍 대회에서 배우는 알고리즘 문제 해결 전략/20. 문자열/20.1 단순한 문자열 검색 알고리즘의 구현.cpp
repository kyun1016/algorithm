//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
////'짚더미 H의 부분 문자열로 '바늘' N이 출현하는 시작 위치들을 모두 반환한다.
//vector<int> naiveSearch(const string& H, const string& N) {
//	vector<int> ret;
//	//모든 시작 위치를 다 시도해 본다.
//	for (int begin = 0; begin + N.size() <= H.size(); begin++) {
//		bool matched = true;
//		for(int i=0;i<N.size();i++)
//			if (H[begin + 1] != N[i]) {
//				matched = false;
//				break;
//			}
//		if (matched) ret.push_back(begin);
//	}
//	return ret;
//}
//
//
//////코드 20.3 단순한 문자열 알고리즘을 이용해 부분 일치 테이블 계산하기
////N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
////pi[]를 계산한다.
////pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
//vector<int> getPartialMatchNaive(const string& N) {
//	int m = N.size();
//	vector<int> pi(m, 0);
//	//단순한 문자열 검색 알고리즘을 구현한다.
//	for (int begin = 1; begin < m; begin++) {
//		for (int i = 0; i + begin < m; i++) {
//			if (N[begin + i] != N[i])
//				break;
//			//i+1 글자가 서로 대응되었다.
//			pi[begin + i] = max(pi[begin + i], i + 1);
//		}
//	}
//	return pi;
//}
//
//vector<int> getPartialMatch(const string& N) {
//	int m = N.size();
//	vector<int> pi(m, 0);
//	//KMP로 자기 자신을 찾는다.
//	//N을 N에서 찾는다. begin=0이면 자기 자신을 찾아버리니까 안됨!
//	int begin = 1, matched = 0;
//	//비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
//	while (begin + matched < m) {
//		if (N[begin + matched] == N[matched]) {
//			matched++;
//			pi[begin + matched - 1] = matched;
//		}
//		else {
//			if (matched == 0)
//				begin++;
//			else {
//				begin += matched - pi[matched - 1];
//				matched = pi[matched - 1];
//			}
//		}
//	}
//	return pi;
//}
//
//
//////코드 20.2 커누스-모리스-프렛(Knuth-Morris-Pratt) 문자열 검색 알고리즘의 구현
//
////'짚더미'H의 부분 문자열로 '바늘' N이 출현하는 시작 위치들을 모두반환한다.
//vector<int> kmpSearch(const string& H, const string& N) {
//	int n = H.size(), m = N.size();
//	vector<int> ret;
//	//pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
//	vector<int> pi = getPartialMatch(N);
//
//	//begin=matched=0에서부터 시작하자.
//	int begin = 0, matched = 0;
//	while (begin <= n - m) {
//		//만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
//		if (matched < m && H[begin + matched] == N[matched]) {
//			++matched;
//			//결과적으로 m글자가 모두 일치했다면 답에 추가한다.
//			if (matched == m) ret.push_back(begin);
//		}
//		else {
//			//예외: matched가 0인 경우에는 다음 칸에서부터 계속
//			if (matched == 0)
//				begin++;
//			else {
//				begin += matched - pi[matched - 1];
//				//begin을 옮겼다고 처음부터 다시 비교할 필요가 없다.
//				//옮긴 ㅎ에도 pi[matched-1]만큼은 항상 일치하기 때문이다.
//				matched = pi[matched - 1];
//			}
//		}
//	}
//
//	return ret;
//
//}
//
//
//
//////코드 20.7 KMP 알고리즘의 다른 구현
//
//vector<int> kmpSearch2(const string& H, const string& N) {
//	int n = H.size(), m = N.size();
//	vector<int> ret;
//	vector<int> pi = getPartialMatch(N);
//	//현재 대응된 글자의 수
//	int matched = 0;
//	//짚더미의 각 글자를 순회한다.
//	for (int i = 0; i < n; i++) {
//		//matched번 글자와 짚더미의 해당 글자가 불일치할 경우,
//		//현재 대응된 글자의 수를 pi[matched-1]로 줄인다.
//		while (matched > 0 && H[i] != N[matched])
//			matched = pi[matched - 1];
//		//글자가 대응될 경우
//		if (H[i] == N[matched - 1]) {
//			matched++;
//			if (matched == m) {
//				ret.push_back(i - m + 1);
//				matched = pi[matched - 1];
//			}
//		}
//	}
//	return ret;
//}
//
//
