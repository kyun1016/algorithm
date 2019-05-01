//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int cost[1001][3];
//
////void min_cost(int N) {
////	for (int i = 1; i <= N; i++) {
////		cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
////		cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
////		cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
////	}
////	 
////}
//
//int main() {
//	int N;
//	cin >> N;
//	int temp[3];
//	for(int i=1;i<=N;i++) {
//		cin >> temp[0] >> temp[1] >> temp[2];
//		cost[i][0] = temp[0] + min(cost[i - 1][1], cost[i - 1][2]);
//		cost[i][1] = temp[1] + min(cost[i - 1][0], cost[i - 1][2]);
//		cost[i][2] = temp[2] + min(cost[i - 1][0], cost[i - 1][1]);
//	}
//	cout << min(min(cost[N][0], cost[N][1]), cost[N][2]);
//}