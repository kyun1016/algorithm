//#include<iostream>
//
//using namespace std;
//
//int arr[9];
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int N, M;
//	int count;
//
//	cin >> N >> M;
//
//	//�켱 �迭�� �ʱ�ȭ
//	for (int i = 1;i <= M;i++) {
//		arr[i] = 1;
//	}
//	bool flag = false;
//	while (1) {
//		//�迭�� ��� ���� N�� �Ǹ� �ݺ����� Ż��
//		flag = true;
//		for (int i = 1;i <= M;i++) {
//			if (!flag)
//				break;
//			if (arr[i] != N)
//				flag = false;
//		}
//		
//		//������ ���
//		for (int i = 1;i <= M;i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//
//		if (flag)
//			break;
//
//		//���� ���������ش�.
//		arr[M]++;
//
//		//�ø��� �߻��ϴ� ���� ó��
//		if (arr[M] > N) {
//			count = 1;
//			//�̶�, ������������ �迭�� �̷�������ϱ⿡ Ư���ϰ� ó�����־���.
//			for (int i = M-1;i >= 1;i--) {
//				if (arr[i] == N) {
//					count++;
//				}
//				else
//					break;
//			}
//			arr[M - count]++;
//			for (int i = 0;i < count;i++) {
//				arr[M - i] = arr[M - count];
//			}
//		}
//
//	}
//	cout << endl;
//}