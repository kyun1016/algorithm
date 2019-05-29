//#include<iostream>
//#include<vector>
//
//
//using namespace std;
//
////�������� ���¸� ǥ���Ѵ�.
//class State {
//	// ������ ���µ��� ����� ��ȯ�Ѵ�
//	vector<State> getAdjacent() const;
//	// map�� State�� �ֱ� ���� �� ������
//	bool operator < (const State& rhs) const;
//	// ���� ���¿� ���ϱ� ���� ������
//	bool operator == (const State& rhs) const;
//
//	// �޸���ƽ�� ���� ��
//	// ��� Ÿ�Ͽ� ���� ���� ��ġ�� ��ǥ ��ġ ������ ����ư �Ÿ��� ���Ѵ�
//	// Manhattan distance: |x1-x2| + |y1-y2|
//	int estimate() const;
//};
//
//int best;
//
//// ���� �켱 Ž��
//void dfs(State here, const State& finish, int steps) {
//	// ���ݱ��� ���� �����غ��� �� ���� ���ɼ��� ������ ������
//	// if (steps >= best) return;
//	if (steps + here.estimate() >= best) return;
//	// ��ǥ ���¿� ������ ���
//	if (here == finish) { best = steps; return; }
//	// ���� ���µ��� ���� �켱 Ž������ ���Ѵ�
//	vector<State> adjacent = here.getAdjacent();
//	for (int i = 0; i < adjacent.size(); i++)
//		dfs(adjacent[i], finish, steps + 1);
//}
//
//// ���� ������� Ž��
//int ids(State start, State finish, int growthStep) {
//	for (int limit = 4; 1; limit += growthStep) {
//		best = limit + 1;
//		dfs(start, finish, 0);
//		if (best <= limit) return best;
//	}
//
//	return -1;
//}