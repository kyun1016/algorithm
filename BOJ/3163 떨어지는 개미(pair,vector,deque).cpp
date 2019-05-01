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
//////vector�� Ȱ���Ͽ� �����͸� ��ƺ���.
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
////	//������ �ϰ� ����.
////	sort(ant_list.begin(), ant_list.end());
////
////	int ret;
////	for (int i = 0; i < k; i++) {
////		// id�� ��,�ڸ� ���� ����س��´�.
////		int frontValue = id_list.front(), backValue = id_list.back();
////
////		// �������� �ð��� ���� ���
////		if (i != k - 1 && ant_list[i].first == ant_list[i + 1].first) {
////			if (frontValue < backValue) {
////				ret = backValue;
////			}
////			else {
////				ret = frontValue;
////			}
////			// 2���� ó�����־��� ������ ������ ��� pop���ְ� i�� �ѹ��� ������Ų��.
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
////		// �Ϲ����� ��� id�� ��ȣ ��, ���⿡ ���� � id�� ������ ���� �����Ѵ�.
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
////	// �ʱ�ȭ
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