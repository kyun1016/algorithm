//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//bool compare(const string &a, const string &b) {
//	if (a.size() == b.size()) {
//		return a < b;
//	}
//	return a.size() < b.size();
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	int n,i;
//	vector<string> dictionary;
//	std::string temp;
//	std::cin >> n;
//	for (i = 0;i < n;i++) {
//		cin >> temp;
//		dictionary.push_back(temp);
//	}
//	sort(dictionary.begin(), dictionary.end(), compare);
//
//	vector<string>::iterator it;
//	vector<string>::iterator end_it;
//
//	dictionary.erase(unique(dictionary.begin(), dictionary.end()),dictionary.end());
//
//	for (auto t : dictionary) {
//		cout << t << "\n";
//	}
//}