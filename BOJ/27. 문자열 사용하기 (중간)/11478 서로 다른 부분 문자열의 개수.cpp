#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

const int MAX = 1001;

string S;
int suffixArray[MAX], pos[MAX], LCPArray[MAX];
int temp[MAX];
int T, N;

bool cmp(int i, int j) {
	//���� �ڽ��� ��ġ�� ���ڸ� ��
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	//���ڰ� ������ Tĭ ���� ���ڳ��� ��
	i += T;
	j += T;
	return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

//S�� ����� suffixArray�� ����� �Լ�
void constructSuffixArray() {
	N = S.size();
	for (int i = 0; i < N; i++) {
		suffixArray[i] = i;
		pos[i] = S[i];
	}
	//T�� 2�辿 �÷����鼭 �Ź� �տ��� ���� T*2���ڸ� ���� ���̻� ����
	for (T = 1; T <=N; T *= 2) {
		sort(suffixArray, suffixArray + N, cmp);
		temp[0] = 0;
		//�տ������� �����鼭 �� ���̻簡 ���� �ٸ� �׷쿡 ���� ������ �׷� ��ȣ ����
		for (int i = 0; i < N - 1; i++)
			temp[i + 1] = temp[i] + cmp(suffixArray[i], suffixArray[i + 1]);
		//pos�迭�� temp�迭�� ��ü
		for (int i = 0; i < N; i++)
			pos[suffixArray[i]] = temp[i];

		//��� ���̻簡 �ٸ� �׷����� ���������ٸ� ����
		if (temp[N - 1] == (N - 1))
			break;
	}
}

void makeLCPArray() {
	int N = S.size();
	for (int i = 0, k=0; i < N; i++, k = max(k-1, 0)) {
		//�迭 �� ������ ��ġ�� ���ڴ� ��� �Ұ�
		if (pos[i] == N - 1) continue;
		
		for (int j = suffixArray[pos[i] + 1]; S[i + k] == S[j + k]; k++);
		LCPArray[pos[i]] = k;
	}
}




int main() {
	cin >> S;
	constructSuffixArray();
	int ret = 0;
	for (int i = 0; i < N; i++)
		ret += suffixArray[i] + 1;
	makeLCPArray();
	for (int i = 0; i < N - 1; i++)
		ret -= LCPArray[i];
	cout << ret;
}