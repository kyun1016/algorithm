//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
////first = Ÿ��Ʋ ����, second.first = �ʿ� ���ط�, second.second = �ʿ� ��ȭ��
//vector<pair<int, pair<int, int> > > restaurant;
//pair<int, int> ablity;
//int Count;
//int Score;
//
//int countScore(const int& N) {
//	int ret = Count;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int T, N;
//	int a, b, c;
//	cin >> T;
//	//���� �ʱ�ȭ
//	while (!restaurant.empty())
//		restaurant.pop_back();
//	Count = 0;
//	Score = 0;
//	for (int i = 1; i <= T; i++) {
//		cin >> N;
//		for (int j = 0; j < N; j++) {
//			cin >> a >> b >> c;
//			if (a == 1 || b == 1) {
//				Count++;
//				Score += c;
//			}
//			else
//				restaurant.push_back({ c, {a,b} });
//		}
//		
//		cout << "#" << i << " " << countScore(N) << "\n";
//	}
//	return 0;
//}