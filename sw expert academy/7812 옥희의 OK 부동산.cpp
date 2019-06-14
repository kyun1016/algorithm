#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[10001];

int makePortfolio(const int& N, const int& M) {
	int count = 0;
	pair<int, int> idx;
	idx = { 0,0 };
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum < M) {
			sum += arr[i];
			idx.second = i;
		}
		if (sum == M) {
			count++;
			sum -= arr[idx.first];
			idx.first++;
		}
		if (sum > M)
		{
			while (1)
			{
				if (sum <= M)
					break;
				sum -= arr[idx.first];
				idx.first++;
			}
			
		}
		if (sum == M) {
			count++;
			sum -= arr[idx.first];
			idx.first++;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, N, M;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		cout << "#" << i << " " << makePortfolio(N, M) << "\n";
	}
	return 0;
}