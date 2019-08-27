#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef unsigned long long ull;

int N, K;
vector<pair<int, int> > Arr;
int cache[100001];

void dp() {
	for (int i = 0; i < N; i++) {
		for (int j = K; j >= 1; j--) {
			if (Arr[i].first <= j) {
				cache[j] = max(cache[j], cache[j - Arr[i].first] + Arr[i].second);
			}
		}
	}

	cout << cache[K];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//W = 무게, V = 가치
	int W, V;
	int ret = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		Arr.push_back({ W,V });
	}
	
	dp();

	return 0;
}