#include <iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int Answer;
int PalindromeData[200];
int Solve[10001];
vector<int> v[10001];
queue<int> qu;
bool visited[10001];


//void palindrome_Preprocessing(const int& N = 10000) {
//	string temp;
//	int count = 0;
//	for (int i = 1; i < N; i++) {
//		temp = to_string(i);
//		bool isPalindrome = true;
//		for (int j = 0; j < temp.size() / 2; j++) {
//			if (temp[j] == temp[temp.size() - 1 - j]) {}
//			else {
//				isPalindrome = false;
//				break;
//			}
//		}
//		if (isPalindrome)
//			PalindromeData[count++] = i;
//	}
//	
//
//	for (int i = 0; i < 198; i++) {
//		int one = PalindromeData[i];
//		visited[one] = true;
//		Solve[one] = 1;
//		while (!qu[one].empty())
//			qu[one].pop_back();
//		qu[one].push_back(one);
//		for (int j = 0; j < 198; j++) {
//			int two = one + PalindromeData[j];
//			if (visited[two] && Solve[two] <= 2)
//				continue;
//			visited[two] = true;
//			Solve[two] = 2;
//			while (!qu[two].empty()) {
//				qu[two].pop_back();
//			}
//			qu[two].push_back(one);
//			qu[two].push_back(PalindromeData[j]);
//			for (int k = 0; k < 198; k++) {
//				int three = two + PalindromeData[k];
//				//이
//				if (visited[three])
//					continue;
//				visited[three] = true;
//				Solve[three] = 3;
//				while (!qu[three].empty()) {
//					qu[three].pop_back();
//				}
//				qu[three].push_back(one);
//				qu[three].push_back(PalindromeData[j]);
//				qu[three].push_back(PalindromeData[k]);
//			}
//		}
//	}
//	
//}


void makePalidrome() {
	string temp;
	int count = 0;
	//1부터 1만까지 회문을 저장하자.
	for (int i = 1; i < 10000; i++) {
		temp = to_string(i);
		bool isPalindrome = true;
		for (int j = 0; j < temp.size() / 2; j++) {
			if (temp[j] == temp[temp.size() - 1 - j]) {}
			else {
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome)
			PalindromeData[count++] = i;
	}
	//회문은 197개 만들어지고, 1개로 만들 수 있는 수들을 찾는다.
	for (int i = 0; i < 198; i++) {
		Solve[PalindromeData[i]] = 1;
		v[PalindromeData[i]].push_back(PalindromeData[i]);
		visited[PalindromeData[i]] = true;
	}
	//2개의 회문을 더해 만들어지는 수를 찾는다.
	for (int i = 0; i < 198; i++) 
		for (int j = 0; j < 198; j++) {
			int tmp = PalindromeData[i] + PalindromeData[j];
			//이 값이 1만보다 커지면 다음 수로 넘긴다.
			if (tmp > 10000)
				break;
			//이미 찾아진 경우라면 pass
			if (visited[tmp])
				continue;
			Solve[tmp] = 2;
			visited[tmp] = true;
			//활용한 수를 vector에 저장
			v[tmp].push_back(PalindromeData[i]);
			v[tmp].push_back(PalindromeData[j]);
			sort(v[tmp].begin(), v[tmp].end());
		}
	
	//3개의 회문을 더해 만들어지는 수를 찾는다.
	for (int i = 0; i < 198; i++) 
		for (int j = 0; j < 198; j++) 
			for (int k = 0; k < 198; k++) {
				int tmp = PalindromeData[i] + PalindromeData[j] + PalindromeData[k];
				if (tmp > 10000)
					break;
				if (visited[tmp])
					continue;
				Solve[tmp] = 3;
				visited[tmp] = true;
				v[tmp].push_back(PalindromeData[i]);
				v[tmp].push_back(PalindromeData[j]);
				v[tmp].push_back(PalindromeData[k]);
				sort(v[tmp].begin(), v[tmp].end());
			}
}

//void calc(const int& N) {
//	int copy_N = N;
//	int count = 0;
//	for (int i = 197; i >= 0; i--) {
//		if (copy_N == 0) {
//			Answer = count;
//			return;
//		}
//		if (copy_N >= PalindromeData[i]) {
//			copy_N -= PalindromeData[i];
//			qu.push(PalindromeData[i]);
//			count++;
//		}
//		if (count > 3) {
//			Answer = 0;
//			return;
//		}
//	}
//	if (copy_N == 0 && count <= 3) {
//		Answer = count;
//		return;
//	}
//	else {
//		Answer = 0;
//		return;
//	}
//
//
//}

int main(int argc, char** argv)
{
	int T, test_case;
	int N;
	makePalidrome();
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N;

		/*while (!qu.empty())
			qu.pop();

		calc(N);*/

		cout << "Case #" << test_case + 1 << endl;
		cout << Solve[N] << " ";
		for (int i = 0; i < Solve[N]; i++) {
			cout << v[N][i] << " ";
		}
		cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

//#include <iostream>
//#include<string>
//#include<queue>
//using namespace std;
//
//int Answer;
//int PalindromeData[200];
//queue<int> qu;
//
//
//void palindrome_Preprocessing(const int& N = 10000) {
//	string temp;
//	int count = 0;
//	for (int i = 1; i < N; i++) {
//		temp = to_string(i);
//		bool isPalindrome = true;
//		for (int j = 0; j < temp.size() / 2; j++) {
//			if (temp[j] == temp[temp.size() - 1 - j]) {}
//			else {
//				isPalindrome = false;
//				break;
//			}
//		}
//		if (isPalindrome)
//			PalindromeData[count++] = i;
//	}
//	/*for (int i = 0; i < 198; i++)
//		cout << i << " : "<< PalindromeData[i] << endl;*/
//}
//
//void calc(const int& N) {
//	int copy_N = N;
//	int count = 0;
//	for (int i = 197; i >= 0; i--) {
//		if (copy_N == 0) {
//			Answer = count;
//			return;
//		}
//		if (copy_N >= PalindromeData[i]) {
//			copy_N -= PalindromeData[i];
//			qu.push(PalindromeData[i]);
//			count++;
//		}
//		if (count > 3) {
//			Answer = 0;
//			return;
//		}
//	}
//	if (copy_N == 0 && count <= 3) {
//		Answer = count;
//		return;
//	}
//	else {
//		Answer = 0;
//		return;
//	}
//
//
//}
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//	int N;
//	palindrome_Preprocessing();
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		cin >> N;
//
//		while (!qu.empty())
//			qu.pop();
//
//		calc(N);
//
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << " ";
//		for (int i = 0; i < Answer; i++) {
//			cout << qu.front() << " ";
//			qu.pop();
//		}
//		cout << endl;
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}