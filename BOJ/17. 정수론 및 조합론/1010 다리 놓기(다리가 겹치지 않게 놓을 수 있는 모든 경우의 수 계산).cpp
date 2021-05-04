#include<iostream>
   
using namespace std;

int N, M, T;

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int cache[30][30] = { 0 };
		//������� 1���� ���, �� �ݴ��� ������ �����Ǵ� ����� ��
		for (int b_num = 1; b_num <= M; b_num++)
			cache[1][b_num] = b_num;
		
		//������� 2~N���� ��, �� �ݴ��� ������ �����Ǵ� ����� ��
		for (int a_num = 2; a_num <= N; a_num++)
			for (int b_num = a_num; b_num <= M; b_num++)
				for (int k = 1; k < b_num; k++)
					cache[a_num][b_num] += cache[a_num - 1][k];
		
		cout << cache[N][M] << endl;
	}

	return 0;
}