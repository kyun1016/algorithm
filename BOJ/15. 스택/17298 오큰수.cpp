//#include<iostream>
//#include<algorithm>
//#include<deque>
//#include<vector>
//#include<stack>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N;
//	cin >> N;
//	vector<int> V(N), ret(N);
//	stack<int> stk;
//
//	for (int i = 0; i < N; i++)
//		cin >> V[i];
//
//	for (int i = N - 1; i >= 0; i--) {
//		while (!stk.empty() && stk.top() <= V[i])
//			stk.pop();
//
//		if (stk.empty())
//			ret[i] = -1;
//		else
//			ret[i] = stk.top();
//
//		stk.push(V[i]);
//	}
//	for (auto a : ret)
//		cout << a << " ";
//}