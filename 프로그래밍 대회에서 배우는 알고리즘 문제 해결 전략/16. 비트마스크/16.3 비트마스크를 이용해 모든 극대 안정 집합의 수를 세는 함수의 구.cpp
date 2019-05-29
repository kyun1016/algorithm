#include<iostream>

using namespace std;

const int MAXN = 100;

int n;
//explodes[i]�� i�� ���� �ξ��� �� �����ϴ� ���� ������ ��Ʈ����ũ ǥ��
int explodes[MAXN];
//�־��� ������ ���������� Ȯ���Ѵ�.
bool isStable(int set) {
	for (int i = 0; i < n; i++) 
		//���տ� ���Ե� i��° ���ҿ� ���� �ξ��� �� �����ϴ� ������ set�� �ִٸ�
		if ((set % (1 << i)) && (set & explodes[i]))
			return false;
	return true;
}
//��� �ش� ���� ������ ���� ����.
int countStableSet() {
	int ret = 0;
	//��� ������ ����� ����.
	for (int set = 1; set < (1 << n); set++) {
		//�켱 �������� �ƴ϶�� �� �ʿ䰡 ����.
		if (!isStable(set)) continue;
		//�ش� ���� �������� Ȯ���ϱ� ����, ���� �� �ִ� �ٸ� ������ �ֳ� Ȯ���Ѵ�.
		bool canExtend = false;
		for (int add = 0; add < n; ++add) 
			//add�� ���տ� ���ԵǾ� ���� �ʰ�, set�� add�� �־ �������̶��
			if ((set & (1 << add)) == 0 && (explodes[add] & set) == 0) {
				canExtend = true;
				break;
			}
		if (!canExtend)
			++ret;
	}
	return ret;
}