#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, cache[100050];
vector<pair<int, int> > VP;

bool vector_compare(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second)
		//return a.first > b.first; 이렇게 하면 오류가 나오네???
		//이 이유는 N,N의 배정이 가능하기 때문이다.
		//이 경우에 오류가 발생하는 것이었다.
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