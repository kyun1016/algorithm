////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <cmath>
////
////using namespace std;
////
////const int INF = 987654321;
//////2 3 4 5 6 7 8 9를 입력 못하는 경우도 고려
////const int MAX = 1000000 + 1;
////
////int N, M;
////
////vector<int> broken;
////
//////현재 채널에서 바꾸는 경우
////int changeFromHundred(void)
////{
////	return abs(N - 100);
////}
////
////
////
//////해당 채널을 누르는 것이 가능한지 여부
//////고장난 버튼을 누르면 false
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
//////누른 채널의 길이
////
////int length(int num)
////{
////	//0이면 길이 1(중요한 예외처리)
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
//////100에서 시작이 아닌 채널을 누르고 나서 +/-
////int changeEntirely(void)
////{
////	int result = INF;
////	int similar = 0;
////	for (int i = 0; i < MAX; i++)
////	{
////		//해당 채널을 누를 수 있다면
////		if (possible(i))
////		{
////			int click = abs(N - i); //+/-을 몇 번 눌러야하는지 확인
////			if (result > click) //덜 클릭해도 된다면
////			{
////				result = click;
////				similar = i; //해당 숫자 저장
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
////내가 다시 만들어보자.
//#include<iostream>
//#include<string>
//#include<stdlib.h>		//abs를 활용하기 위해서
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
//			//버튼을 누른 횟수
//			temp = to_string(i).length();
//			//+,-를 해야하는 횟수
//			temp += abs(i - N);
//			//만일 이번 계산이 최소였다면, 저장하자.
//			button_min = Min(button_min, temp);
//		}
//	}
//
//	//가장 횟수가 적은 방법을 반환.
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