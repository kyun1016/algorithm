//#include <iostream>
//#include <algorithm>
//#include <cstring> //memset
//
//using namespace std;
//
//int N; //최대 1000
//int cache[1001];
//int delay[1001]; //건물 짓는데 걸리는 시간
//int order[1001][1001]; //건물 짓는 조건
//
//
//
//int totalTime(int destination)
//{
//	int &result = cache[destination];
//	if (result != -1)
//		return result;
//	int time = 0;
//	for (int i = 1; i <= N; i++)
//		if (order[i][destination])
//			time = max(time, totalTime(i)); //destination을 만들기 전에 동시에 만들 건물 중 제일 시간 오래 걸리는 건물
//	return result = time + delay[destination];
//}
//
//
//
//int main(void)
//{
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		int K, D, X, Y;
//		cin >> N >> K; //최대 건물 수, 조건 수
//		for (int j = 1; j <= N; j++)
//			cin >> delay[j];
//		memset(cache, -1, sizeof(cache));
//		memset(order, 0, sizeof(order));
//		for (int j = 0; j < K; j++)
//		{
//			cin >> X >> Y; //source, destination
//			order[X][Y] = 1;
//		}
//		cin >> D;
//		if (D < 0 || D>100000)
//			exit(-1);
//		cout << totalTime(D) << endl;
//	}
//	return 0;
//}
//
//
//
//
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//int N, K;
//int time[1002];
//int build_order[1002][1002];
//int delay[1002];
//int final_build;
//
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//
////동적 계획법을 적용하자.
//int calc(int order) {
//	//메모이제이션을 활용.
//	int&ret = delay[order];
//	//기저 사례:이미 계산이 완료된 경우 바로 return
//	if (ret != -1) {
//		return ret;
//	}
//
//	int this_time = 0;
//	//이번 건물 건설에 걸리는 시간은 이전 단계 건물의 건설시간중 가장 큰 값
//	for (int i = 1; i <= N; i++) {
//		//order을 건설하기 위해 필요한 이전 건물을 체크하자.
//		if (build_order[i][order]) {
//			//이전 건물의 건설 시간을 체크한다.
//			//
//			this_time = Max(this_time, calc(i));
//		}
//	}
//
//	//이전 단계 최댓값 + 이번 건물의 건설시간을 더하면 완성이다.
//	return ret = this_time + time[order];
//
//}
//
//int main() {
//	int T,X,Y;
//	cin >> T;
//	while (T--) {
//		cin >> N >> K;
//		//초기화를 해주자.
//		memset(time, 0, sizeof(time));
//		memset(build_order, 0, sizeof(build_order));
//		//-1로 초기화 하는 이유는 시간이 0인 경우도 있기 때문에 -1로 계산이 완료되었음을 체크하였다.
//		memset(delay, -1, sizeof(delay));
//		for (int i = 1; i <= N; i++) {
//			cin >> time[i];
//		}
//		for (int i = 0; i < K; i++) {
//			cin >> X >> Y;
//			build_order[X][Y] = 1;
//		}
//		cin >> final_build;
//		cout << calc(final_build) << endl;
//	}
//}
//
//
//
////포인트는 이전 가지에 Max Time이 지금 나의 시간과 더해지는 것이다.
//
