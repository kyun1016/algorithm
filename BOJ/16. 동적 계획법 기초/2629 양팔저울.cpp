//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//int N, arr[50], boal_arr[7];
//bool cache[50][15001];
//bool is_possible[15001];
//
//void dp(const int& here, const int& count) {
//	bool& ret = cache[here][count];
//	//�޸������̼� Ȱ��, �̹� �湮�� ���� Ž�� ����
//	if (ret)
//		return;
//	ret = true;
//	is_possible[count] = true;
//
//	if (here >= N)
//		return;
//
//	dp(here + 1, count + arr[here]);
//	dp(here + 1, count);
//	dp(here + 1, abs(count - arr[here]));
//}
//
//int main() {
//	//input
//	cin >> N;
//	for (int i = 0; i < N; i++) 
//		cin >> arr[i];
//
//	//calc
//	//�߷� ���� �� �ִ� ���Ը� ��� üũ����.
//	dp(0, 0);
//
//
//	//input 2
//	//�Է°� ���ÿ� ���ɼ� �˻�
//	cin >> N;
//	int temp;
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		if (temp > 15000)
//			cout << "N ";
//		else if (is_possible[temp])
//			cout << "Y ";
//		else
//			cout << "N ";
//	}
//
//
//	return 0;
//}