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
//	//������ ��� left, right ������ ��ȸ�Ѵ�.
//	for (int left = 0; left < N; left++) {
//		int minHeight = h[left];
//		for (int right = left; right < N; right++) {
//			minHeight = min(minHeight, h[right]);
//			ret = max(ret, (right - left + 1)*minHeight);
//		}
//	}
//	return ret;
//}