//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//int cache[101][501];
//vector<pair<int, int> > arr;
//int N;
//
////생각해보자.
////연결을 할 때, 연결할 수 있고, 하지 않을수도 있다.
////첫 연결을 결정하면, 그 이후 연결은 이전 연결의 값보다 더 큰 것인지 확인해준다.
////더 큰 경우에는 연결을 할 수도, 하지 않을수도 있는 것을 반복해 나가자.
//int linkLine(int here = 0, int before=0) {
//	//메모이제이션을 활용하자.
//	int& ret = cache[here][before];
//	//기저 사례: 이미 이 전선의 최대 연결을 구한 경우
//	if (ret != -1)
//		return ret;
//	//기저 사례: 모든 종류의 전선을 방문한 경우
//	if (here >= N)
//		return 0;
//	
//	ret = 0;
//	//연결을 하는 경우, 전선이 교차하는지 확인하자.
//	if (before < arr[here].second)
//		//연결을 할 수 있는 경우지만, 하지 않는 것이 더 클 수 있으므로 하지 않는것도 같이 검사해준다.
//		ret = max(1 + linkLine(here + 1, arr[here].second), linkLine(here + 1, before));
//	//연결이 불가능한 경우는 그냥 다음 줄을 확인하러 넘어가자.
//	else
//		ret = max(ret, linkLine(here + 1, before));
//
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int a, b;
//	cin >> N;
//	//사실 오른쪽은 이번 풀이에서 중요치 않다.
//	for (int i = 0; i < N; i++) {
//		cin >> a >> b;
//		arr.push_back({ a,b });
//	}
//
//	sort(arr.begin(), arr.end());
//	for (int i = 0; i <= N; i++) {
//		for (int j = 0; j <= 500; j++) {
//			cache[i][j] = -1;
//		}
//	}
//
//	int ret = linkLine();
//
//	cout << N - ret;
//	return 0;
//}