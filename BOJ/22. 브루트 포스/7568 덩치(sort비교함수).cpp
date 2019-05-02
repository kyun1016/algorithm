#include<iostream>

using namespace std;

pair<int, int>people[50];
int Rank[50];

void compareRank(const int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (people[i].first > people[j].first && people[i].second > people[j].second)
				Rank[j]++;
		}
	}
}

void printRank(const int N) {
	for (int i = 0; i < N; i++) {
		cout << Rank[i] + 1 << " ";
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> people[i].first >> people[i].second;
	}

	compareRank(N);
	printRank(N);

	return 0;
}