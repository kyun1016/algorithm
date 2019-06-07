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
	//먼저 자신의 위치의 문자를 비교
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	//문자가 같으면 T칸 뒤의 문자끼리 비교
	i += T;
	j += T;
	return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

//S를 사용해 suffixArray를 만드는 함수
void constructSuffixArray() {
	N = S.size();
	for (int i = 0; i < N; i++) {
		suffixArray[i] = i;
		pos[i] = S[i];
	}
	//T를 2배씩 늘려가면서 매번 앞에서 부터 T*2글자만 보고 접미사 정렬
	for (T = 1; T <=N; T *= 2) {
		sort(suffixArray, suffixArray + N, cmp);
		temp[0] = 0;
		//앞에서부터 훑으면서 각 접미사가 서로 다른 그룹에 속할 때마다 그룹 번호 증가
		for (int i = 0; i < N - 1; i++)
			temp[i + 1] = temp[i] + cmp(suffixArray[i], suffixArray[i + 1]);
		//pos배열을 temp배열로 대체
		for (int i = 0; i < N; i++)
			pos[suffixArray[i]] = temp[i];

		//모든 접미사가 다른 그룹으로 나뉘어졌다면 종료
		if (temp[N - 1] == (N - 1))
			break;
	}
}

void makeLCPArray() {
	int N = S.size();
	for (int i = 0, k=0; i < N; i++, k = max(k-1, 0)) {
		//배열 중 마지막 위치의 문자는 계산 불가
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