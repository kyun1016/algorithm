#include<iostream>
#include<queue>
#include<string>

using namespace std;

queue<int> qu;
string input;

int main() {
	cin >> input;
	int ret = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') 
			qu.push(1);
		else if (input[i] == ')') 
			if (input[i - 1] == '(') {
				qu.pop();
				ret += qu.size();
			}
			else if (input[i - 1] == ')') {
				ret++;
				qu.pop();
			}
	}
	cout << ret << endl;


}