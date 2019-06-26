//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//typedef long long ll;
//using namespace std;
//
//vector<ll> acid;
//vector<ll> basic;
//vector<ll> acidSum;
//vector<ll> basicSum;
//
//bool cmp(ll a, ll b) {
//	return abs(a) < abs(b);
//}
//
//pair<ll, ll> findRoot(const ll& N) {
//	pair<ll, ll> ret;
//	if (N > 0) {
//		for (int i = 0; i < acid.size() - 1; i++)
//			for (int j = i + 1; j < acid.size(); j++)
//				if (acid[i] + acid[j] == N)
//					return ret = { acid[i], acid[j] };
//	}
//	if (N < 0) {
//		for (int i = 0; i < basic.size() - 1; i++)
//			for (int j = i + 1; j < basic.size(); j++)
//				if (basic[i] + basic[j] == N)
//					return ret = { basic[i], basic[j] };
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int N;
//	cin >> N;
//	ll temp;
//	ll arr[3];
//	ll sum = 3000000000;
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		if (temp > 0)
//			acid.push_back(temp);
//		else
//			basic.push_back(temp);
//	}
//
//	sort(acid.begin(), acid.end());
//	sort(basic.begin(), basic.end(), cmp);
//
//	if (basic.empty()) {
//		for (int i = 0; i < 3; i++)
//			cout << acid[i] << " ";
//		return 0;
//	}
//	//이건 다시 오름차순 정렬을 거쳐주도록 수정(이후에)
//	if (acid.empty()) {
//		for (int i = 2; i >= 0; i--)
//			cout << basic[i] << " ";
//	}
//
//
//	if (acid.size() >= 2 && !basic.empty()) {
//		for (int i = 0; i < acid.size() - 1; i++)
//			for (int j = i + 1; j < acid.size(); j++)
//				acidSum.push_back(acid[i] + acid[j]);
//		for (int i = 0; i < basic.size(); i++)
//			acidSum.push_back(basic[i]);
//	}
//
//	if (basic.size() >= 2 && !acid.empty()) {
//		for (int i = 0; i < basic.size() - 1; i++)
//			for (int j = i + 1; j < basic.size(); j++)
//				basicSum.push_back(basic[i] + basic[j]);
//		for (int i = 0; i < acid.size(); i++)
//			basicSum.push_back(acid[i]);
//	}
//
//	if (basic.size() >= 3) {
//		arr[0] = basic[0];
//		arr[1] = basic[1];
//		arr[2] = basic[2];
//		sum = basic[0] + basic[1] + basic[2];
//		sum = abs(sum);
//	}
//
//	if (acid.size() >= 3) {
//		if (sum > acid[0] + acid[1] + acid[2]) {
//			sum = acid[0] + acid[1] + acid[2];
//			arr[0] = acid[0];
//			arr[1] = acid[1];
//			arr[2] = acid[2];
//		}
//	}
//
//	sort(acidSum.begin(), acidSum.end(), cmp);
//	sort(basicSum.begin(), basicSum.end(), cmp);
//
//	for (int i = 0; i < acidSum.size() - 1; i++) {
//		if (sum > abs(acidSum[i] + acidSum[i + 1])) {
//			sum = abs(acidSum[i] + acidSum[i + 1]);
//			if (acidSum[i] >= 0) {
//				arr[0] = acidSum[i + 1];
//				pair<ll, ll> ret = findRoot(acidSum[i]);
//				arr[1] = ret.first;
//				arr[2] = ret.second;
//			}
//			else {
//				arr[0] = acidSum[i];
//				pair<ll, ll> ret = findRoot(acidSum[i + 1]);
//				arr[1] = ret.first;
//				arr[2] = ret.second;
//			}
//		}
//	}
//
//	for (int i = 0; i < basicSum.size() - 1; i++) {
//		if (sum > abs(basicSum[i] + basicSum[i + 1])) {
//			sum = abs(basicSum[i] + basicSum[i + 1]);
//			if (basicSum[i] >= 0) {
//				arr[0] = basicSum[i];
//				pair<ll, ll> ret = findRoot(basicSum[i + 1]);
//				arr[1] = ret.first;
//				arr[2] = ret.second;
//			}
//			else {
//				arr[0] = basicSum[i + 1];
//				pair<ll, ll> ret = findRoot(basicSum[i]);
//				arr[1] = ret.first;
//				arr[2] = ret.second;
//			}
//		}
//	}
//	
//	sort(arr, arr + 3);
//
//	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
//
//
//	return 0;
//}