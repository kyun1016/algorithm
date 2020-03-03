//#include<iostream>
//#include<algorithm>
//#include<cstring>		//memset
//
//using namespace std;
//
//int N, M;
//
//int memory[100];
//int cost[100];
////cache[i][j]는 i위치부터 j비용으로 만들수 있는 최대 메모리 크기
//int cache[100][10001];
//
//int calc_memory(const int& here, const int& total_cost) {
//	if (here >= N)
//		return 0;
//	
//	//메모이제이션 활용
//	int& ret = cache[here][total_cost];
//
//	//기저 사례 : 이미 탐색이 완료된 경우
//	if (ret != -1)
//		return ret;
//
//	//현재 앱을 비활성화 시키지 않은 경우
//	ret = calc_memory(here + 1, total_cost);	
//
//	//현재 앱을 비활성화 시키는 경우
//	if (cost[here] <= total_cost)
//		//현재 앱을 비활성화 시키지 않은 경우와 비교하여 더 큰 메모리를 선택
//		ret = max(ret, memory[here] + calc_memory(here + 1, total_cost - cost[here]));
//	
//	return ret;
//}
//
//int main() {
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++)
//		cin >> memory[i];
//	for (int i = 0; i < N; i++)
//		cin >> cost[i];
//
//	//메모이제이션을 활용하기 위해 초기화
//	memset(cache, -1, sizeof(cache));
//
//	int ret = 0;
//
//	//가능한 최대 코스트는 10000까지 탐색을 진행하도록 하자.
//	for (int i = 0; i < 10001; i++) {
//		ret = calc_memory(0, i);
//		if (ret >= M) {
//			cout << i;
//			break;
//		}
//	}
//
//	return 0;
//}