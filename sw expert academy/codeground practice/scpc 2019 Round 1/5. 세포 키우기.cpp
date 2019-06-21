#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

//const long long INF_LEFT = -1000000000007;
//const long long INF_Right = 1000000000007;
//
////first = x좌표, second = y좌표
//vector<pair<ll, ll> > V;
//
////idx[0] = 좌측 x가 가장 가까운 i값, idx[1] = 우측 x가 가장 가까운 i값, idx[2] = 좌측 y가 가장 가까운 i값, idx[3] = 우측 y가 가장 가까운
//int Idx[3];
//int Answer;
//
//bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
//	if (a.first == b.first)
//		return a.second < b.second;
//
//	return a.first < b.first;
//}
//
//ll findAdjLeft(const ll& here) {
//	int& ret = Idx[0];
//	ll size = INF_Right;
//	for (int i = 0; i < V.size(); i++) {
//		if (V[i].first > here)
//			break;
//		else {
//			ll y = V[i].second;
//			ll x = here - V[i].first;
//			y = max(y, x);
//			if (size >= y) {
//				size = y;
//				ret = i;
//			}
//		}
//	}
//	return size;
//}
//
////사이즈 구간에서 가장 작은 h를 찾자.
//ll findAdjHeight(const ll& here) {
//	int& ret = Idx[1];
//	ll size = INF_Right;
//	for (int i = Idx[0]; i <= Idx[2]; i++) {
//		ll y = V[i].second;
//		ll x = abs(here - V[i].first);
//		y = max(y, x);
//		if (size >= y) {
//			size = y;
//			ret = i;
//		}
//	}
//
//	return size;
//}
//
//ll findAdjRight(const ll& here) {
//	int& ret = Idx[2];
//	ll size = INF_Right;
//	for (int i = V.size() - 1; i >= 0; i--) {
//		if (V[i].first < here)
//			break;
//		else {
//			ll y = V[i].second;
//			ll x = V[i].first - here;
//			y = max(y, x);
//			if (size >= y) {
//				size = y;
//				ret = i;
//			}
//		}
//	}
//	return size;
//}
//
////슬라이딩 윈도우 기법을 활용해서 쓸모없는 계산을 줄여보자.
//void checkMaxSquare(const long long left, const long long right, const int N) {
//
//	ll MaxLength = 0;
//	for (long long i = left; i <= right; i++) {
//		for (int j = 0; j < V.size(); j++) {
//			if(V[j].second > abs(i - V[j].first))
//				MaxLength = max(MaxLength, V[j].second);
//			else
//				MaxLength = max(MaxLength, abs(i - V[j].first));
//		}
//	}
//	Answer =  MaxLength * 2;
//}
//
//
//
////한 점에서 가장 가까운 점을 탐색하는 알고리즘
//void findAdj(ll here) {
//	ll ret = INF_Right;
//	int idx = 0;
//	for (int i = 0; i < V.size(); i++) {
//		ll y = V[i].second;
//		ll x = abs(V[i].first - here);
//		y = max(y, x);
//		if (ret > y) {
//			ret = y;
//			idx = i;
//		}
//			
//	}
//	cout << idx <<" " <<V[idx].first << " " << V[idx].second << endl;
//	cout << "ret : " << ret << endl;
//}

//생각해보니까 x축을 기준으로 비교를 하는 것 자체가 불가능한 x소리이다.
//비교를 해야되는 기준점은 각 점들을 비교해주자.
//h는 x축을 밑변으로 가지는 직사각형을 생성 할 것인데, 이 중 변이 가장 긴 것을 찾아보자.
//추가적으로 y축은 2배를 해서 평가하자.
void cmpDot() {

}



int main(int argc, char** argv)
{
	int T, test_case, N;
	ll r, l, x, y;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> l >> r >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			V.push_back({ x,abs(y) });
		}
		sort(V.begin(), V.end(), cmp);

		
		Answer = 0;
		
		ll printThis = 0;
		for (int i = l; i <= r; i++) {
			ll ret = INF_Right;
			ret = min(ret, findAdjLeft(i));
			ret= min(ret, findAdjRight(i));
			ret= min(ret, findAdjHeight(i));

			printThis = max(printThis, ret);
			findAdj(i);
		}
		/*checkMaxSquare(l, r, N);*/
		
		cout << "Case #" << test_case + 1 << endl;
		cout << printThis*2 << endl;
		V.clear();
	}

	return 0;//Your program should return 0 on normal termination.
}