#include<iostream>
#include<cstring>

using namespace std;

int arr[1001];
bool visited[1001];

//아주 간단한 깊이탐색 구현
void DFS(int i) {
	if (visited[i])
		return;
	visited[i] = true;
	DFS(arr[i]);
}

int findCycles(int N) {
	//초기화를 해준다.
	memset(visited, false, sizeof(visited));
	int Count = 0;
	for (int i = 1; i <= N; i++) {
		//배열중에 아직 선택이 안된 것이 있다면,
		if (!visited[i]) {
			//깊이탐색을 해서 루프 고리를 찾아낸다.
			DFS(i);
			//그리고 루프 1개 추가.
			Count++;
		}
	}

	//루프 개수 반환
	return Count;
}

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		//루프를 찾으러 갑시다.
		cout << findCycles(N) << endl;

	}
}