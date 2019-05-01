//#include<iostream>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//int ret[3];
//char arr[20000];
//std::string trim_arr[2200];
//
//void cut(int y, int x, int yy, int xx) {
//	int flag = 0;
//	char find = trim_arr[y].at(x);
//	if (x == xx) {
//		ret[find - '0']++;
//		flag++;
//	}
//	else {
//		int temp = (yy - y + 1) / 3;
//		for (int i = y; i < yy; i++) {
//			for (int j = x; j < xx; j++) {
//				//만일 같지 않은 숫자가 나오면, 9조각으로 나눠 자른다.				
//				if (find != trim_arr[i].at(j) && flag == 0) {
//					cut(y, x, y + temp - 1, x + temp - 1);
//					cut(y, x + temp, y + temp - 1, x + temp * 2 - 1);
//					cut(y, x + temp * 2, y + temp - 1, x + temp * 3 - 1);
//
//					cut(y + temp, x, y + temp * 2 - 1, x + temp - 1);
//					cut(y + temp, x + temp, y + temp * 2 - 1, x + temp * 2 - 1);
//					cut(y + temp, x + temp * 2, y + temp * 2 - 1, x + temp * 3 - 1);
//
//					cut(y + temp * 2, x, y + temp * 3 - 1, x + temp - 1);
//					cut(y + temp * 2, x + temp, y + temp * 3 - 1, x + temp * 2 - 1);
//					cut(y + temp * 2, x + temp * 2, y + temp * 3 - 1, x + temp * 3 - 1);
//					flag++;
//				}
//			}
//		}
//	}
//	if (flag == 0) {
//		ret[find - '0']++;
//	}
//}
//
//std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to) {
//	size_t start_pos = 0; //string처음부터 검사
//	while ((start_pos = str.find(from, start_pos)) != std::string::npos)  //from을 찾을 수 없을 때까지
//	{
//		str.replace(start_pos, from.length(), to);
//		start_pos += to.length(); // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
//	}
//	return str;
//}
//
//int main() {
//	int N;
//	std::cin >> N;
//	for (int y = 0; y <= N; y++) {
//		//공백을 포함하여 입력받는다.
//		std::cin.getline(arr, 8000);
//		trim_arr[y] = arr;
//		//공백을 제거하자.
//		trim_arr[y].erase(std::remove(trim_arr[y].begin(), trim_arr[y].end(), ' '), trim_arr[y].end());
//		//-1을 2로 교체하자.
//		ReplaceAll(trim_arr[y], string("-1"), string("2"));
//	}
//
//	cut(1, 0, N, N - 1);
//	cout << ret[2] << "\n" << ret[0] << "\n" << ret[1] << endl;
//
//	return 0;
//}
//
////#include<iostream>
////
////using namespace std;
////
////int num[2200][2200];
////int ret[3];
////
////bool check(int y, int x, int N) {
////	int find = num[y][x];
////	for (int i = y; i < y + N; i++)
////		for (int j = x; j < x + N; j++)
////			if (find != num[i][j])
////				return false;
////	return true;
////}
////
////
////int divide(int y, int x, int N) {
////	if (check(y, x, N)) {
////		ret[num[y][x]]++;
////	}
////	//만일 모든 수가 동일하지 않다면, 9등분으로 나눠준다.
////	else {
////		int size = N / 3;
////		for (int i = 0; i < 3; i++) {
////			for (int j = 0; j < 3; j++) {
////				divide(y + size * i, x + size * j, size);
////			}
////		}
////	}
////	return 0;
////}
////
////int main() {
////	int N;
////	cin >> N;
////	for (int y = 1; y <= N; y++) {
////		for (int x = 1; x <= N; x++) {
////			cin >> num[y][x];
////			num[y][x] += 1;
////		}
////	}
////
////	divide(1, 1, N);
////	cout << ret[0] << "\n" << ret[1] << "\n" << ret[2];
////}