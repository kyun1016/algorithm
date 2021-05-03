#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, cache[100050];
vector<pair<int, int> > VP;

bool vector_compare(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second)
		//return a.first > b.first; �̷��� �ϸ� ������ ������???
		//�� ������ N,N�� ������ �����ϱ� �����̴�.
		//�� ��쿡 ������ �߻��ϴ� ���̾���.
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	//input
	cin >> N;
	VP.resize(N);
	for (int i = 0; i < N; i++)
		cin >> VP[i].first >> VP[i].second;

	//calc
	sort(VP.begin(), VP.end(), vector_compare);
	int max_num = VP[0].second;
	int count = 1;
	for (int i = 1; i < N; i++) {
		if (VP[i].first >= max_num) {
			max_num = VP[i].second;
			count++;
		}
	}

	//output
	cout << count << endl;

	return 0;
}