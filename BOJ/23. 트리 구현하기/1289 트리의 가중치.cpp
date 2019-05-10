#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long long ull;

const ull INF = 1000000007;
//�տ��� ���� ��� ��ȣ, �ڴ� ����ġ
vector<pair <ull, ull > > adj[100001];
//cache[i]�� (i������ ����� ����ġ ��%INF)�� �����Ѵ�.
ull ret;

ull dp(const ull here, const ull before) {
	//���ϱ⸦ ������� �κ��� �������ش�. �켱 ù ��ŸƮ�� �ڱ� �ڽ� ��ü�� ��Ÿ���� 1�� �־��ش�.
	ull mulUnit = 1,temp;
	for (int i = 0; i < adj[here].size(); i++) {
		ull there = adj[here][i].first;
		//������ ��ġ�ߴ� ���� ������ �湮�� ��尡 ��ġ���� �ʴ´ٸ�.
		if (there != before) {
			//���� ��带 �湮�ϰ�, �� ����� ����ġ�� �����ش�.
			temp = dp(there, here) * adj[here][i].second % INF;
			//���ϱ� ���ֿ� ���� ������ ���ؼ� ret���� ��ȯ�Ѵ�.
			ret =  (ret + temp * mulUnit) % INF;
			//���ϱ� ���ֿ��� 1 + dp[1] + dp[2] + ..... �̷������� ���� �ȴ�.
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