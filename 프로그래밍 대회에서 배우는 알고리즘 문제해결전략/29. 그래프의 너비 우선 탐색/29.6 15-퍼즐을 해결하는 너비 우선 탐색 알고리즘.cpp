//#include<vector>
//#include<queue>
//#include<iostream>
//#include<map>
//
//using namespace std;
//
//
//
//bool State::operator<(const State& rhs) const
//{
//	return false;
//}
//
//vector<State> State::getAdjacent() const
//{
//	return vector<State>();
//}
//
////�������� ���¸� ǥ���Ѵ�.
//class State {
//	//������ ���µ��� ����� ��ȯ�Ѵ�.
//	vector<State> getAdjacent() const;
//	//map�� State�� �ֱ� ���� �� ������
//	bool operator < (const State& rhs) const;
//
//	//���� ���¿� ���ϱ� ���� ������
//	bool operator == (const State& rhs) const;
//
//};
//typedef map<State, int> StateMap;
////start���� finish���� ���� �ִ� ����� ���̸� ��ȯ�Ѵ�.
//int bfs(State start, State finish) {
//	//����: start == finish�� ���
//	if (start == finish) return 0;
//	//�� ���������� �ִ� ����� ���̸� �����Ѵ�.
//	StateMap c;
//	//������ �湮�� �������� �����Ѵ�.
//	queue<State> q;
//	q.push(start);
//	c[start] = 0;
//	//�ʺ� �켱 Ž��
//	while (!q.empty()) {
//		State here = q.front();
//		q.pop();
//		int cost = c[here];
//		//������ �������� ��ȣ�� ����.
//		vector<State> adjacent = here.getAdjacent();
//		for (int i = 0; i < adjacent.size(); i++) {
//			if (c.count(adjacent[i]) == 0) {
//				//���� ã�ҳ�?
//				if (adjacent[i] == finish) return cost = 1;
//				c[adjacent[i]] = cost + 1;
//				q.push(adjacent[i]);
//
//			}
//		}
//	}
//	//���� ã�� ���� ���
//	return -1;
//}
//
//////�ڵ� 29.7 15-���� ������ �ذ��ϴ� ����� Ž�� �˰���
//
////15-���� ������ ���¸� ǥ���ϴ� Ŭ����
//class State;
////x�� ��ȣ�� ��ȯ�Ѵ�.
//int sgn(int x) {
//	if (!x) return 0; return x > 0 ? 1 : -1;
//}
////x�� ���밪�� 1 ������Ų��
//int incr(int x) {
//	if (x < 0) return x - 1; return x + 1;
//}
////start���� finish���� ���� �ִ� ����� ���̸� ��ȯ�Ѵ�.
//int bidirectional(State start, State finish) {
//	//�� ���������� �ִ� ����� ���̸� �����Ѵ�.
//	map<State, int> c;
//	//������ �湮�� �������� �����Ѵ�.
//	queue<State> q;
//	//���� ���¿� ��ǥ ���°� ���� ���� ���ܷ� ó���ؾ� �Ѵ�.
//	if (start == finish) return 0;
//	q.push(start); c[start] = 1;
//	q.push(finish); c[finish] = -1;
//	//�ʺ� �켱 Ž��
//	while (!q.empty()) {
//		State here = q.front();
//		q.pop();
//		//������ ���µ��� �˻��Ѵ�.
//		vector<State> adjacent = here.getAdjacent();
//		for (int i = 0; i < adjacent.size(); i++) {
//			map<State, int>::iterator it = c.find(adjacent[i]);
//			if (it == c.end()) {
//				c[adjacent[i]] == incr(c[here]);
//				q.push(adjacent[i]);
//			}
//			//����� ���� ���
//			else if (sgn(it->second) != sgn(c[here]))
//				return abs(it->second) + abs(c[here]) - 1;
//		}
//	}
//	//���� ã�� ���� ���
//	return - 1;
//}