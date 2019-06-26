#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>


using namespace std;
const int MAX = 100000;

struct Point {
	int x, y; // 실제 위치
	int p, q; // 기준점으로부터의 상대 위치
	Point() : Point(0, 0, 1, 0) {}
	Point(int x1, int y1) : Point(x1, y1, 1, 0) {}
	Point(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1) {}
	// p, q 값을 기준으로 정렬하기 위한 관계연산자
	bool operator <(const Point& O) {
		if (1LL * q * O.p != 1LL * p * O.q) return 1LL * q * O.p < 1LL * p * O.q;
		if (y != O.y) return y < O.y;
		return x < O.x;
	}
};

Point p[MAX];
Point findThis;

stack<int> S;

// 벡터 AB와 벡터 AC의 CW/CCW
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

	// 점들을 y좌표 -> x좌표 순으로 정렬: 0번 점이 제일 아래 제일 왼쪽
	sort(p, p + N);

	for (int i = 1; i < N; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	// 0번을 제외한 점들을 반시계 방향으로 정렬
	sort(p + 1, p + N);

	
	// 스택에 처음 2개의 점을 넣음
	S.push(0);
	S.push(1);
	int next = 2;
	// 모든 점을 훑음
	while (next < N) {
		// 스택에 2개 이상의 점이 남아있는 한...
		while (S.size() >= 2) {
			int first, second;
			first = S.top();
			S.pop();
			second = S.top();
			// 스택 최상단 점 2개와 다음 점의 관계가 CCW일 때까지 스택 pop
			if (ccw(p[second], p[first], p[next]) > 0) {
				S.push(first);
				break;
			}
		}
		// 다음 점을 스택에 넣음
		S.push(next++);
	}
	// 이제 스택에 컨벡스 헐 정점들이 순서대로 쌓여 있음

	// 컨벡스 헐의 점 개수 출력
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

