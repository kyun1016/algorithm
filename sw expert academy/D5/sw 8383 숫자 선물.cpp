#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	cin >> T;

	string N;
	int x, y;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> x >> y;
		string ret;
		cout << "#" << test_case << " ";
		for (int i = 0; i < N.size(); i++) {
			//첫자리가 y보다 크면 모든 자리에 y를 집어넣는다.
			if (N[i] - 48 > y) {
				for (i; i < N.size(); i++)
					ret.push_back(y + 48);
			}
			//이번 자리가 y라면 우선 y를 집어넣고 다음으로 넘긴다.
			else if (N[i] - 48 == y) {
				ret.push_back(y + 48);
			}
			//이번 자리가 x보다 크다면, x를 집어넣고 그 뒤는 모두 y로 채운다.
			else if (N[i] - 48 > x) {
				ret.push_back(x + 48);
				i++;
				for (i; i < N.size(); i++) {
					ret.push_back(y + 48);
				}
			}
			else if (N[i] - 48 == x) {
				ret.push_back(x + 48);
			}
			//이부분이 틀렸다.
			else if (N[i] - 48 < x) {
				if (ret.size() == 0) {
					i++;
					for (i; i < N.size(); i++) {
						ret.push_back(y + 48);
					}
				}
				else {
					int order = -1;
					for (int j = 0; j < ret.size(); j++) {
						if (ret[j] - 48 == y) {
							order = j;
						}
					}
					if (order == -1) {
						ret.pop_back();
						for (int j=0; j < ret.size(); j++) {
							ret[j] = y + 48;
						}
						for (i; i < N.size(); i++) {
							ret.push_back(y + 48);
						}
					}
					else {
						ret[order++] = x + 48;
						for (order; order < ret.size(); order++) {
							ret[order] = y + 48;
						}
						for (i; i < N.size(); i++) {
							ret.push_back(y + 48);
						}
					}
					
				}
			}
		}

		while (ret[0] - 48 == 0) {
			ret.erase(0, 1);
		}

		if (ret.size() == 0)
			cout << -1 << "\n";
		else
			cout << ret <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}