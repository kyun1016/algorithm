//#include<iostream>
//
//using namespace std;
//
//int N, ret = 1000000007;
//int arr[21][21];
//bool visited[21];
//
//void matching(int num, int pos) {
//	if (num == N / 2) {
//		//a,b에는 각 팀의 능력치를 저장한다.
//		int a = 0, b = 0;
//		for (int i = 0;i < N;i++) {
//			//a팀은 visited==true인 팀이다.
//			if (visited[i]) {
//				for (int j = i + 1;j < N;j++)
//					//팀원간의 상호작용 능력치 합을 오름차순을 활용해 더해준다.
//					if (visited[j])
//						a += arr[i][j] + arr[j][i];
//			}
//			else {
//				for (int j = i + 1;j < N;j++)
//					if (!visited[j])
//						b += arr[i][j] + arr[j][i];
//			}
//		}
//		//각 팀의 능력치 차를 더해준다.
//		if (ret > abs(a - b))
//			ret = abs(a - b);
//	}
//	else if (N - pos < N/2 - num)
//		return;
//	else {
//		for (int i = pos;i < N;i++) {
//			visited[i] = true;
//			matching(num + 1, i + 1);
//			visited[i] = false;
//		}
//	}
//}
//
//int main() {
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	cin >> N;
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < N;j++)
//			cin >> arr[i][j];
//
//	matching(0, 0);
//
//	cout << ret;
//}