#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
using namespace std;

bool stringMODNine(const string& S, int k) {
	int t = 0;
	for (int i = 0; i < S.size(); i++) {
		t += S[i] - 48;
	}
	t += k;
	if (t % 9 == 0)
		return true;
	else
		return false;
}

ull solve(const string& F, const string& L) {


	//10진수로 변환하자.
	ull a = 0, b = 0, c = 0;
	ull k = 1;
	for (int i = 1; i <= F.size(); i++) {
		a += (F[F.size() - i] - 48) * k;
		k *= 9;
	}
	k = 1;
	for (int i = 1; i <= L.size(); i++) {
		b += (L[L.size() - i] - 48) * k;
		k *= 9;
	}
	//사이에 중복되어있는 9의 배수의 개수를 찾자.(9개마다 1개가 포함)
	int arr[9];
	for (int i = 0; i < 9; i++) {
		arr[i] = i;
	}
	ull n = a, m = b;
	
	n /= 9;
	char x = F[F.size() - 1];
	bool flag = false;
	for (int i = 0; i < 9; i++) {
		
		if ((x - 48) == 9) {
			break;
		}
		if (stringMODNine(F, i)) {
			flag = true;
			break;
		}
		x++;
	}
	if (flag)
		n--;
	if (a == 8)
		n = 0;
		
	m /= 9;
	x = L[L.size() - 1];
	flag = false;
	for (int i = 0; i < 9; i++) {
		
		if ((x - 48) == 9) {
			break;
		}
		if (stringMODNine(L, i)) {
			flag = true;
			break;
		}
		x++;
	}
	if (flag)
		m--;
	if (b == 8)
		m = 0;

	
	//cout << a << " " << b << endl;
	//cout << n << " " << m << endl;

	return (b - m) - (a - n) + 1;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	string F, L;
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> F >> L;

		cout << "Case #" << i << ": " << solve(F,L) << "\n";
	}
}


//void printNine(int N) {
//	int a = 9;
//	int count = 0;
//	for (int i = 1; i < N; i++) {
//		
//		if (includeNine(a)) {
//			count++;
//			cout << i << " : " << a << "\t\t" << count <<endl;
//		}
//			
//		a += 9;
//	}
//}

//
//ull seed[20];
//ull seedSum[20];
//
//bool includeNine(const ull& N) {
//	ull copy = N;
//	while (copy) {
//		int a = copy % 10;
//		if (a == 9)
//			return true;
//		copy /= 10;
//	}
//	return false;
//}
//
//ull nineFilter(const string& F, const string& L) {
//	ull count = 0;
//	ull a = atoi(F.c_str());
//	ull b = atoi(L.c_str());
//	ull i = a;
//	int temp = i % 9;
//	i += (9 - temp);
//	while (1) {
//		if (i > b)
//			break;
//		if (!includeNine(i))
//			count++;
//		i += 9;
//	}
//	return count;
//}