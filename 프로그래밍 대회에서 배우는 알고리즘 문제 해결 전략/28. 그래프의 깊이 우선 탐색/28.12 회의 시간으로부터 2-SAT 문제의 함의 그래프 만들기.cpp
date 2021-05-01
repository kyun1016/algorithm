//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////그래프의 인접 리스트 표현
//vector<vector<int> > adj;
////두구간 a와 b가 서로 겹치지 않는지를 확인한다.
//bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
//	return a.second <= b.first || b.second <= a.first;
//}
////meetings[]가 각 팀이 ㅏ고 싶어하는 회의 사간의 목록일 때, 이를
////2-SAT 문제로 변환한 뒤 함의 그래프를 생성한다.
////i번 팀은 meetings[2*i] 혹은 meetings[2*i+1] 중 하나 시간에 회의실을 써야 한다.
//void makeGraph(const vector<pair<int, int> >& meetings) {
//	int vars = meetings.size();
//	//그래프는 각 변수마다 두 개의 정점을 갖는다.
//	adj.clear(); adj.resize(vars * 2);
//	for (int i = 0; i < vars; i += 2) {
//		//각 팀은 i번 회의나 j번 회의 둘 중 하나는 해야한다/
//		//(i or j) 절을 추가한다.
//		int j = i + 1;
//		adj[i * 2 + 1].push_back(j * 2); //~i =>j
//		adj[j * 2 + 1].push_back(i * 2); //~i =>j
//	}
//}