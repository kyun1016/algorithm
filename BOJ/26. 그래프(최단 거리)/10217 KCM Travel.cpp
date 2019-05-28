#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//triple에 대한 출처
//https://hugman.tistory.com/entry/C-stdtriple
//http://www.bioinf.uni-leipzig.de/Software/bbq/doc/structstd_1_1triple.html
#ifndef __GLIBCPP_INTERNAL_TRIPLE_H
#define __GLIBCPP_INTERNAL_TRIPLE_H

namespace std
{

	template <class _T1, class _T2, class _T3>
	struct triple {
		typedef _T1 first_type;
		typedef _T2 second_type;
		typedef _T3 third_type;

		_T1 first;
		_T2 second;
		_T3 third;
#ifdef _GLIBCPP_RESOLVE_LIB_DEFECTS
		//265.  std::triple::triple() effects overly restrictive
		triple() : first(), second(), third() {}
#else
		triple() : first(_T1()), second(_T2()), third(_T3()) {}
#endif

		triple(const _T1& __a, const _T2& __b, const _T3& __c) : first(__a), second(__b), third(__c) {}

		template <class _U1, class _U2, class _U3>
		triple(const triple<_U1, _U2, _U3>& __p) : first(__p.first), second(__p.second), third(__p.third) {}
	};

	template <class _T1, class _T2, class _T3>
	inline bool operator==(const triple<_T1, _T2, _T3>& __x, const triple<_T1, _T2, _T3>& __y)
	{
		return __x.first == __y.first && __x.second == __y.second && __x.third == __y.third;
	}

	template <class _T1, class _T2, class _T3>
	inline bool operator<(const triple<_T1, _T2, _T3>& __x, const triple<_T1, _T2, _T3>& __y)
	{
		return __x.first < __y.first ||
			(!(__y.first < __x.first) && __x.second < __y.second) ||
			((!(__y.first < __x.first) && !(__y.second < __x.second) && __x.third < __y.third));
	}

	template <class _T1, class _T2, class _T3>
	inline bool operator!=(const triple<_T1, _T2, _T3>& __x, const triple<_T1, _T2, _T3>& __y) {
		return !(__x == __y);
	}

	template <class _T1, class _T2, class _T3>
	inline bool operator>(const triple<_T1, _T2, _T3>& __x, const triple<_T1, _T2, _T3>& __y) {
		return __y < __x;
	}

	template <class _T1, class _T2, class _T3>
	inline bool operator<=(const triple<_T1, _T2, _T3>& __x, const triple<_T1, _T2, _T3>& __y) {
		return !(__y < __x);
	}

	template <class _T1, class _T2, class _T3>
	inline bool operator>=(const triple<_T1, _T2, _T3>& __x, const triple<_T1, _T2, _T3>& __y) {
		return !(__x < __y);
	}

	template <class _T1, class _T2, class _T3>
#ifdef _GLIBCPP_RESOLVE_LIB_DEFECTS
	//181.  make_triple() unintended behavior
	inline triple<_T1, _T2, _T3> make_triple(_T1 __x, _T2 __y, _T3 __z)
#else
	inline triple<_T1, _T2, _T3> make_triple(const _T1& __x, const _T2& __y, const _T3& __z)
#endif
	{
		return triple<_T1, _T2, _T3>(__x, __y, __z);
	}

} // namespace std

#endif /* __GLIBCPP_INTERNAL_TRIPLE_H */

const int INF = 1000000007;
const int MAX_N = 101;


//first는 다음 공항, second.first는 cost, second.second는 소요 시간이다.
vector<pair<int, pair<int, int> > > adj[MAX_N];

//벨만-포드 알고리즘을 활용한 탐색
void bellmanFord(int N) {
	//앞은 소요시간을 저장하고, 뒤는 비용을 저장한다.
	vector<pair<int, int> > upper(N + 1, { INF, 0 });
	//1에서 시작하므로 1은 0으로 한다.
	upper[1] = { 0,0 };
	
	bool updated = false;

	for (int iter = 0; iter < N; iter++) {
		updated = false;
		for (int here = 1; here <= N; here++) {
			int thisCost = 0;
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second.first;
				int timeCost = adj[here][i].second.second;
				if (upper[there].first > upper[here].first + timeCost) {
					thisCost = cost;
					upper[there].first = upper[here].first + timeCost;
				}
			}
		}
		
	}


}





//다익스트라 알고리즘을 활용한 탐색
void dijkstra(int N) {


	priority_queue<pair<int, int> > pq;
	pq.push(adj[1]);
}

int main() {
	int T, N, M, K;
	int start, end, cost, timeDelay;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		adj->clear();
		for (int i = 0; i < K; i++) {
			cin >> start >> end >> cost >> timeDelay;
			adj[start].push_back({ end, {cost, timeDelay} });
		}
	}


	return 0;
}