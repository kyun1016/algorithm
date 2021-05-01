//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int city_Num, D;
//int Count;
//char N[600005];
//
//void buildPortal(const int& here) {
//	int right = here;
//
//	//오른쪽을 계산하자.
//	for (int i = here + 1; i <= here + D; i++) {
//		if (i >= city_Num)
//			break;
//		if (N[i * 2] == '1') {
//			right = i;
//			break;
//		}
//	}
//
//	if (right == here) {
//		if (right + D < city_Num) {
//			N[(right + D) * 2] = '1';
//			Count++;
//			buildPortal(right + D);
//		}
//	}
//	else {
//		buildPortal(right);
//	}
//}
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int test_case;
//	int T;
//	
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		cin >> city_Num >> D;
//		cin.getline(N, city_Num * 2 + 3, '\n');
//		cin.getline(N, city_Num * 2 + 3, '\n');
//		cin.clear();
//		Count = 0;
//		if (N[0] == '0') {
//			Count++;
//			N[0] = '1';
//		}
//		if (N[(city_Num - 1) * 2] == '0') {
//			Count++;
//			N[(city_Num - 1) * 2] = '1';
//		}
//		buildPortal(0);
//		cout << "#" << test_case << " " << Count << endl;
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}