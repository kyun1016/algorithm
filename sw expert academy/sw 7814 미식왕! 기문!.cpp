//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
////first = 타이틀 점수, second.first = 필요 이해력, second.second = 필요 소화력
//vector<pair<int, pair<int, int> > > restaurant;
//pair<int, int> ablity;
//int Count;
//int Score;
//
//int countScore(const int& N) {
//	int ret = Count;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int T, N;
//	int a, b, c;
//	cin >> T;
//	//벡터 초기화
//	while (!restaurant.empty())
//		restaurant.pop_back();
//	Count = 0;
//	Score = 0;
//	for (int i = 1; i <= T; i++) {
//		cin >> N;
//		for (int j = 0; j < N; j++) {
//			cin >> a >> b >> c;
//			if (a == 1 || b == 1) {
//				Count++;
//				Score += c;
//			}
//			else
//				restaurant.push_back({ c, {a,b} });
//		}
//		
//		cout << "#" << i << " " << countScore(N) << "\n";
//	}
//	return 0;
//}