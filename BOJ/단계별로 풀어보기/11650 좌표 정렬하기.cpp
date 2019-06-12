#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> > v;

bool cmp(pair<int, int>, pair<int, int>) {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}