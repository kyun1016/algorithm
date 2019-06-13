#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<int> st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//char temp[101];
	string S;

	while (1) {
		////���� �Է� �޾ƿ���.
		//cin.getline(temp, 100, '\n');
		//if (temp[0] == '.' && temp[1] == NULL)
		//	break;
		////string���� ��ȯ
		//string S(temp);

		getline(cin, S);
		if (S.length() == 1 && S[0] == '.')
			break;


		//������ �ʱ�ȭ�Ѵ�.
		while (!st.empty())
			st.pop();

		//S�� ��ȸ�ϸ鼭 ���๮��('[(')�� ������ ���ÿ� �־��ְ�, �ݴ� �κп��� ¦�� �´��� Ȯ���Ѵ�.
		//¦�� ���� �ʴ´ٸ�, break;
		bool flag = true;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '(')
				st.push(1);
			else if (S[i] == '[')
				st.push(2);
			else if (S[i] == ')') {
				if (!st.empty() && st.top() == 1)
					st.pop();
				else {
					flag = false;
					break;
				}
			}
			else if (S[i] == ']') {
				if (!st.empty() && st.top() == 2)
					st.pop();
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag && st.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	

	return 0;
}