#include<iostream>
#include<algorithm>


using namespace std;

int N, C;
int arr[200001];
int MIN = 1000000007;
int ret = 0;

////무식하게 풀기
//void calc(int num, int pos) {
//	if (num == C) {
//		if (ret < MIN)
//			ret = MIN;
//		return;
//	}
//	else {
//		for (int i = pos + 1; i < N;i++) {
//			int temp = MIN;
//			int dist = arr[i] - arr[pos];
//			if (dist < MIN)
//				MIN = dist;
//			calc(num + 1, i);
//			MIN = temp;
//		}
//	}
//}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> C;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + N);

	//calc(1, 0);

	int high = arr[N - 1], low = 0, mid;
	int pos, count;
	while (low <= high) {
		mid = (low + high) / 2;
		pos = 0, count = 1;	//가장 첫번째 arr[0]에는 바로 설치하고 시작한다.
		for (int i = 1;i < N;i++) {
			if (arr[i] - arr[pos] >= mid) {
				pos = i;
				count++;
			}
		}
		if (count >= C) {
			if (ret < mid)
				ret = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	
	cout << ret;
}