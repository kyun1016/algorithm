//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
////ó���� ������ ���ڵ��� ������ seed�� ������.
//vector<int> mod;
//
//int append(int here, int edge, int mod) {
//	int there = here * 10 + edge;
//	if (there >= mod)
//		return mod + there % mod;
//	return there % mod;
//}
////digit�� ���� ���ڵ鸸���� �����ǰ�,
////C mod n == m�� �ּ��� C�� ã�´�.
//string gifts(string digits, int n, int m) {
//	//������ ��ȣ�� ������������ ������ �θ� ���������� ���� �տ�
//	//�ִ� ��θ� ã�� �� �ִ�.
//	sort(digits.begin(), digits.end());
//	//��� ���� i�� 0 ~ n-1, ȸ�� ���� i�� n~ 2n-1�� ǥ���Ѵ�.
//	//parent[i]=BFS ���д� Ʈ������ ���� i�� �θ�
//	//choice[i]=parent[i]���� i�� ����� ������ ��ȣ
//	vector<int> parent(2 * n, -1), choice(2 * n, -1);
//	queue<int> q;
//	//��� 0���� ť�� �߰�
//	parent[0] = 0;
//	q.push(0);
//	while (!q.empty()) {
//		int here = q.front();
//		q.pop();
//		for (int i = 0; i < digits.size(); i++) {
//			//���� digits[i]-'0'�� ���� ����.
//			int there = append(here, digits[i] - '0', n);
//			if (parent[there] == -1) {
//				parent[there] = here;
//				choice[there] = digits[i] - '0';
//				q.push(there);
//			}
//		}
//	}
//	//ȸ�� m���� �������� �������� ����!
//	if (parent[n + m] == -1) return "IMPOSSIBEL";
//	//�θ�� ���� ������ ���󰡸鼭 C�� ����Ѵ�.
//	string ret;
//	int here = n + m;
//	while (parent[here] != here) {
//		ret += char('0' + choice[here]);
//		here = parent[here];
//	}
//	reverse(ret.begin(), ret.end());
//	return ret;
//}
//
//
//
