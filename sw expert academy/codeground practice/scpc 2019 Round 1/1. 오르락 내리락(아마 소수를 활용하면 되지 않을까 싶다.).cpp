//#include <iostream>
//#include<string>
//
//using namespace std;
//typedef unsigned long long ull;
//
//
//int Answer;
//int Arr[21];
//
//int Solve[1000001];
//int bi[1000001];
//bool visited[1000001];
//
//void inputArr() {
//	ull a = 1;
//	for (int i = 0; i < 21; i++) {
//		Arr[i] = a;
//		a *= 2;
//	}
//}
//
//
////��Ʈ����ũ�� Ȱ������. 5�� 8���� 3�� �����ѵ�, 3�� �������� 11, �� 3 + 2
//// 6�� 8���� 2�� �����ѵ�, 2�� 2������ 10, 3+1
//// 7�� 8���� 1�� �����ѵ�, 1�� 2������ 1, 3+1
////8�� 2�� �����, 3
//void calc() {
//	for (int i = 1; i <= 1000000; i++) {
//		int count = 0;
//		for (count; count < 21; count++) {
//			if (i < Arr[count])
//				break;
//		}
//		//�̰� 2�� n�������� �ٷ� ��������.
//		if (i == Arr[count - 1]) {
//			count--;
//			Solve[i] = count + Solve[i - 1];
//			continue;
//		}
//		//�������� Ȱ���ϵ��� ����.
//		int binary = Arr[count] - i;
//		int temp = binary;
//		int temp_2 = count;
//		//������ ã�� �������� �ִٸ�, �װ��� Ȱ������.
//		if (visited[binary])
//			count += bi[binary];
//		else {
//			//���� ���� ã�� �������� ���������.
//			visited[binary] = true;
//			while (binary) {
//				if (binary % 2 == 1) {
//					count++;
//				}
//				binary /= 2;
//				//���⼭�� Ȱ��.
//				if (visited[binary]) {
//					count += bi[binary];
//					break;
//				}
//			}
//			bi[temp] = count - temp_2;
//		}
//		Solve[i] = count + Solve[i - 1];
//	}
//
//}
//
//
////void thisNum(int N) {
////	string a;
////	while (N) {
////		a.push_back((N % 2) + '0');
////		N /= 2;
////	}
////	reverse(a.begin(), a.end());
////	cout << a << endl;
////}
//
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int T, test_case, N1, N2;
//
//	//�̸� ��ó���� ������.
//	inputArr();
//	calc();
//
//	cin >> T;
//	
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		cin >> N1 >> N2;
//		Answer = Solve[N2] - Solve[N1 - 1];
//
//		cout << "Case #" << test_case + 1 << "\n";
//		cout << Answer << "\n";
//	}
//
//	return 0;
//}