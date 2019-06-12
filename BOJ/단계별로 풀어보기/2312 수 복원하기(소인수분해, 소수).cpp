#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool eratosthenes_sieve[100002];
vector<int> prime;


void primeFactorization(const int& N) {
	//���� ��� : �̹� �Ҽ��� ��� ����� �ϰ� �����Ѵ�.
	if (eratosthenes_sieve[N]) {
		cout << N << " 1\n";
		return;
	}
	
	int copy_N = N;
	//ã�� �Ҽ��� �������� ���μ����ظ� �ǽ��Ѵ�.
	//���ʿ��� ������ ���� �� �ִ�.
	for (int i = 0; i < prime.size(); i++) {
		//���� ��� : �ڱ��ڽ��� �Ҽ��� �� �����, ����ϰ� ����.
		if (eratosthenes_sieve[copy_N]) {
			if (copy_N == 1)
				return;
			cout << copy_N << " 1\n";
			return;
		}

		//prime[i]�� �ڽ��� �μ��� ���Ѵٸ�, ����̳� ���������� Ȯ���Ѵ�.
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
	//����� �����ϱ� ���� 100000�������� �Ҽ��� �̸� Ž���Ѵ�.
	memset(eratosthenes_sieve, true, sizeof(eratosthenes_sieve));
	for (int i = 2;i <= 100000;i++) {
		if (i*i > 100000)
			break;
		if (eratosthenes_sieve[i]) {
			for (int j = i + i;j <= 100000;j += i)
				eratosthenes_sieve[j] = false;
		}
	}
	//eratosthenes_sieve�� Ȱ���� ã�� �Ҽ��� Ȱ���ϱ� ���ϰ� vector<int>�� �����Ѵ�.
	for (int i = 2; i <= 100000; i++) {
		if (eratosthenes_sieve[i]) 
			prime.push_back(i);
	}
	
	//���μ����ظ� ��������.
	for (int i = 0; i < N; i++) {
		cin >> origin;
		primeFactorization(origin);
	}


	return 0;
}