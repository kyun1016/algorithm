////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <cmath>
////
////using namespace std;
////
////const int INF = 987654321;
//////2 3 4 5 6 7 8 9�� �Է� ���ϴ� ��쵵 ���
////const int MAX = 1000000 + 1;
////
////int N, M;
////
////vector<int> broken;
////
//////���� ä�ο��� �ٲٴ� ���
////int changeFromHundred(void)
////{
////	return abs(N - 100);
////}
////
////
////
//////�ش� ä���� ������ ���� �������� ����
//////���峭 ��ư�� ������ false
////bool possible(int num)
////{
////	if (num == 0)
////		if (find(broken.begin(), broken.end(), 0) == broken.end())
////			return true;
////		else
////			return false;
////
////	while (num)
////	{
////		if (find(broken.begin(), broken.end(), num % 10) != broken.end())
////			return false;
////		num /= 10;
////	}
////	return true;
////}
////
////
////
//////���� ä���� ����
////
////int length(int num)
////{
////	//0�̸� ���� 1(�߿��� ����ó��)
////	if (num == 0)
////		return 1;
////	int result = 0;
////	while (num)
////	{
////		num /= 10;
////		result++;
////	}
////
////	return result;
////}
////
////
////
//////100���� ������ �ƴ� ä���� ������ ���� +/-
////int changeEntirely(void)
////{
////	int result = INF;
////	int similar = 0;
////	for (int i = 0; i < MAX; i++)
////	{
////		//�ش� ä���� ���� �� �ִٸ�
////		if (possible(i))
////		{
////			int click = abs(N - i); //+/-�� �� �� �������ϴ��� Ȯ��
////			if (result > click) //�� Ŭ���ص� �ȴٸ�
////			{
////				result = click;
////				similar = i; //�ش� ���� ����
////			}
////		}
////	}
////	return result + length(similar);
////
////}
////
////
////
////int main(void)
////{
////	cin >> N >> M;
////	for (int i = 0; i < M; i++)
////	{
////		int button;
////		cin >> button;
////		broken.push_back(button);
////	}
////	cout << min(changeFromHundred(), changeEntirely()) << endl;
////	return 0;
////}
//
////���� �ٽ� ������.
//#include<iostream>
//#include<string>
//#include<stdlib.h>		//abs�� Ȱ���ϱ� ���ؼ�
//
//using namespace std;
//
//int INF = 1000007;
//int broken[10];
//
//int Min(int a, int b) {
//	return a < b ? a : b;
//}
//
//bool possible(int k) {
//	if (k == 0)
//		return broken[0] ? false : true;
//	while (k) {
//		if (broken[k % 10] == 1) {
//			return false;
//		}
//		k /= 10;
//	}
//	
//	return true;
//}
//
//int find(int N) {
//	int hundred = abs(N - 100);
//	int button_min = INF;
//	int temp;
//	for (int i = 0; i <= INF; i++) {
//		if (possible(i)) {
//			//��ư�� ���� Ƚ��
//			temp = to_string(i).length();
//			//+,-�� �ؾ��ϴ� Ƚ��
//			temp += abs(i - N);
//			//���� �̹� ����� �ּҿ��ٸ�, ��������.
//			button_min = Min(button_min, temp);
//		}
//	}
//
//	//���� Ƚ���� ���� ����� ��ȯ.
//	return Min(hundred, button_min);
//}
//
//int main(void)
//{
//	int N, M, temp;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> temp;
//		broken[temp] = 1;
//	}
//	cout << find(N) << endl;
//	return 0;
//}