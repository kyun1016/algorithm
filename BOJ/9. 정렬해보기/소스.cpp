#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> V, idx;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;
	V.resize(N);
	idx.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i];
		idx[i] = V[i];
	}

	sort(idx.begin(), idx.end());
	////개수를 줄이는 방법
	//idx.resize(unique(idx.begin(), idx.end()) - idx.begin());
	//for (int a : idx) {
	//	cout << a << endl;
	//}

	//반복되는 뒤의 쓰레기 값을 지우는 방법
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	//for (int a : idx) {
	//	cout << a << endl;
	//}

	for (int a : V) {
		int pos = lower_bound(idx.begin(), idx.end(), a) - idx.begin();
		cout << pos << ' ';
	}
	return 0;
}