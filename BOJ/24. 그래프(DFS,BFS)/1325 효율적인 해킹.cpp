#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

//vector<pair<int, int> > trust;
//trust[i]�� �ڽ��� �ŷ��ϴ� ��ǻ�͸� �ڼ� ���� ���´�.
vector<int> trust[10001];
bool visited[10001];
pair<int,int> Count[10001];

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}


//ù��° ������ Ʋ�ȴ�. �ֳ��ϸ� �ڼճ���߿� 2�� �湮�ϴ� ���� ������� ���߱� �����̴�.
void calcHackComputer(int here, int mather) {
	//���� ��� : �̹� �湮�� ����̸� ����
	if (visited[here])
		return;
	visited[here] = true;

	for (int i = 0; i < trust[here].size(); i++) {
		if (!visited[trust[here][i]]) {
			Count[mather].first++;
			calcHackComputer(trust[here][i], mather);
		}
	}
	Count[mather].first++;
}

int main() {
	int N, M,a,b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		//trust.push_back({ a,b });
		//a�� b�� �ŷ��ϹǷ� �̸� vector�� �ݿ��Ѵ�.
		trust[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		calcHackComputer(i, i-1);
		Count[i-1].second = i;
	}
	

	sort(Count, Count + N, comp);

	int temp = Count[0].first;

	for (int i = 0; i < N; i++) {
		//cout << Count[i].second << " : " << Count[i].first << endl;

		if (Count[i].first == temp) {
			cout << Count[i].second << " ";
		}
		else {
			break;
		}
	}

	return 0;
}