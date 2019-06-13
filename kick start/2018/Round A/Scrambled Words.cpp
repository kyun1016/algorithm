//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//string arr[20001];
//
//string S_Generator(char x_1, char x_2, int N, int A, int B, int C, int D) {
//	string S;
//	S += x_1;
//	S += x_2;
//	long long int x[3];
//	x[0] = x_1; x[1] = x_2; x[2] = 0;
//	while (1) {
//		if (S.length() == N) {
//			return S;
//		}
//		x[2] = (A*x[0] + B * x[1] + C) % D;
//		S += char(97 + x[2] % 26);
//		x[0] = x[1]; 
//		x[1] = x[2];
//		x[2] = 0;
//	}
//	
//}
//
//int checkWord(const int& N, const string& S) {
//	int count = 0;
//	for (int k = 0; k < N; k++) {
//		int word_Length = arr[k].length();
//
//		string midText = arr[k].substr(1, word_Length - 2);
//		sort(midText.begin(), midText.end());
//
//		for (int i = 0; i < S.length() - word_Length + 1; i++) {
//			//앞뒤가 일치하면 탐색 시작.
//			if (S[i] == arr[k][0] && S[i + word_Length - 1] == arr[k].back()) {
//				string midText_ = "";
//				for (int j = 1; j < word_Length - 1; j++) {
//					midText_ += S[i + j];
//				}
//				sort(midText_.begin(), midText_.end());
//				if (midText == midText_) {
//					count++;
//					break;
//				}
//			}
//		}
//	}
//	
//	//만일 여기까지 왔다면, 이 단어는 등장하질 않았으므로 false반환.
//	return count;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int T, L, N, A, B, C, D;
//	char S_1, S_2;
//	
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//		cin >> L;
//		for (int j = 0; j < L; j++) {
//			cin >> arr[j];
//		}
//
//		cin >> S_1 >> S_2 >> N >> A >> B >> C >> D;
//		vector<int> X(N);
//		X[0] = S_1;
//		X[1] = S_2;
//		for (int i = 2; i < N; ++i) X[i] = ((long long)A*X[i - 1] + (long long)B*X[i - 2] + C) % D;
//		string S;
//		S.resize(N);
//		S[0] = S_1;
//		S[1] = S_2;
//		for (int i = 2; i < N; ++i) S[i] = char('a' + X[i] % 26);
//
//		//string S = S_Generator(S_1, S_2, N, A, B, C, D);
//
//		cout << "Case #" << i << ": " << checkWord(L, S) << "\n";
//	}
//}
