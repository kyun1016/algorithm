#include<iostream>
#include<queue>
#include<functional>	//greater를 사용하기 위해 선언

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, num;
	cin >> N;

	//<data tape, container type, 정렬 기준>
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0;i < N;i++) {
		cin >> num;
		if (num) {
			pq.push(num);
		}
		else {
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
				
		}
	}

	return 0;
}