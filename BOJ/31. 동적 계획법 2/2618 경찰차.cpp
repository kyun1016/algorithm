//
////brute force를 활용한 풀이
////#include<iostream>
////#include<queue>
////#include<vector>
////
////using namespace std;
////
////int N, W;
////const int INF = 1000000007;
////vector<pair<int, int>> qu;
////
////int dp(pair<int, int> car1 = { 1,1 }, pair<int, int> car2 = { 6,6 }, int count = 0) {
////	if (count == W)
////		return 0;
////	int ret = INF;
////	ret = min(ret, (abs(car1.first - qu[count].first) + abs(car1.second - qu[count].second) + dp(qu[count], car2, count + 1)));
////	ret = min(ret, (abs(car2.first - qu[count].first) + abs(car2.second - qu[count].second) + dp(car1, qu[count], count + 1)));
////
////	return ret;
////}
////
////int main() {
////	ios_base::sync_with_stdio(0);
////	cin.tie(0);
////
////	cin >> N >> W;
////	int x,y;
////	for (int i = 0; i < W; i++) {
////		cin >> x >> y;
////		qu.push_back({ x,y });
////	}
////	
////	cout << dp() << endl;
////
////
////	return 0;
////}
//
//
////brute force를 활용한 풀이
//#include<iostream>
//#include<queue>
//#include<vector>
//
//using namespace std;
//
//int N, W;
//const int INF = 100000007;
//vector<pair<int, int>> qu;
//queue<int> order;
//int cache[1001][1001];
//
//int dp(int order1 = 0, int order2 = 0) {
//	int here = max(order1, order2);
//	int next = here + 1;
//	if (next == qu.size())
//		return 0;
//
//	int& ret = cache[order1][order2];
//	if (ret != -1)
//		return ret;
//	
//	
//	ret = INF;
//
//
//	pair<int, int> car1;
//	pair<int, int> car2;
//	if (order1 == 0) {
//		car1 = { 1,1 };
//	}
//	else {
//		car1 = qu[order1];
//	}
//	if (order2 == 0) {
//		car2 = { N,N };
//	}
//	else {
//		car2 = qu[order2];
//	}
//
//	ret = min(ret, (abs(car1.first - qu[next].first) + abs(car1.second - qu[next].second) + dp(next, order2)));
//	ret = min(ret, (abs(car2.first - qu[next].first) + abs(car2.second - qu[next].second) + dp(order1, next)));
//
//	return ret;
//}
//
//void findOrder(int order1 = 0, int order2 = 0) {
//	int here = max(order1, order2);
//	int next = here + 1;
//	if (next == qu.size())
//		return;
//
//	pair<int, int> car1;
//	pair<int, int> car2;
//	if (order1 == 0) {
//		car1 = { 1,1 };
//	}
//	else {
//		car1 = qu[order1];
//	}
//	if (order2 == 0) {
//		car2 = { N,N };
//	}
//	else {
//		car2 = qu[order2];
//	}
//	int a = (abs(car1.first - qu[next].first) + abs(car1.second - qu[next].second) + dp(next, order2));
//	int b = (abs(car2.first - qu[next].first) + abs(car2.second - qu[next].second) + dp(order1, next));
//	if (a < b) {
//		order.push(1);
//		findOrder(next, order2);
//	}
//	else {
//		order.push(2);
//		findOrder(order1, next);
//	}
//
//}
//
//
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> W;
//	int x,y;
//	qu.push_back({ 0,0 });
//	for (int i = 0; i < W; i++) {
//		cin >> x >> y;
//		qu.push_back({ x,y });
//	}
//
//	//초기화를 해주자.
//	for (int i = 0; i < W; i++) {
//		for (int j = 0; j < W; j++) {
//			cache[i][j] = -1;
//		}
//	}
//	
//	cout << dp() << endl;
//	findOrder();
//
//	while (!order.empty()) {
//		cout << order.front() << endl;
//		order.pop();
//	}
//
//	//for (int i = 0; i < N; i++) {
//	//	for (int j = 0; j < N; j++) {
//	//		if(cache[i][j] != -1)
//	//			cout << "i : " << i <<" j : " << j << " "  << cache[i][j] << endl;
//	//	}
//	//}
//
//
//	return 0;
//}