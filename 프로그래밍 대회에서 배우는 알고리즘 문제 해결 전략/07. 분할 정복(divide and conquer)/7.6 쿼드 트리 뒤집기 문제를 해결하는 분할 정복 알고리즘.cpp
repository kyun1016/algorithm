//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MAX_SIZE = 1000;
//
//char decompressed[MAX_SIZE][MAX_SIZE];
//void decompress(string::iterator& it, int y, int x, int size) {
//	//�� ���ڸ� �˻��� ������ �ݺ��ڸ� �� ĭ ������ �ű��.
//	char head = *(it++);
//	// ���� ���: ù ���ڰ� b �Ǵ� w�� ���
//	if (head == 'b' || head == 'w') {
//		for (int dy = 0; dy < size; dy++)
//			for (int dx = 0; dx < size; dx++)
//				decompressed[y + dy][x + dx] = head;
//	}
//	else {
//		//�� �κ��� ���� ������� ���� �����Ѵ�.
//		int half = size / 2;
//		decompress(it, y, x, half);
//		decompress(it, y, x + half, half);
//		decompress(it, y + half, x, half);
//		decompress(it, y + half, x + half, half);
//	}
//}
//
//string reverse(string::iterator& it) {
//	char head = *it;
//	++it;
//	if (head == 'b' || head == 'w')
//		return string(1, head);
//	string upperLeft = reverse(it);
//	string upperRight = reverse(it);
//	string lowerLeft = reverse(it);
//	string lowerRight = reverse(it);
//	//���� ���� �Ʒ� �������� ��ġ�� �ٲ۴�.
//	return string("X") + lowerLeft + lowerRight + upperLeft + upperRight;
//}