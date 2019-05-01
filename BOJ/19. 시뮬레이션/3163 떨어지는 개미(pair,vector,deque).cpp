//////#include<iostream>
//////#include<algorithm>
//////#include<string.h>
//////
//////using namespace std;
//////
//////int pos[500001];
//////
//////
//////int falling(int L, int k) {
//////	int count, left, right, i, flag;
//////	count = left = right = i = 0;
//////	while (count < k) {
//////		flag = 0;
//////		if (pos[i] < 0) {
//////			count++;
//////			left++;
//////			flag += 1;
//////		}
//////		if (pos[L - i] > 0) {
//////			count++;
//////			right++;
//////			flag += 2;
//////		}
//////		i++;
//////	}
//////	if (flag == 1) {
//////		count = 0;
//////		i = 0;
//////		while (count < left) {
//////			if (pos[i] != 0) {
//////				count++;
//////			}
//////			i++;
//////		}
//////		return pos[i - 1];
//////	}
//////	else if (flag == 2) {
//////		count = 0;
//////		i = L;
//////		while (count < right) {
//////			if (pos[i] != 0) {
//////				count++;
//////			}
//////			i--;
//////		}
//////		return pos[i + 1];
//////	}
//////	else if (flag == 3) {
//////		int count2 = 0;
//////		i = L;
//////		while (count2 < right) {
//////			if (pos[i] != 0) {
//////				count2++;
//////			}
//////			i--;
//////		}
//////		count2 = 0;
//////		int j = 0;
//////		while (count2 < left) {
//////			if (pos[j] != 0) {
//////				count2++;
//////			}
//////			j++;
//////		}
//////		if (count == k)
//////			return max(pos[i + 1], pos[j - 1]);
//////		else if (count > k)
//////			return min(pos[i + 1], pos[j - 1]);
//////
//////	}
//////
//////	return 0;
//////}
//////
//////
//////
//////int main() {
//////	int T, N, L, k, a, b;
//////	cin >> T;
//////	while (T--) {
//////		cin >> N >> L >> k;
//////		memset(pos, 0, sizeof(pos));
//////		while (N--) {
//////			cin >> a >> b;
//////			pos[a] = b;
//////		}
//////		cout << falling(L, k) << endl;
//////	}
//////
//////	return 0;
//////}
////
////#include<iostream>
////#include <algorithm>
////
////using namespace std;
////
////int arr[100001],change_arr[100001], id[100001];
////
////int fall_id(int N, int k) {
////	int find = change_arr[k-1];
////	int count = 0;
////	int save[2],t(0);
////	for (int i = 0; i < N; i++) {
////		if (arr[i] == find) {
////			count++;
////			save[t++] = id[i];
////		}
////	}
////	if (count > 1)
////		return min(save[0], save[1]);
////	return save[0];
////}
////
////int main() {
////	int T, N, L, k,pos,id;
////	cin >> T;
////	while (T--) {
////		cin >> N >> L >> k;
////		for (int i = 0; i < N;i++) {
////			cin >> pos >> id;
////			if (id > 0) {
////				arr[i] = L - pos;
////				change_arr[i] = L - pos;
////			}
////			else {
////				arr[i] = pos;
////				change_arr[i] = pos;
////			}
////			id[i] = id;
////		}
////		sort(change_arr, change_arr + N);
////		cout << fall_id(N, k);
////	}
////
////}
//
//
//
//
//////vector를 활용하여 데이터를 담아보자.
////#include<iostream>
////#include<algorithm>
////#include<vector>
////#include<deque>
////
////using namespace std;
////
////vector<pair<int, int>> ant_list;
////deque<int> id_list;
////
////void fall_ant(int k) {
////	//정렬을 하고 시작.
////	sort(ant_list.begin(), ant_list.end());
////
////	int ret;
////	for (int i = 0; i < k; i++) {
////		// id의 앞,뒤를 먼저 기억해놓는다.
////		int frontValue = id_list.front(), backValue = id_list.back();
////
////		// 떨어지는 시간이 같은 경우
////		if (i != k - 1 && ant_list[i].first == ant_list[i + 1].first) {
////			if (frontValue < backValue) {
////				ret = backValue;
////			}
////			else {
////				ret = frontValue;
////			}
////			// 2개를 처리해주었기 때문에 덱에서 모두 pop해주고 i는 한번더 증가시킨다.
////			id_list.pop_back(); id_list.pop_front(); i++;
////		}
////		else if (i == k - 1 && ant_list[i].first == ant_list[i + 1].first) {
////			if (frontValue < backValue) {
////				ret = frontValue;
////			}
////			else {
////				ret = backValue;
////			}
////			id_list.pop_back(); id_list.pop_front(); i++;
////		}
////		// 일반적인 경우 id의 부호 즉, 방향에 따라서 어떤 id를 저장할 건지 결정한다.
////		else if (ant_list[i].second < 0) {
////			ret = frontValue;
////			id_list.pop_front();
////		}
////		else {
////			ret = backValue;
////			id_list.pop_back();
////		}
////	}
////	cout << ret << endl;
////
////	// 초기화
////	ant_list.clear();
////	id_list.clear();
////}
////
////int main() {
////	int T, N, L, k,pos,id;
////	cin >> T;
////	while (T--) {
////		cin >> N >> L >> k;
////		for (int i = 0; i < N;i++) {
////			cin >> pos >> id;
////			id_list.push_back(id);
////			id < 0 ? ant_list.push_back({ pos, id }) : ant_list.push_back({L - pos, id });
////		}
////		fall_ant(k);
////	}
////
////}
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int t, n, l, k, x;
//pair<int, int> p[100000];
//
//int main() {
//	cin >> t;
//	while (t--) {
//		int cnt = 0;
//		vector<int> v;
//		cin >> n >> l >> k;
//		for (int i = 0; i < n; i++) {
//			cin >> x >> p[i].second;
//			if (p[i].second < 0)
//				p[cnt++].first = x;
//			else
//				v.push_back(l - x);
//		}
//		for (int a : v) {
//			p[cnt++].first = a;
//			cout << "vector : "<< a << endl;
//		}
//
//		sort(p, p + n);
//		cout << p[k - 1].second << endl;
//	}
//
//	return 0;
//}