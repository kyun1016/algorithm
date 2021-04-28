//#include<iostream>
//
//using namespace std;
//
//typedef unsigned long long ull;
//
//ull A, B, C;
//
//ull cache[50];
//bool visited[50];
//ull ret = 1;
//
//void calc() {
//	ull copy_A = A;
//	ull copy_B = B;
//	ull power = 0;
//	
//	while (copy_B > 1) {
//		//비트마스크의 방식을 활용해서 B에 활용되는 2진수를 찾자.
//		if (copy_B % 2)
//			visited[power] = true;
//		copy_B /= 2;
//
//		//cache[i]에 A를 1,2,4,16,64,... 곱한 값을 넣어준다.
//		cache[power] = copy_A % C;
//		copy_A *= copy_A;
//		copy_A %= C;
//
//		//power을 한차례 증가시켜준다.
//		power++;
//	}
//	visited[power] = true;
//
//	//이진수로 변경한 수에 담겨있는 값을 구해야 하는 답과 곱해준다.
//	for (int i = 0; i <= power; i++) {
//		if (visited[i]) {
//			ret *= cache[i];
//			ret %= C;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> A >> B >> C;
//	calc();
//	cout << ret;
//
//	return 0;
//}