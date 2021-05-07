//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int N;
//
//int main() {
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	//input
//	cin >> N;
//	int temp;
//	priority_queue<int> pq_max, pq_min;
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		//calc
//		if (pq_max.size() > pq_min.size())
//			pq_min.push(-temp);
//		else
//			pq_max.push(temp);
//
//		if(!pq_max.empty() && !pq_min.empty())
//			if (pq_max.top() > -pq_min.top()) {
//				int max_temp = pq_max.top(), min_temp = -pq_min.top();
//				
//				pq_max.pop(); pq_min.pop();
//
//				pq_max.push(min_temp);
//				pq_min.push(-max_temp);
//			}
//		cout << pq_max.top() << '\n';
//	}
//
//	return 0;
//}