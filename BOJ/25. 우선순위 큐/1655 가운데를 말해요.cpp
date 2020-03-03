#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;

void push(int num) {
	if (arr.empty()) {
		arr.push_back(num);
		cout << num << "\n";
		return;
	}
	//�̺� Ž���� Ȱ���� �ڽź��� ���� ���� ������ ã�´�.
	int low = 0, high = arr.size() - 1, mid;
	int ret = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] <= num) {
			if (ret < mid) {
				ret = mid;
			}
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	//���� �ڱ⺸�� ���� ���� 0�̶��, ���� ���� ������� Ȯ���� �Ѵ�.
	if (!ret && arr[0] > num)
		//���� ���� ���� �� �տ� num�� �����Ѵ�.
		arr.insert(arr.begin() + ret, num);
	//�Ϲ����� ����� ���� �� �ٷ� �տ� �����Ѵ�.
	else
		arr.insert(arr.begin() + ret + 1, num);
	
	//���������� �߰����� ����Ѵ�.
	if (arr.size() % 2)
		cout << arr[arr.size() / 2] << "\n";
	else
		cout << arr[arr.size() / 2 - 1] << "\n";
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, num;
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> num;
		push(num);
	}

	return 0;
}
