#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[25][25];
bool visited[25];
int ret = 987654321;

void dfs(const int& depth, const int& here) {
	if (depth == N / 2) {
		int team_A_sum = 0;
		int team_B_sum = 0;
		for (int y = 0; y < N; y++)
			for (int x = y+1; x < N; x++) {
				if (visited[x] && visited[y])
					team_A_sum += arr[x][y] + arr[y][x];
				if (!visited[x] && !visited[y])
					team_B_sum += arr[x][y] + arr[y][x];
			}
		ret = min(ret, abs(team_A_sum - team_B_sum));
		return;
	}

	for (int i = here; i < N; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		dfs(depth + 1, i+1);
		visited[i] = false;
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	//input
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> arr[y][x];

	//calc
	dfs(0, 0);

	//output
	cout << ret << endl;

	return 0;
}