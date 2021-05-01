#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[500001];

int findH(int N) {
	int max_num = 0;

	for (int i = 1; i <= N; i++) {
		if (arr[N - i] >= i) 
			max_num = i;
			
	}
	return max_num;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + N);
		/*for (int j = 0; j < N; j++) {
			arr[j] = j;
		}*/
		cout << "#" << i << " " << findH(N) << "\n";
	}
	return 0;
}