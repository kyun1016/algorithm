//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
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
//	return ret;
//}
//
//int main() {
//	/*int N;
//	scanf("%d", &N);
//	for (int i = 1; i <= N; i++){
//		scanf("%d", &cache[i]);
//
//		if (cache[i - 1] + cache[i] > cache[i])
//			cache[i] += cache[i - 1];
//
//		if (cache[i] > MAX)
//			MAX = cache[i];
//	}
//
//	printf("%d\n", MAX);*/				//2019.04.25 1�� ����
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	int n,temp;
//	vector<int> arr;
//	cin >> n;
//	while (n--) {
//		cin >> temp;
//		arr.push_back(temp);
//	}
//	cout << fastestMaxSum(arr) << endl;
//}
////
////�� �ڿ������� cache�� �����
////�ڱ���� ������ ���ϴµ�, cache[i]�� �ڱ���� ������ ���� �ִ�ũ��
////���� cache[]�� ������ ������ stop�ϵ���
////���ڵ� ���� �غ���.