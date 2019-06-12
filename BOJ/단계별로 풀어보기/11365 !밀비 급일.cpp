#include<iostream>
#include<string>

using namespace std;



int main() {
	char temp[501];

	while (1) {
		//getline(char *, 읽을 개수, 읽기를 멈출 기준이 되는 문자)함수를 활용하여 개행문자('\n')부분까지 읽는다.
		cin.getline(temp, 501, '\n');
		//만일 읽은 글자가 END라면 반복 종료
		if (temp[0] == 'E' && temp[1] == 'N' && temp[2] == 'D')
			break;
		//읽은 글자를 string으로 변환한다.
		string ret(temp);
		int t = ret.size();
		//string의 마지막 부분부터 출력
		while (t--) {
			cout << ret[t];
		}
		cout << endl;
	}
	

	return 0;
}