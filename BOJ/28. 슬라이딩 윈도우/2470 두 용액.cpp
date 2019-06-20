//#include<iostream>
//#include<vector>
//#include<deque>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//
//ll arr[5001];
//
//bool cmp(ll a, ll b) {
//	return abs(a) < abs(b);
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//	sort(arr, arr + N, cmp);
//	
//	ll a, b;
//	ll ret = 2000000007;
//	for (int i = 0; i < N-1; i++) {
//		if (ret > abs(arr[i] + arr[i + 1])) {
//			ret = abs(arr[i] + arr[i + 1]);
//			a = arr[i];
//			b = arr[i+1];
//		}
//	}
//
//	if(a<b)
//		cout << a << " " << b;
//	else
//		cout << b << " " << a;
//
//	
//			
//
//
//}