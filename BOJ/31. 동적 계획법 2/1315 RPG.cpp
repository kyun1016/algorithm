//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N;
//int sol;
//vector<pair<pair<int, int>, int> > quest;
//
//bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
//	return (a.first.first + a.first.second) < (b.first.first + b.first.second);
//}
//
//int cache[1001][1001];
//
//void dp(const int& here_str, const int& here_int) {
//	int& ret = cache[here_str][here_int];
//	if (ret != -1) {
//		return;
//	}
//	ret = 0;
//	int here_pnt = 2;
//	for (int i = 0; i < N; i++) {
//		pair<int, int> next = quest[i].first;
//		int next_pnt = quest[i].second;
//		if (next.first <= here_str || next.second <= here_int) {
//			here_pnt += next_pnt;
//			ret++;
//		}
//	}
//
//	if (sol < ret)
//		sol = ret;
//
//	here_pnt -= here_str;
//	here_pnt -= here_int;
//
//	for (int i = here_str; i <= min(1000, (here_str + here_pnt)); i++) {
//		dp(i, min(1000, (here_str - i + here_pnt + here_int)));
//	}
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int a, b, c;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b >> c;
//		quest.push_back({ {a,b},c });
//	}
//	//sort(quest.begin(), quest.end(), cmp);
//
//	//for (int i = 0; i < N; i++) {
//	//	cout << quest[i].first.first << " " << quest[i].first.second << endl;
//	//}
//
//	for (int i = 0; i < 1001; i++) 
//		for(int j=0;j<1001;j++)
//			cache[i][j] = -1;
//	
//
//	dp(1, 1);
//	cout << sol;
//
//	return 0;
//}