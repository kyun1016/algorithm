//#include<iostream>
//#include<list>
//using namespace std;
//
//void josephus(int n, int k) {
//	cout << "<";
//	std::list<int> survivors;
//	for (int i = 1; i <= n; i++) survivors.push_back(i);
//	//�̹��� ���� ����� ��Ÿ���� ������
//	std::list<int>::iterator kill = survivors.begin();
//	for (int i = 1; i < k; i++) {
//		kill++;
//	}
//	while (n > 1) {
//		//ù° ����� �ڻ��Ѵ�. erase()�� ���� ������ ���� ���Ҹ� ��ȯ�Ѵ�.
//		--n;
//		cout << *kill <<", ";
//		kill = survivors.erase(kill);
//		if (kill == survivors.end()) kill = survivors.begin();
//	
//		//k-1�� ���� ������� �ű��.
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