#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long ull;
ull N, road_length[100050], gas_cost[100050];

int main() {
	//input
	cin >> N;
	for (int i = 1; i < N; i++)
		cin >> road_length[i];
	for (int i = 0; i < N; i++)
		cin >> gas_cost[i];

	//calc
	ull min_cost = gas_cost[0];
	ull ret = 0;
	for (int i = 1; i < N; i++) {
		ret += min_cost * road_length[i];
		min_cost = min(min_cost, gas_cost[i]);
	}

	//output
	cout << ret << endl;
	return 0;
}