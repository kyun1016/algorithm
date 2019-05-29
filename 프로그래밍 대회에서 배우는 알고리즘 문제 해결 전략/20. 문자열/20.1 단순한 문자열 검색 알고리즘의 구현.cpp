//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
////'¤���� H�� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�.
//vector<int> naiveSearch(const string& H, const string& N) {
//	vector<int> ret;
//	//��� ���� ��ġ�� �� �õ��� ����.
//	for (int begin = 0; begin + N.size() <= H.size(); begin++) {
//		bool matched = true;
//		for(int i=0;i<N.size();i++)
//			if (H[begin + 1] != N[i]) {
//				matched = false;
//				break;
//			}
//		if (matched) ret.push_back(begin);
//	}
//	return ret;
//}
//
//
//////�ڵ� 20.3 �ܼ��� ���ڿ� �˰����� �̿��� �κ� ��ġ ���̺� ����ϱ�
////N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿���
////pi[]�� ����Ѵ�.
////pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
//vector<int> getPartialMatchNaive(const string& N) {
//	int m = N.size();
//	vector<int> pi(m, 0);
//	//�ܼ��� ���ڿ� �˻� �˰����� �����Ѵ�.
//	for (int begin = 1; begin < m; begin++) {
//		for (int i = 0; i + begin < m; i++) {
//			if (N[begin + i] != N[i])
//				break;
//			//i+1 ���ڰ� ���� �����Ǿ���.
//			pi[begin + i] = max(pi[begin + i], i + 1);
//		}
//	}
//	return pi;
//}
//
//vector<int> getPartialMatch(const string& N) {
//	int m = N.size();
//	vector<int> pi(m, 0);
//	//KMP�� �ڱ� �ڽ��� ã�´�.
//	//N�� N���� ã�´�. begin=0�̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵ�!
//	int begin = 1, matched = 0;
//	//���� ���ڰ� N�� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ����Ѵ�.
//	while (begin + matched < m) {
//		if (N[begin + matched] == N[matched]) {
//			matched++;
//			pi[begin + matched - 1] = matched;
//		}
//		else {
//			if (matched == 0)
//				begin++;
//			else {
//				begin += matched - pi[matched - 1];
//				matched = pi[matched - 1];
//			}
//		}
//	}
//	return pi;
//}
//
//
//////�ڵ� 20.2 Ŀ����-�𸮽�-����(Knuth-Morris-Pratt) ���ڿ� �˻� �˰����� ����
//
////'¤����'H�� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ���� ��ġ���� ��ι�ȯ�Ѵ�.
//vector<int> kmpSearch(const string& H, const string& N) {
//	int n = H.size(), m = N.size();
//	vector<int> ret;
//	//pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
//	vector<int> pi = getPartialMatch(N);
//
//	//begin=matched=0�������� ��������.
//	int begin = 0, matched = 0;
//	while (begin <= n - m) {
//		//���� ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
//		if (matched < m && H[begin + matched] == N[matched]) {
//			++matched;
//			//��������� m���ڰ� ��� ��ġ�ߴٸ� �信 �߰��Ѵ�.
//			if (matched == m) ret.push_back(begin);
//		}
//		else {
//			//����: matched�� 0�� ��쿡�� ���� ĭ�������� ���
//			if (matched == 0)
//				begin++;
//			else {
//				begin += matched - pi[matched - 1];
//				//begin�� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����.
//				//�ű� ������ pi[matched-1]��ŭ�� �׻� ��ġ�ϱ� �����̴�.
//				matched = pi[matched - 1];
//			}
//		}
//	}
//
//	return ret;
//
//}
//
//
//
//////�ڵ� 20.7 KMP �˰����� �ٸ� ����
//
//vector<int> kmpSearch2(const string& H, const string& N) {
//	int n = H.size(), m = N.size();
//	vector<int> ret;
//	vector<int> pi = getPartialMatch(N);
//	//���� ������ ������ ��
//	int matched = 0;
//	//¤������ �� ���ڸ� ��ȸ�Ѵ�.
//	for (int i = 0; i < n; i++) {
//		//matched�� ���ڿ� ¤������ �ش� ���ڰ� ����ġ�� ���,
//		//���� ������ ������ ���� pi[matched-1]�� ���δ�.
//		while (matched > 0 && H[i] != N[matched])
//			matched = pi[matched - 1];
//		//���ڰ� ������ ���
//		if (H[i] == N[matched - 1]) {
//			matched++;
//			if (matched == m) {
//				ret.push_back(i - m + 1);
//				matched = pi[matched - 1];
//			}
//		}
//	}
//	return ret;
//}
//
//
