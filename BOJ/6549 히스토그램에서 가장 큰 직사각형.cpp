//#include<vector>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
////�� ������ ���̸� �����ϴ� �迭
//vector<long long> h;
////h[legt..right] �������� ã�Ƴ� �� �ִ� ���� ū �簢���� ���̸� ��ȯ�Ѵ�.
//long long solve(int left, int right) {
//	//���� ���: ���ڰ� �ϳ��ۿ� ���� ���
//	if (left == right) return h[left];
//	//[left,min], [mid+1,right]�� �� �������� ������ �����Ѵ�.
//	int mid = (left + right) / 2;
//	//������ ������ ��������
//	long long ret = max(solve(left, mid), solve(mid + 1, right));
//	//�κ� ���� 3: �� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
//	long long lo = mid, hi = mid + 1;
//	long long height = min(h[lo], h[hi]);
//	//[mid,mid+1]�� �����ϴ� �ʺ� 2�� �簢���� ����Ѵ�.
//	ret = max(ret, height * 2);
//	//�簢���� �Է� ��ü�� ���� ������ Ȯ���� ������.
//	while (left < lo || hi < right) {
//		//�׻� ���̰� �� ���� ������ Ȯ���Ѵ�.
//		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
//			++hi;
//			height = min(height, h[hi]);
//		}
//		else {
//			--lo;
//			height = min(height, h[lo]);
//		}
//		//Ȯ���� �� �簢���� ����
//		ret = max(ret, height * (hi - lo + 1));
//	}
//	return ret;
//}
//
//int main() {
//	int N,temp;
//	cin >> N;
//	while (N) {
//		h.clear();
//		for (int i = 0; i < N; i++) {
//			cin >> temp;
//			h.push_back(temp);
//		}
//		cout << solve(0, N - 1) << endl;
//		cin >> N;
//	}
//}