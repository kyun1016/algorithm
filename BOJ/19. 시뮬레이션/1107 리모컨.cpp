//#include<iostream>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//int INF = 1000007;
//int broken[10];
//int N, M;
//
//bool possible(int k) {
//	if (k == 0)
//		return broken[0] ? false : true;
//	while (k) {
//		if (broken[k % 10] == 1) {
//			return false;
//		}
//		k /= 10;
//	}
//
//	return true;
//}
//
//int find() {
//	int ret = abs(N - 100);
//	int temp;
//	int inf = N * 2 - 100;
//	if (inf < 100)
//		inf = 100;
//
//	//기저 사례 : 모든 버튼이 존재하지 않는 경우
//	if (M == 10)
//		return ret;
//
//	//N보다 더 큰 수로 버튼 이동
//	for (int i = N; i <= inf; i++) {
//		//버튼을 누른 횟수
//		temp = to_string(i).length() + abs(i - N);
//		if (possible(i)) {
//			//한번이라도 이동을 하면 바로 탐색을 종료한다.
//			ret = min(temp, ret);
//			break;
//		}
//	}
//
//	for (int i = N; i >= 0; i--) {
//		//버튼을 누른 횟수
//		temp = to_string(i).length() + abs(i - N);
//		if (possible(i)) {
//			//한번이라도 이동을 하면 바로 탐색을 종료한다.
//			ret = min(temp, ret);
//			break;
//		}
//	}
//
//	return ret;
//}
//
//int main(void)
//{
//	int temp;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> temp;
//		broken[temp] = 1;
//	}
//	cout << find() << endl;
//	return 0;
//}