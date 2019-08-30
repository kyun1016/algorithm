//#include<iostream>
//#include<algorithm>
//#include<deque>
//#include<vector>
//
//using namespace std;
//typedef unsigned long long ull;
//
//vector<int> V;
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N;
//	cin >> N;
//
//	int temp;
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		if (temp == 0)
//			V.pop_back();
//		else
//			V.push_back(temp);
//	}
//	
//	ull ret = 0;
//	for (int i = 0; i < V.size(); i++) {
//		ret += V[i];
//	}
//	
//	cout << ret;
//}