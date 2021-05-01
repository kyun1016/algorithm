//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MAX_SIZE = 1000;
//
//int bruteForce(const vector<int>& h) {
//	int ret = 0;
//	int N = h.size();
//	//가능한 모든 left, right 조합을 순회한다.
//	for (int left = 0; left < N; left++) {
//		int minHeight = h[left];
//		for (int right = left; right < N; right++) {
//			minHeight = min(minHeight, h[right]);
//			ret = max(ret, (right - left + 1)*minHeight);
//		}
//	}
//	return ret;
//}