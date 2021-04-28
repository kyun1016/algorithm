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
//	//우선 배열을 초기화
//	for (int i = 1;i <= M;i++) {
//		arr[i] = 1;
//	}
//	bool flag = false;
//	while (1) {
//		//배열의 모든 수가 N이 되면 반복문을 탈출
//		flag = true;
//		for (int i = 1;i <= M;i++) {
//			if (!flag)
//				break;
//			if (arr[i] != N)
//				flag = false;
//		}
//		
//		//데이터 출력
//		for (int i = 1;i <= M;i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//
//		if (flag)
//			break;
//
//		//수를 증가시켜준다.
//		arr[M]++;
//
//		//올림이 발생하는 것을 처리
//		if (arr[M] > N) {
//			count = 1;
//			//이때, 오름차순으로 배열이 이루어져야하기에 특수하게 처리해주었다.
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