//#include <iostream>
//#include <algorithm>
//#include <cstring> //memset
//
//using namespace std;
//
//int N; //�ִ� 1000
//int cache[1001];
//int delay[1001]; //�ǹ� ���µ� �ɸ��� �ð�
//int order[1001][1001]; //�ǹ� ���� ����
//
//
//
//int totalTime(int destination)
//{
//	int &result = cache[destination];
//	if (result != -1)
//		return result;
//	int time = 0;
//	for (int i = 1; i <= N; i++)
//		if (order[i][destination])
//			time = max(time, totalTime(i)); //destination�� ����� ���� ���ÿ� ���� �ǹ� �� ���� �ð� ���� �ɸ��� �ǹ�
//	return result = time + delay[destination];
//}
//
//
//
//int main(void)
//{
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		int K, D, X, Y;
//		cin >> N >> K; //�ִ� �ǹ� ��, ���� ��
//		for (int j = 1; j <= N; j++)
//			cin >> delay[j];
//		memset(cache, -1, sizeof(cache));
//		memset(order, 0, sizeof(order));
//		for (int j = 0; j < K; j++)
//		{
//			cin >> X >> Y; //source, destination
//			order[X][Y] = 1;
//		}
//		cin >> D;
//		if (D < 0 || D>100000)
//			exit(-1);
//		cout << totalTime(D) << endl;
//	}
//	return 0;
//}
//
//
//
//
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//int N, K;
//int time[1002];
//int build_order[1002][1002];
//int delay[1002];
//int final_build;
//
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//
////���� ��ȹ���� ��������.
//int calc(int order) {
//	//�޸������̼��� Ȱ��.
//	int&ret = delay[order];
//	//���� ���:�̹� ����� �Ϸ�� ��� �ٷ� return
//	if (ret != -1) {
//		return ret;
//	}
//
//	int this_time = 0;
//	//�̹� �ǹ� �Ǽ��� �ɸ��� �ð��� ���� �ܰ� �ǹ��� �Ǽ��ð��� ���� ū ��
//	for (int i = 1; i <= N; i++) {
//		//order�� �Ǽ��ϱ� ���� �ʿ��� ���� �ǹ��� üũ����.
//		if (build_order[i][order]) {
//			//���� �ǹ��� �Ǽ� �ð��� üũ�Ѵ�.
//			//
//			this_time = Max(this_time, calc(i));
//		}
//	}
//
//	//���� �ܰ� �ִ� + �̹� �ǹ��� �Ǽ��ð��� ���ϸ� �ϼ��̴�.
//	return ret = this_time + time[order];
//
//}
//
//int main() {
//	int T,X,Y;
//	cin >> T;
//	while (T--) {
//		cin >> N >> K;
//		//�ʱ�ȭ�� ������.
//		memset(time, 0, sizeof(time));
//		memset(build_order, 0, sizeof(build_order));
//		//-1�� �ʱ�ȭ �ϴ� ������ �ð��� 0�� ��쵵 �ֱ� ������ -1�� ����� �Ϸ�Ǿ����� üũ�Ͽ���.
//		memset(delay, -1, sizeof(delay));
//		for (int i = 1; i <= N; i++) {
//			cin >> time[i];
//		}
//		for (int i = 0; i < K; i++) {
//			cin >> X >> Y;
//			build_order[X][Y] = 1;
//		}
//		cin >> final_build;
//		cout << calc(final_build) << endl;
//	}
//}
//
//
//
////����Ʈ�� ���� ������ Max Time�� ���� ���� �ð��� �������� ���̴�.
//
