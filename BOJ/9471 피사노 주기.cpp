//#include<iostream>
//
//using namespace std;
//
//
//
//int fisano_period(int m) {
//	int count = 0, m1 = 0, m2 = 1;
//	do {
//		int temp = m1;
//		m1 = m2;
//		m2 = (temp + m1) % m;
//		count++;
//	} while (m1 != 0 || m2 != 1);	//0,1�� ���´ٴ� ���� �ֱⰡ �ݺ��ȴٴ� ���̴�.
//
//	//���ݱ��� ���̸� ��ȯ�Ѵ�.
//	return count;
//}
//
//
//int main() {
//	int P, N, M;
//	cin >> P;
//	for (int i = 0; i < P; i++) {
//		cin >> N >> M;
//		cout << N << " " << fisano_period(M) << endl;
//	}
//}