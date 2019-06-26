#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>


using namespace std;
const int MAX = 100000;

struct Point {
	int x, y; // ���� ��ġ
	int p, q; // ���������κ����� ��� ��ġ
	Point() : Point(0, 0, 1, 0) {}
	Point(int x1, int y1) : Point(x1, y1, 1, 0) {}
	Point(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1) {}
	// p, q ���� �������� �����ϱ� ���� ���迬����
	bool operator <(const Point& O) {
		if (1LL * q * O.p != 1LL * p * O.q) return 1LL * q * O.p < 1LL * p * O.q;
		if (y != O.y) return y < O.y;
		return x < O.x;
	}
};

Point p[MAX];
Point findThis;

stack<int> S;

// ���� AB�� ���� AC�� CW/CCW
long long ccw(const Point & A, const Point & B, const Point & C) {
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int main() {
	int N;
	cin >> N;
	/*int find;
	cin >> find;*/
	
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		p[i] = Point(x, y);
	}

	//findThis = p[find];

	// ������ y��ǥ -> x��ǥ ������ ����: 0�� ���� ���� �Ʒ� ���� ����
	sort(p, p + N);

	for (int i = 1; i < N; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	// 0���� ������ ������ �ݽð� �������� ����
	sort(p + 1, p + N);

	
	// ���ÿ� ó�� 2���� ���� ����
	S.push(0);
	S.push(1);
	int next = 2;
	// ��� ���� ����
	while (next < N) {
		// ���ÿ� 2�� �̻��� ���� �����ִ� ��...
		while (S.size() >= 2) {
			int first, second;
			first = S.top();
			S.pop();
			second = S.top();
			// ���� �ֻ�� �� 2���� ���� ���� ���谡 CCW�� ������ ���� pop
			if (ccw(p[second], p[first], p[next]) > 0) {
				S.push(first);
				break;
			}
		}
		// ���� ���� ���ÿ� ����
		S.push(next++);
	}
	// ���� ���ÿ� ������ �� �������� ������� �׿� ����

	// ������ ���� �� ���� ���
	cout << S.size() << endl;
	/*while(!S.empty()) {
		int first = S.top();
		S.pop();
		if (p[first].x == findThis.x && p[first].y == findThis.y) {
			cout << "here is outside" << endl;
		}
	}*/

	return 0;
}

