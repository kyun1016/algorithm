//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//
////거중기가 감당할 수 있는 무게, 화물의 무게을 저장하는 배열
//int can_trans[50];
//int cargo_weight[100000];
////화물선에 실리는 짐의 개수를 저장하는 배열, 자주 변화하기에 cache로 이름을 붙였다.
//int cache[50];
//
//
////구현을 하자. O(M)이다.
//int transfer(const int N, const int M) {
//	int i, j(0);
//	int MAX(0), temp, count,flag(0);
//
//	//기저사례
//	if (cargo_weight[M-1] > can_trans[N-1])
//		return -1;
//
//	//cache를 초기화하자.
//	memset(cache, 0, sizeof(cache));
//	for (i = 0; i < M; i++) {
//		//가벼운 거중기에 최대한 짐을 몰아준다.
//		if (can_trans[j] >= cargo_weight[i])
//			cache[j]++;
//		//거중기가 부담할 수 없게되면, 그 다음 거중기를 찾는다.
//		else {
//			while (can_trans[j] < cargo_weight[i]) {
//				j++;
//			}
//			//찾은 거중기에 짐을 싣는다.
//			cache[j]++;
//		}
//	}
//	
//
//	//각각의 화물선에 담기는 화물의 양을 정규화 시키기 위해서, 가벼운 곳의 짐이 더 많을경우 다음 화물차로 옮겨싣는다.
//	for (int i = N - 1; i >0; i--) {
//		//가벼운 거중기에 짐이 더 적어질 때까지 반복한다.
//		while (cache[i - 1] > cache[i]) {
//			//짐을 옮기는 작업을 했다면, flag를 세운다.
//			flag = 1;
//			//짐을 순차적으로 더 큰 거중기로 옮긴다.
//			for (j = i; j < N; j++) {
//				if (cache[j - 1] > cache[j]) {
//					temp = cache[j - 1] - cache[j];
//					if (temp % 2) {
//						cache[j - 1] -= temp / 2 + 1;
//						cache[j] += temp / 2 + 1;
//					}
//					else {
//						cache[j - 1] -= temp / 2;
//						cache[j] += temp / 2;
//					}
//				}
//			}
//		}
//		//이번에 짐을 옮겼었다면, 다시 처음으로 돌아가서 확인을 다시하자.
//		if (flag) {
//			i = N - 1;
//			flag = 0;
//		}
//		//flag가 0이라면, 이번 반복이 마무리된다.
//	}
//
//	//짐이 가장 많이 실린 거중기를 찾는다.
//	for (i = 0; i < N; i++) {
//		MAX = max(MAX, cache[i]);
//	}	
//
//	//마지막 반환.
//	return MAX;
//}
//
//int main() {
//	int T, N, M;
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//		cin >> N;
//		for (int j = 0; j < N; j++) {
//			cin >> can_trans[j];
//		}
//
//		cin >> M;
//		for (int j = 0; j < M; j++) {
//			cin >> cargo_weight[j];
//		}
//		sort(can_trans, can_trans + N);
//		sort(cargo_weight, cargo_weight + M);
//
//		cout << "#" << i << " " << transfer(N, M) << endl;
//	}
//	return 0;
//}