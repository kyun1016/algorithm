//#include<iostream>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//ull A, B, C;
//
//ull cache[50];
//bool visited[50];
//ull ret = 1;
//
//void calc() {
//	ull copy_A = A;
//	ull copy_B = B;
//	ull power = 0;
//	
//	while (copy_B > 1) {
//		//��Ʈ����ũ�� ����� Ȱ���ؼ� B�� Ȱ��Ǵ� 2������ ã��.
//		if (copy_B % 2)
//			visited[power] = true;
//		copy_B /= 2;
//
//		//cache[i]�� A�� 1,2,4,16,64,... ���� ���� �־��ش�.
//		cache[power] = copy_A % C;
//		copy_A *= copy_A;
//		copy_A %= C;
//
//		//power�� ������ ���������ش�.
//		power++;
//	}
//	visited[power] = true;
//
//	//�������� ������ ���� ����ִ� ���� ���ؾ� �ϴ� ��� �����ش�.
//	for (int i = 0; i <= power; i++) {
//		if (visited[i]) {
//			ret *= cache[i];
//			ret %= C;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> A >> B >> C;
//	calc();
//	cout << ret;
//
//	return 0;
//}