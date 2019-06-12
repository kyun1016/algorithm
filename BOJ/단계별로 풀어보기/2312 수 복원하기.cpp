#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool eratosthenes_sieve[100002];
vector<int> prime;


void primeFactorization(const int& N) {
	//기저 사례 : 이미 소수인 경우 출력을 하고 종료한다.
	if (eratosthenes_sieve[N]) {
		cout << N << " 1\n";
		return;
	}
	
	int copy_N = N;
	//찾은 소수를 바탕으로 소인수분해를 실시한다.
	//불필요한 연산을 줄일 수 있다.
	for (int i = 0; i < prime.size(); i++) {
		//기저 사례 : 자기자신이 소수가 된 경우라면, 출력하고 종료.
		if (eratosthenes_sieve[copy_N]) {
			if (copy_N == 1)
				return;
			cout << copy_N << " 1\n";
			return;
		}

		//prime[i]가 자신의 인수에 속한다면, 몇번이나 곱해졌는지 확인한다.
		if (copy_N % prime[i] == 0) {
			int count = 0;
			while (copy_N % prime[i] == 0) {
				count++;
				copy_N /= prime[i];
			}
			cout << prime[i] << " " << count << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, origin;
	cin >> N;
	//계산을 시작하기 전에 100000범위내의 소수를 미리 탐색한다.
	memset(eratosthenes_sieve, true, sizeof(eratosthenes_sieve));
	for (int i = 2;i <= 100000;i++) {
		if (i*i > 100000)
			break;
		if (eratosthenes_sieve[i]) {
			for (int j = i + i;j <= 100000;j += i)
				eratosthenes_sieve[j] = false;
		}
	}
	//eratosthenes_sieve를 활용해 찾은 소수를 활용하기 편하게 vector<int>에 저장한다.
	for (int i = 2; i <= 100000; i++) {
		if (eratosthenes_sieve[i]) 
			prime.push_back(i);
	}
	
	//소인수분해를 시행하자.
	for (int i = 0; i < N; i++) {
		cin >> origin;
		primeFactorization(origin);
	}


	return 0;
}