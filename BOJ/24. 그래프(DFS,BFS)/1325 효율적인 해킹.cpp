#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

//vector<pair<int, int> > trust;
//trust[i]는 자신을 신뢰하는 컴퓨터를 자손 노드로 갖는다.
vector<int> trust[10001];
bool visited[10001];
pair<int,int> Count[10001];

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}


//첫번째 구현은 틀렸다. 왜냐하면 자손노드중에 2번 방문하는 경우는 고려하지 못했기 때문이다.
void calcHackComputer(int here, int mather) {
	//기저 사례 : 이미 방문한 노드이면 종료
	if (visited[here])
		return;
	visited[here] = true;

	for (int i = 0; i < trust[here].size(); i++) {
		if (!visited[trust[here][i]]) {
			Count[mather].first++;
			calcHackComputer(trust[here][i], mather);
		}
	}
	Count[mather].first++;
}

int main() {
	int N, M,a,b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		//trust.push_back({ a,b });
		//a가 b를 신뢰하므로 이를 vector에 반영한다.
		trust[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		calcHackComputer(i, i-1);
		Count[i-1].second = i;
	}
	

	sort(Count, Count + N, comp);

	int temp = Count[0].first;

	for (int i = 0; i < N; i++) {
		//cout << Count[i].second << " : " << Count[i].first << endl;

		if (Count[i].first == temp) {
			cout << Count[i].second << " ";
		}
		else {
			break;
		}
	}

	return 0;
}