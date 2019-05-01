//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int ret[50];
//pair<int, int> P[50];
//
//void calc(int N){
//	for (int i = 0; i < N; i++) {
//		ret[P[i].second] = i;
//	}
//
//	for (int i = 0; i < N; i++) {
//		cout << ret[i] << " ";
//	}
//}
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> P[i].first;
//		P[i].second = i;
//	}
//
//	sort(P, P + N);
//
//	calc(N);
//
//	return 0;
//}