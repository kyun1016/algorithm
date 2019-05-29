//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MAX_SIZE = 1000;
//
//int bruteForce(const vector<int>& h) {
//	int ret = 0;
//	int N = h.size();
//	//������ ��� left, right ������ ��ȸ�Ѵ�.
//	for (int left = 0; left < N; left++) {
//		int minHeight = h[left];
//		for (int right = left; right < N; right++) {
//			minHeight = min(minHeight, h[right]);
//			ret = max(ret, (right - left + 1)*minHeight);
//		}
//	}
//	return ret;
//}
//
////�� ������ ���̸� �����ϴ� �迭
//vector<int> h;
////h[legt..right] �������� ã�Ƴ� �� �ִ� ���� ū �簢���� ���̸� ��ȯ�Ѵ�.
//int solve(int left, int right) {
//	//���� ���: ���ڰ� �ϳ��ۿ� ���� ���
//	if (left == right) return h[left];
//	//[left,min], [mid+1,right]�� �� �������� ������ �����Ѵ�.
//	int mid = (left + right) / 2;
//	//������ ������ ��������
//	int ret = max(solve(left, mid), solve(mid + 1, right));
//	//�κ� ���� 3: �� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
//	int lo = mid, hi = mid + 1;
//	int height = min(h[lo], h[hi]);
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