//#include<iostream>
//#include<string>
//#include<cstring>
//
//using namespace std;
//
//string A = "FF-MCM-";
//string B = "FC-MF";
//
//string detectBomb(const string& N) {
//	int flag = 0;
//	int MAX_SIZE = N.size();
//	for (int i = 0; i < N.size();) {
//		if (flag == 0) {
//			if (N[i] == 'F') 
//				i++;
//			else 
//				return "NOTHING!";
//
//			if(i >= MAX_SIZE)
//				return "NOTHING!";
//
//			if (N[i] == 'F') {
//				while (N[i] == 'F')
//					i++;
//				flag = 1;
//			}
//			else if (N[i] == 'C') {
//				while (N[i] == 'C')
//					i++;
//				flag = 2;
//			}
//			else	
//				return "NOTHING!";
//
//			if (i >= MAX_SIZE)
//				return "NOTHING!";
//		}
//		else if (flag == 1) {
//			if (N[i] == 'M') 
//				i++;
//			else
//				return "NOTHING!";
//
//			if (i >= MAX_SIZE)
//				return "NOTHING!";
//
//			if (N[i] == 'C') 
//				i++;
//			else
//				return "NOTHING!";
//
//			if (i >= MAX_SIZE)
//				return "NOTHING!";
//
//			if (N[i] == 'M') 
//				while (N[i] == 'M')
//					i++;
//			else
//				return "NOTHING!";
//
//			flag = 0;
//		}
//		else if(flag == 2){
//			if (N[i] == 'M')
//				i++;
//			else
//				return "NOTHING!";
//
//			if (i >= MAX_SIZE)
//				return "NOTHING!";
//
//			if (N[i] == 'F')
//				i++;
//			else
//				return "NOTHING!";
//
//			flag = 0;
//		}
//	}
//	if(flag == 0)
//		return "DETECTED!";
//
//	return "NOTHING!";
//	
//}
//
//int main(int argc, char** argv)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int test_case;
//	int T;
//	string N;
//	
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		cin >> N;
//		cout << "#" << test_case << " ";
//		cout << detectBomb(N) << endl;
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}