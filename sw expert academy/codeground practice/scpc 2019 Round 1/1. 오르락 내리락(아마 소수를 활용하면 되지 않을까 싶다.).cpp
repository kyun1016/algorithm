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
////비트마스크를 활용하자. 5는 8에서 3이 부족한데, 3은 이진수로 11, 즉 3 + 2
//// 6은 8에서 2가 부족한데, 2는 2진수로 10, 3+1
//// 7은 8에서 1이 부족한데, 1은 2진수로 1, 3+1
////8은 2의 배수로, 3
//void calc() {
//	for (int i = 1; i <= 1000000; i++) {
//		int count = 0;
//		for (count; count < 21; count++) {
//			if (i < Arr[count])
//				break;
//		}
//		//이게 2의 n제곱수면 바로 더해주자.
//		if (i == Arr[count - 1]) {
//			count--;
//			Solve[i] = count + Solve[i - 1];
//			continue;
//		}
//		//이진수를 활용하도록 하자.
//		int binary = Arr[count] - i;
//		int temp = binary;
//		int temp_2 = count;
//		//이전에 찾은 이진수가 있다면, 그것을 활용하자.
//		if (visited[binary])
//			count += bi[binary];
//		else {
//			//이제 새로 찾은 이진수로 등록해주자.
//			visited[binary] = true;
//			while (binary) {
//				if (binary % 2 == 1) {
//					count++;
//				}
//				binary /= 2;
//				//여기서도 활용.
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
//	//미리 전처리를 해주자.
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