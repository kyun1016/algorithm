//#include <iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//
//int Answer;
//int Arr[200001];
//bool visited[200001];
//queue<int> qu;
//
//void checkMinBus(const int& N, const int& K) {
//	//int count = 0;
//	//int here_ability = 0;
//	//qu.push(0);
//	//int i = 1;
//	//while (!qu.empty()) {
//	//	int here = qu.front();
//	//	qu.pop();
//	//	here_ability = Arr[here];
//	//	count++;
//	//	for (i; i < N; i++) {
//	//		//아직 방문하지 않은 곳이면서, 능력이 K보다 작게 차이난다면, qu에 넣어준다.
//	//		if ((Arr[i] - here_ability) <= K) {
//	//			qu.push(i);
//	//		}
//	//		//
//	//		else if ((Arr[i] - here_ability) > K) {
//	//			qu.push(i);
//	//			count--;
//	//			i++;
//	//			break;
//	//		}
//	//	}
//	//	//만일 이번 반복에서 변한 항목이 없다면, 탐색이 종료된 것이므로 break;
//	//}
//
//	int count = 0;
//	int j = 1;
//	for (int i = 0; i < N; i++) {
//		while (j < N&&Arr[j] - Arr[i] <= K) j++;
//		count = max(count, j - i);
//	}
//
//	
//
//
//	Answer = count;
//}
//
//void calc(const int& N, const int& K) {
//	int ans = 0; int j = 0;
//	for (int i = 0; i < N; i++) {
//		while (j < N && Arr[j] - Arr[i] <= K) ++j;
//		ans = max(ans, j - i);
//	}
//	Answer = ans;
//}
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int T, test_case;
//
//	int N, K;
//
//	 // freopen("input.txt", "r", stdin);
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		cin >> N >> K;
//		//초기화
//		Answer = 0;
//		for (int i = 0; i < N; i++)
//			cin >> Arr[i];
//		sort(Arr, Arr + N);
//		checkMinBus(N,K);
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}