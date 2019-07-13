#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];
int cache[100001][5][5];
int K;
const int INF = 1000000007;

int dp(const int& N = 0, const int& left = 0, const int& right = 0) {
	//���� ��� : ������ ��� ���
	if (N == K)
		return 0;
	//�޸������̼� Ȱ��
	int& ret = cache[N][left][right];
	//���� ��� : �̹� ����� ���� ���
	if (ret != 0)
		return ret;

	ret = INF;
	int next = arr[N];

	//���� ���� �����̴� ���
	if (left == next) 
		ret = min(dp(N + 1, left, right) + 1, ret);
	else if (next != right) 
		if (left == 0) 
			ret = min(dp(N + 1, next, right) + 2, ret);
		else 
			if (abs(left - next) == 1 || abs(left - next) == 3) 
				ret = min(dp(N + 1, next, right) + 3, ret);
			else 
				ret = min(dp(N + 1, next, right) + 4, ret);

	//������ ���� �����̴� ���
	if (right == next) 
		ret = min(dp(N + 1, left, right) + 1, ret);
	else if (next != left) 
		if (right == 0) 
			ret = min(dp(N + 1, left, next) + 2, ret);
		else 
			if (abs(right - next) == 1 || abs(right - next) == 3) 
				ret = min(dp(N + 1, left, next) + 3, ret);	
			else 
				ret = min(dp(N + 1, left, next) + 4, ret);
			

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int temp;

	while (1) {
		cin >> temp;
		if (temp == 0)
			break;
		arr[K++] = temp;
	}

	cout << dp() << endl;


	return 0;
}