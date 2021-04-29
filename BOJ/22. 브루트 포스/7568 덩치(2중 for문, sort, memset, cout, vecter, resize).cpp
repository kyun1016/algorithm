//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N;
//
//vector<pair<pair<int, int>, int> > V;
//
//int main() {
//	cin >> N;
//	V.resize(N);
//	for (int i = 0; i < N; i++) {
//		cin >> V[i].first.first >> V[i].first.second;
//		V[i].second = i;
//	}
//
//	sort(V.begin(), V.end(),greater<pair<pair<int, int>, int> > ());
//
//	cout << endl;
//	for (auto a : V) {
//		cout << a.first.first << ' ' << a.first.second << endl;
//	}
//
//	pair<int, int> max_pair = V[0].first;
//	int rank = 1, gab = 0,start = 0, end = 0;
//	vector<int> ans;
//	ans.resize(N);
//
//	for (auto i : V) {
//		if ((i.first.first < max_pair.first) && (i.first.second < max_pair.second)) {
//			max_pair = i.first;
//			rank += gab;
//			gab = 0;
//		}
//		ans[i.second] = rank;
//		gab++;
//	}
//
//	for (auto a : ans)
//		cout << a << ' ';
//
//	return 0;
//}

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

//간단하게 생각하자.
//n^2번 순회하며 나보다 큰 사람 수를 체크해주자.

vector<pair<int, int> > V;
int ans[100];
int N;

int main() {
	cin >> N;
	V.resize(N);

	memset(ans, 0, sizeof(ans));

	//input
	for (int i = 0; i < N; i++)
		cin >> V[i].first >> V[i].second;

	//calc
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if ((V[i].first > V[j].first) & (V[i].second > V[j].second))
				ans[j]++;

	//output
	for (int i=0; i<N;i++)
		cout << ans[i]+1 << ' ';
	
	//return
	return 0;
}