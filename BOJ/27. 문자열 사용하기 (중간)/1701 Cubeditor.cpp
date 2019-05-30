#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int commonPrefix(const string& input, int i, int j) {
	int k = 0; 
	while (i < input.size() && j < input.size() && input[i] == input[j]) {
		i++; j++; k++;
	}
	return k;
}

int main() {
	string input;
	cin >> input;
	int ret = 0;
	for (int i = 0; i < input.size(); i++)
		for (int j = i + 1; j < input.size(); j++)
			ret = max(ret, commonPrefix(input, i, j));
		
	cout << ret;
	return 0;

}