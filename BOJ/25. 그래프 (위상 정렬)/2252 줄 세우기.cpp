#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

//vector로 배열을 구현하고, 그 배열에는 자신 앞에 들어가야 할 수를 적어볼까?
queue<int> myFront[32001];
queue<int> myBack[32001];
//그리고 bool 배열을 만들어서 그 수가 사용되었는지 확인을 해주자.
bool visited[32001];
//이번에 출력 할 번호를 queue로 구현하자.
queue<int> PrintME;


//BFS를 활용해서 구현을 하자.
void BFS(int N) {
	//우선 내 뒤에 있는 수들을 처리해주자.
	while(!myBack[N].empty()) {
		int next = myBack[N].front();
		myBack[N].pop();
		bool nextHere=true;
		//만일 다음에 있는 수가 출력되어있지 않은 경우에
		if(!visited[next])
			//다음 수의 앞이 비어있을 때까지
			while(!myFront[next].empty()) {
				//자신의 앞의 수가 이미 출력되었다면 queue를 하나 터트리자.
				if (visited[myFront[next].front()])
					myFront[next].pop();
				//아직 자신의 앞에 수가 있으면 반복 탈출
				else {
					nextHere = false;
					break;
				}
			}
		//다음 수를 출력 할 수 있다면,
		if (nextHere&& !visited[next]) {
			visited[next] = true;
			PrintME.push(next);
		}
	}
	cout << N << " ";
}



int main() {
	int N, M;
	int a, b;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		myFront[b].push(a);
		myBack[a].push(b);
	}

	//int count = 0;
	//
	//while (count < N) {
	//	for (int i = 1; i <= N; i++) {
	//		if (visited[i])
	//			continue;
	//		bool printIt = true;
	//		//자신의 앞에 필요한 수들이 아직 나오지 않았다면 다음으로 넘어간다.
	//		for (int j = 0; j < myFront[i].size(); j++) {
	//			//아직 방문하지 않았다면,
	//			if (!visited[myFront[i][j]]) {
	//				printIt = false;
	//				break;
	//			}
	//		}

	//		if (printIt) {
	//			cout << i << " ";
	//			visited[i] = true;
	//			count++;
	//		}
	//	}
	//}
	
	//우선 BFS를 할 수들을 queue에 집어넣자.
	for (int i = 1; i <= N; i++) {
		if (myFront[i].empty()) {
			PrintME.push(i);
			visited[i] = true;
		}
	}

	//queue가 완전히 빌 때까지 넓이 탐색을 반복한다.
	while (!PrintME.empty()) {
		BFS(PrintME.front());
		PrintME.pop();
	}
	

	return 0;
}