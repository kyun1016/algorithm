#include<iostream>
#include<vector>

using namespace std;

//int Count = 1;
vector<pair<int, int> > v;

//int moveCount(int N) {
//	int ret = 1;
//	for (int i = 1; i <= N-1; i++) {
//		ret *= 2;
//		ret += 1;
//	}
//	return ret;
//}

void move(int N, int x, int y) {
	if (N == 1)
		v.push_back({ x,y });
	else {
		move(N - 1, x, 6 - x - y);
		v.push_back({ x,y });
		move(N - 1, 6 - x - y, y);
	}
		
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	move(N, 1, 3);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}