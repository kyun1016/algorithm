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
//	//한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
//	char head = *(it++);
//	// 기저 사례: 첫 글자가 b 또는 w인 경우
//	if (head == 'b' || head == 'w') {
//		for (int dy = 0; dy < size; dy++)
//			for (int dx = 0; dx < size; dx++)
//				decompressed[y + dy][x + dx] = head;
//	}
//	else {
//		//네 부분을 각각 순서대로 압축 해제한다.
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
//	//각각 위와 아래 조각들의 위치를 바꾼다.
//	return string("X") + lowerLeft + lowerRight + upperLeft + upperRight;
//}