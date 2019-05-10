#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long long ull;

const ull INF = 1000000007;
//앞에는 인접 노드 번호, 뒤는 가중치
vector<pair <ull, ull > > adj[100001];
//cache[i]는 (i길이의 노드의 가중치 합%INF)을 저장한다.
ull ret;

ull dp(const ull here, const ull before) {
	//곱하기를 담당해줄 부분을 구현해준다. 우선 첫 스타트는 자기 자신 자체를 나타내는 1을 넣어준다.
	ull mulUnit = 1,temp;
	for (int i = 0; i < adj[here].size(); i++) {
		ull there = adj[here][i].first;
		//이전에 위치했던 노드와 다음에 방문할 노드가 일치하지 않는다면.
		if (there != before) {
			//다음 노드를 방문하고, 그 결과에 가중치를 곱해준다.
			temp = dp(there, here) * adj[here][i].second % INF;
			//곱하기 유닛에 지금 가지를 곱해서 ret으로 반환한다.
			ret =  (ret + temp * mulUnit) % INF;
			//곱하기 유닛에는 1 + dp[1] + dp[2] + ..... 이런식으로 들어가게 된다.
			mulUnit = (temp + mulUnit) % INF;
/*
			temp = adj[here][i].second % INF;
			sum += dp(there, here);

			sum += dp(there, here) * adj[here][i].second % INF;*/
		}
		
	}
	return mulUnit;
}

int main() {
	ull N,a,b,c;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dp(1, 0);
	cout << ret;

	return 0;
}