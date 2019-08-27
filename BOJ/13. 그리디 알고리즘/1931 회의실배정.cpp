//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//vector<pair<int, int>> timeTable;
//
//int N;
//
//int dp() {
//	int ret = 0;
//	int whatTimeIsItNow = 0;
//
//	for (int i = 0; i < N; i++) {
//		if (timeTable[i].second >= whatTimeIsItNow) {
//			ret++;
//			whatTimeIsItNow = timeTable[i].first;
//		}
//	}
//	
//
//
//
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//
//	cin >> N;
//	int a, b;
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b;
//		timeTable.push_back({ b,a });
//	}
//
//	sort(timeTable.begin(), timeTable.end());
//	////중복되서 필요없는 수를 지워준다.
//	//for (int i = 1; i < N; i++) {
//	//	while (i < N && timeTable[i - 1].first == timeTable[i].first) {
//	//		timeTable.erase(timeTable.begin() + i);
//	//		N--;
//	//	}
//	//}
//
//	/*for (int i = 0; i < N; i++) {
//		cout << timeTable[i].first << " " << timeTable[i].second << endl;
//	}*/
//
//	cout << dp();
//
//	return 0;
//}