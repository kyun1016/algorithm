#include<iostream>
#include<deque>

using namespace std;

const int MAX = 5000001;

deque<pair<int, int> > dq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, L, temp;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> temp;

		if (!dq.empty() && dq.front().second <= i - L)
			dq.pop_front();

		while (!dq.empty() && dq.back().first > temp)
			dq.pop_back();

		dq.push_back({ temp, i });
		cout << dq.front().first << " ";
	}
}