//# pragma GCC optimize ("O3")
//# pragma GCC optimize ("Ofast")
//# pragma GCC optimize ("unroll-loops")
//
//#include <iostream>
//#include<vector>
//
//#pragma warning(disable:4996)
//#pragma comment(linker, "/STACK:336777216")
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//typedef tuple<int, int, int> ti3;
//typedef tuple<int, int, int, int> ti4;
//typedef pair<ll, ll> pll;
//typedef vector<ll> vl;
//typedef tuple<ll, ll, ll> tl3;
//typedef tuple<ll, ll, ll, ll> tl4;
//
//#define rep(i,a,b) for(int i = a; i < b; i++)
//#define all(x) (x).begin(), (x).end()
//#define sf1(a) cin >> a
//
//#define pf1(a) cout << (a) << ' '
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	vi pre[16];
//	vi depth[16];
//	pre[1].resize(2);
//	pre[1][1] = 1;
//	depth[1].resize(2);
//	depth[1][1] = 1;
//	for (int i = 2; i <= 15; i++) {
//		pre[i].resize((1 << i));
//		depth[i].resize((1 << i));
//		pre[i][1] = 1;
//		depth[i][1] = 1;
//		for (int j = 1; j <= (1 << (i - 1)) - 1; j++) {
//			depth[i][j + 1] = depth[i - 1][j] + 1;
//			depth[i][j + (1 << (i - 1))] = depth[i - 1][j] + 1;
//			if (depth[i - 1][j] + 1 != i) {
//				pre[i][j + 1] = 2 * pre[i - 1][j] + 1;
//				pre[i][j + (1 << (i - 1))] = 2 * pre[i - 1][j];
//			}
//			else {
//				pre[i][j + 1] = 2 * pre[i - 1][j];
//				pre[i][j + (1 << (i - 1))] = 2 * pre[i - 1][j] + 1;
//			}
//		}
//	}
//	int N;
//	sf1(N);
//	rep(i, 1, (1 << N))
//		pf1(pre[N][i]);
//
//}