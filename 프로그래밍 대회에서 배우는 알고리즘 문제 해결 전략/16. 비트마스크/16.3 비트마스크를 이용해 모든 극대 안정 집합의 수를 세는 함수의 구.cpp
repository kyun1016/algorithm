#include<iostream>

using namespace std;

const int MAXN = 100;

int n;
//explodes[i]는 i와 같이 두었을 때 폭발하는 물질 집합의 비트마스크 표현
int explodes[MAXN];
//주어진 집합이 안정적인지 확인한다.
bool isStable(int set) {
	for (int i = 0; i < n; i++) 
		//집합에 포함된 i번째 원소와 같이 두었을 때 폭발하는 물질이 set에 있다면
		if ((set % (1 << i)) && (set & explodes[i]))
			return false;
	return true;
}
//모든 극대 안정 집합의 수를 센다.
int countStableSet() {
	int ret = 0;
	//모든 집합을 만들어 보자.
	for (int set = 1; set < (1 << n); set++) {
		//우선 안정적이 아니라면 셀 필요가 없다.
		if (!isStable(set)) continue;
		//극대 안정 집합인지 확인하기 위해, 넣을 수 있는 다른 물질이 있나 확인한다.
		bool canExtend = false;
		for (int add = 0; add < n; ++add) 
			//add가 집합에 포함되어 있지 않고, set에 add를 넣어도 안정적이라면
			if ((set & (1 << add)) == 0 && (explodes[add] & set) == 0) {
				canExtend = true;
				break;
			}
		if (!canExtend)
			++ret;
	}
	return ret;
}