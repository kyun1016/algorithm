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
			//ù�ڸ��� y���� ũ�� ��� �ڸ��� y�� ����ִ´�.
			if (N[i] - 48 > y) {
				for (i; i < N.size(); i++)
					ret.push_back(y + 48);
			}
			//�̹� �ڸ��� y��� �켱 y�� ����ְ� �������� �ѱ��.
			else if (N[i] - 48 == y) {
				ret.push_back(y + 48);
			}
			//�̹� �ڸ��� x���� ũ�ٸ�, x�� ����ְ� �� �ڴ� ��� y�� ä���.
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
			//�̺κ��� Ʋ�ȴ�.
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}