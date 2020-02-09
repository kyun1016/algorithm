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
//
//	cin >> N >> M;
//
//	//우선 배열을 초기화
//	for (int i = 1;i <= M;i++) {
//		arr[i] = 1;
//	}
//	bool flag = false;
//	while(1) {
//		flag = true;
//		for (int i = 1;i <= M;i++) {
//			if (!flag)
//				break;
//			if (arr[i] != N)
//				flag = false;
//		}
//		for (int i = 1;i <= M;i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		if (flag)
//			break;
//		arr[M]++;
//		for (int i = M; i >= 1;i--) {
//			if (arr[i] > N) {
//				arr[i] = 1;
//				arr[i - 1]++;
//			}
//		}
//			
//	}
//	cout << endl;
//}