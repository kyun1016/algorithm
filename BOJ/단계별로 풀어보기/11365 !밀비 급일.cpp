#include<iostream>
#include<string>

using namespace std;



int main() {
	char temp[501];

	while (1) {
		//getline(char *, ���� ����, �б⸦ ���� ������ �Ǵ� ����)�Լ��� Ȱ���Ͽ� ���๮��('\n')�κб��� �д´�.
		cin.getline(temp, 501, '\n');
		//���� ���� ���ڰ� END��� �ݺ� ����
		if (temp[0] == 'E' && temp[1] == 'N' && temp[2] == 'D')
			break;
		//���� ���ڸ� string���� ��ȯ�Ѵ�.
		string ret(temp);
		int t = ret.size();
		//string�� ������ �κк��� ���
		while (t--) {
			cout << ret[t];
		}
		cout << endl;
	}
	

	return 0;
}