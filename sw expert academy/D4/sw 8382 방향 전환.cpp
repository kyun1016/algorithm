#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	cin >> T;

	pair<int, int> dist;
	int a, b, c, d;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b >> c >> d;
		pair<int, int> dist = { abs(a - c), abs(b - d) };

		cout << "#" << test_case << " ";
		if((abs(dist.first + dist.second)) % 2 == 0)
			cout << max(dist.first, dist.second) * 2 << "\n";
		else
			cout << max(dist.first, dist.second) * 2 - 1 << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}