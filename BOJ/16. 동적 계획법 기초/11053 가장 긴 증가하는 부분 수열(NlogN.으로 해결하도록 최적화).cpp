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
		//lower_bound�� Ȱ���ؼ� ���� ���ڰ� ��ġ�� ��ġ�� �����Ѵ�.
		//ã�� ��ġ���� 2������ ������ ������ �ȴ�.
		//1. ���� �߰� ��ġ�� ����ϴ� ���
		//�� ���� �� ��ġ�� �ּڰ��� ��ȭ�ϰ� �ȴ�.
		//2. ���� ������ ��ġ�� ����ϴ� ���
		//���� �κ� �κм����� ���̰� ������� �ȴ�.
		int* pos = lower_bound(arr, arr + longest_increasing_subsequence_length, temp);
		*pos = temp;
		if (pos == arr + longest_increasing_subsequence_length)
			longest_increasing_subsequence_length++;
	}

	cout << longest_increasing_subsequence_length;

	return 0;
}