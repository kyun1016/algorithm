//#include<iostream>
//
//using namespace std;
//typedef unsigned long long ull;
//
//ull divisor[10000];
//
//ull gcd(ull a, ull b) {
//	return a % b ? gcd(b, a%b) : b;
//}
//
////N�� ����� ���ϴ� �Լ�
//ull countDivisor(ull N) {
//	ull ret = 1;
//	int k = 0,flag = 1;
//	for (ull i = 2; i*i <= N; i++) {
//		if (N%i == 0) {
//			//for (int j = 0; j < k; j++) {
//			//	flag = 1;
//			//	//���� ������ ����� ����� �����
//			//	if (i%divisor[j] == 0) {
//			//		flag = -1;
//			//		break;
//			//	}
//			//}
//			//�� ���� ���� ����� ����� �ƴ϶��
//			/*if (flag == 1) {*/
//				for (int j = 0; j < k; j++) {
//					int temp = i * divisor[j];
//					for (int m = temp; m <= N; m += temp) {
//						ret--;
//					}
//					
//				}
//				divisor[k++] = i;
//				//�� ���� ����� ������ �����ش�.
//				for (ull j = i; j <= N; j += i)
//					ret++;
//				
//			//}
//		}
//	}
//	
//	return ret;
//}
//
//void printGDCOne(ull N) {
//	cout << N - countDivisor(N);
//}
//
//void countOne(ull N) {
//	int ret=0;
//	for (ull i = 1; i <= N; i++) {
//		if(gcd(i, N)==1)
//			ret++;
//	}
//	cout << ret << endl;
//}
//
//int main() {
//	ull N;
//	cin >> N;
//
//
//	printGDCOne(N);
//	//countOne(N);
//
//	return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef unsigned long long ull;

ull gcd(ull a, ull b) {
	return a % b ? gcd(b, a%b) : b;
}

vector<ull> prime;
bool eratosthenes_sieve[1000002];

void count_prime(const ull end) {
	ull i, j;
	//�迭 �ʱ�ȭ
	for (i = 2; i <= end;i++) {
		eratosthenes_sieve[i] = true;
	}

	//�Ҽ� Ž��
	for (i = 2;i <= end;i++) {
		if (eratosthenes_sieve[i]) {
			for (j = i * i;j <= end;j += i)
				eratosthenes_sieve[j] = false;
		}
		
	}
}

void gcdOne(const ull N) {
	ull ret = N;
	count_prime(N);
	for (int i = 2; i <= N; i++) {
		if (eratosthenes_sieve[i]&&N%i == 0) {
			ret /= i;
			ret *= i - 1;
		}
	}
	std::cout << ret;
}



//���� ������
void coprime(ull N) {
	//�̹����� ���Ϸ��� �����Լ��� Ȱ���Ͽ� ������ ������ ���̴�.
	//�����Լ��� Ȱ���ϱ� ���ؼ���
	//1. N�� ����� ������ �Ҽ��� ��� ���ؾ� �Ѵ�.
	//�̸� ���ؼ� ����� ã�� �ڵ带 Ȱ���� ���̴�.
	if (N == 1) {
		cout << 1;
		return;
	}

	ull i, j, k=0;
	ull prime[10000];

	ull ret = N;

	//N^0.5�� ������ �Ѵ�.
	for (i = 1; i*i <= N; i++) {
		if (i*i == N)
			prime[k++] = i;
		else if (N%i == 0) {
			prime[k++] = i;
			prime[k++] = N / i;
		}
		
	}

	//������������ �������ش�.
	sort(prime, prime+k);

	const int divisorSize = k;
	k = 0;
	//���� ����� �迭 �߿��� �Ҽ��� �ƴ� ���� �ִٸ�, �����ش�.(-1�� �ٲپ� �� ���̴�.)
	//����� ������ 500�� �����̹Ƿ�, �ִ� 250000���� ������ �� ���̴�.
	//prime[1]���� �����ϴ� ������ prime[0]=1���� Ư�����̽��̱� ������ ����� ���־���.
	for (i = 1; i < divisorSize-1; i++) {
		ull temp = prime[i];
		for (j = i + 1; j < divisorSize; j++) {
			if (temp == -1)
				break;
			if (prime[j] != -1 && prime[j] % temp == 0) {
				prime[j] = -1;
			}
				
		}
	}

	//���� ���Ϸ� �����Լ��� Ȱ������.
	//prime�� ��� ���� Ȱ������.
	for (i = 1; i < divisorSize; i++) {
		if (prime[i] != -1) {
			ret *= prime[i] - 1;
			ret /= prime[i];
		}
	}

	cout << ret << endl;

}


int main() {
	ull N;
	std::cin >> N;

	coprime(N);
	return 0;
}
