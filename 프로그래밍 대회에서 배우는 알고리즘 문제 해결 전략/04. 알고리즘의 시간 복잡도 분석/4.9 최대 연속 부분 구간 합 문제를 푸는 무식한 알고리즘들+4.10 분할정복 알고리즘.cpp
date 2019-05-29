//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MIN = numeric_limits<int>::min();
////A[]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵:O(N^3)
//int inefficientMaxSum(const vector<int>&A) {
//	int N = A.size(), ret = MIN;
//	for (int i = 0; i < N; ++i) 
//		for (int j = i; j < N; ++j) {
//			//���� A[i..j]�� ���� ���Ѵ�.
//			int sum = 0;
//			for (int k = i; k <= j; ++k)
//				sum += A[k];
//			ret = max(ret, sum);
//		}
//	return ret;
//}
//
////A[]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵:O(N^2)
//int betterMaxSum(const vector<int> & A) {
//	int N = A.size(), ret = MIN;
//	for (int i = 0; i < N; ++i) {
//		int sum = 0;
//		for (int j = i; j < N; j++) {
//			//���� A[i..j]�� ���� ���Ѵ�.
//			sum += A[j];
//			ret = max(ret, sum);
//		}
//	}
//	return ret;
//}
//
//
//
////
////4.10 �ִ뿬�� �κ� ���� �� ������ Ǫ�� ���� ���� �˰���
////
//
////A[lo..hi]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵:O(nlgn)
//int fastMaxSum(const vector<int>&A, int lo, int hi) {
//	//���� ��� : ������ ���̰� 1�� ���
//	if (lo == hi) return A[lo];
//	//�迭�� A[lo..mid], A[mid+1..hi]�� �� �������� ������.
//	int mid = (lo + hi) / 2;
//	//�� �κп� ��� ���� �ִ� �ִ� �� ������ ã�´�. �� ������
//	//A[i..mid]�� A[mid+1..j] ���¸� ���� ������ ������ �̷������.
//	//A[i.mid] ���¸� ���� �ִ� ������ ã�´�.
//	int left = MIN, right = MIN, sum = 0;
//	for (int i = mid; i >= lo; --i) {
//		sum += A[i];
//		left = max(left, sum);
//	}
//	//A[mid+1..j] ���¸� ���� �ִ� ������ ã�´�.
//	sum = 0;
//	for (int j = mid+1; j <= hi; ++j) {
//		sum += A[j];
//		right = max(right, sum);
//	}
//	//�ִ� ������ �� ���� �� �ϳ����� ���� �ִ� ����� ���� ��� ȣ��� ã�´�.
//	int single = max(fastMaxSum(A, lo, mid),
//		fastMaxSum(A, mid + 1, hi));
//	//�� ��� �� �ִ�ġ�� ��ȯ�Ѵ�.
//	return max(left + right, single);
//}
//
//
////
////�ڵ� 4.11 �ִ� ���� �κ� ���� �� ������ Ǫ�� ���� ��ȹ�� �˰���
////
//
////A[]�� ���ӵ� �κ� ������ �ִ� ���� ���Ѵ�. �ð� ���⵵: O(n)
//int fastestMaxSum(const vector<int>& A) {
//	int N = A.size(), ret = MIN, psum = 0;
//	for (int i = 0; i < N; ++i) {
//		psum = max(psum, 0) + A[i];
//		ret = max(psum, ret);
//	}
//}
//
//
//
//int main() {
//	//�Էº�
//	int x, y;
//	cout << "x�� �Է��ϼ��� : ";
//	cin >> x;
//	cout << "y�� �Է��ϼ��� : ";
//	cin >> y;
//
//	
//	//��º�
//	;
//}