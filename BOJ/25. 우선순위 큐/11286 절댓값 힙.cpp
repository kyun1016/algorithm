//#include<iostream>
//#include<queue>
//#include<functional>	//greater를 사용하기 위해 선언
//
//using namespace std;
//
//int main() {
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//
//	int N, num;
//	cin >> N;
//
//	//<data tape, container type, 정렬 기준>
//	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
//
//	for (int i = 0;i < N;i++) {
//		cin >> num;
//		if (num) {
//			pq.push({ abs(num), num });
//		}
//		else {
//			if (pq.empty())
//				cout << 0 << "\n";
//			else {
//				cout << pq.top().second << "\n";
//				pq.pop();
//			}
//		}
//	}
//
//	return 0;
//}