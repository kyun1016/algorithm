//#include<iostream>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//int N;
//ull B;
//int matrix[6][6];
//int temp[6][6];
//int cache[50][6][6];
//bool visited[50];
//int ret[6][6];
//
//void calc() {
//	int power = 0;
//	while (B > 1) {
//		//B를 2진수로 변환하여 변환되는 2진수 부분을 visited배열에 저장해주었다.
//		if (B % 2)
//			visited[power] = true;
//
//		//temp행렬을 초기화해준다.
//		for (int y = 0; y < N; y++) {
//			for (int x = 0; x < N; x++) {
//				temp[y][x] = 0;
//			}
//		}
//
//		//행렬을 2^power번 제곱한 값을 cache에 미리 저장 해주었다.(B의 크기가 100,000,000,000 이하이므로 power가 40을 넘지 않는다.)
//		//행렬을 제곱한 값을 temp에 담아준다.
//		for (int bra = 0; bra < N; bra++) {
//			for (int ket = 0; ket < N; ket++) {
//				for (int i = 0; i < N; i++) {
//					temp[bra][ket] += cache[power][bra][i] * cache[power][i][ket];
//					temp[bra][ket] %= 1000;
//				}
//			}
//		}
//
//		//지수를 증가시켜주고, cache에 temp의 값을 옮겨 담아주었다.
//		power++;
//		for (int y = 0; y < N; y++) {
//			for (int x = 0; x < N; x++) {
//				cache[power][y][x] = temp[y][x];
//			}
//		}
//
//		B /= 2;
//	}
//	visited[power] = true;
//
//	//ret행렬을 단위행렬로 만들어준다.
//	for (int i = 0; i < N; i++) {
//		ret[i][i] = 1;
//	}
//
//	for (int i = 0; i <= power; i++) {
//		if (visited[i]) {
//			//temp행렬을 초기화해준다.
//			for (int y = 0; y < N; y++) {
//				for (int x = 0; x < N; x++) {
//					temp[y][x] = 0;
//				}
//			}
//
//			//ret과 cache를 곱해준다.
//			for (int bra = 0; bra < N; bra++) {
//				for (int ket = 0; ket < N; ket++) {
//					for (int j = 0; j < N; j++) {
//						temp[bra][ket] += ret[bra][j] * cache[i][j][ket];
//						temp[bra][ket] %= 1000;
//					}
//				}
//			}
//			for (int y = 0; y < N; y++) {
//				for (int x = 0; x < N; x++) {
//					ret[y][x] = temp[y][x];
//				}
//			}
//		}
//	}
//
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cout << ret[y][x] << " ";
//		}
//		cout << "\n";
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> B;
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cin >> matrix[y][x];
//			cache[0][y][x] = matrix[y][x];
//		}
//	}
//
//	calc();
//
//	return 0;
//}