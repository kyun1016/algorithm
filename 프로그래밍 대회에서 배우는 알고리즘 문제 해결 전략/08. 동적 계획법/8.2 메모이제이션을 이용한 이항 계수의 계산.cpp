//#include<iostream>
//
//using namespace std;
//
//int cache[30][30];
//
//int bino2(int n, int r) {
//	//기저 사례:n=r(모든 원소를 다 고르는 경우) 혹은 r=0(고를 원소가 없는 경우)
//	if (r == 0 || n == r) return 1;
//	//-1이 아니면 한번 계산했던 값이니 곧장 반환
//	if (cache[n][r] != -1)
//		return cache[n][r];
//	//직접 계산한 뒤 배열에 저장
//	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
//}
//
//int main() {
//	int n, r;
//	cout << "n을 입력하세요 : ";
//	cin >> n;
//	cout << "r을 입력하세요 : ";
//	cin >> r;
//	cout << bino2(n, r);
//}