#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001], N, longest_increasing_subsequence_length;

int main() {
	//input
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		//lower_bound를 활용해서 지금 숫자가 배치될 위치를 선정한다.
		//찾은 위치에서 2가지로 동작이 나뉘게 된다.
		//1. 숫자 중간 위치를 출력하는 경우
		//이 경우는 그 위치의 최솟값이 변화하게 된다.
		//2. 숫자 마지막 위치를 출력하는 경우
		//최장 부분 부분수열의 길이가 길어지게 된다.
		int* pos = lower_bound(arr, arr + longest_increasing_subsequence_length, temp);
		*pos = temp;
		if (pos == arr + longest_increasing_subsequence_length)
			longest_increasing_subsequence_length++;
	}

	cout << longest_increasing_subsequence_length;

	return 0;
}