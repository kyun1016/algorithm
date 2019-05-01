//#include<iostream>
//#include<list>
//using namespace std;
//
//void josephus(int n, int k) {
//	cout << "<";
//	std::list<int> survivors;
//	for (int i = 1; i <= n; i++) survivors.push_back(i);
//	//이번에 죽을 사람을 나타내는 포인터
//	std::list<int>::iterator kill = survivors.begin();
//	for (int i = 1; i < k; i++) {
//		kill++;
//	}
//	while (n > 1) {
//		//첫째 사람이 자살한다. erase()는 지운 원소의 다음 원소를 반환한다.
//		--n;
//		cout << *kill <<", ";
//		kill = survivors.erase(kill);
//		if (kill == survivors.end()) kill = survivors.begin();
//	
//		//k-1번 다음 사람으로 옮긴다.
//		for (int i = 0; i < k - 1; ++i) {
//			++kill;
//			if (kill == survivors.end()) kill = survivors.begin();
//		}
//		if (n <= 1) break;
//	}
//	cout << *kill << ">\n";
//}
//
//int main() {
//	int n, k;
//	std::cin >> n >> k;
//
//	josephus(n, k);
//}