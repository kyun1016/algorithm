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
	//이분 탐색을 활용해 자신보다 작은 수의 개수를 찾는다.
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

	//만일 자기보다 작은 수가 0이라면, 가장 작은 경우인지 확인을 한다.
	if (!ret && arr[0] > num)
		//가장 작은 경우는 맨 앞에 num을 삽입한다.
		arr.insert(arr.begin() + ret, num);
	//일반적인 경우라면 작은 수 바로 앞에 삽입한다.
	else
		arr.insert(arr.begin() + ret + 1, num);
	
	//최종적으로 중간값을 출력한다.
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
