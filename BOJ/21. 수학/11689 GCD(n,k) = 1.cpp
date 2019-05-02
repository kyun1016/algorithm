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
////N의 약수를 구하는 함수
//ull countDivisor(ull N) {
//	ull ret = 1;
//	int k = 0,flag = 1;
//	for (ull i = 2; i*i <= N; i++) {
//		if (N%i == 0) {
//			//for (int j = 0; j < k; j++) {
//			//	flag = 1;
//			//	//만일 이전의 약수의 배수인 경우라면
//			//	if (i%divisor[j] == 0) {
//			//		flag = -1;
//			//		break;
//			//	}
//			//}
//			//이 수가 이전 약수의 배수가 아니라면
//			/*if (flag == 1) {*/
//				for (int j = 0; j < k; j++) {
//					int temp = i * divisor[j];
//					for (int m = temp; m <= N; m += temp) {
//						ret--;
//					}
//					
//				}
//				divisor[k++] = i;
//				//이 수의 배수를 모조리 없애준다.
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
	//배열 초기화
	for (i = 2; i <= end;i++) {
		eratosthenes_sieve[i] = true;
	}

	//소수 탐색
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



//새로 만들자
void coprime(ull N) {
	//이번에는 오일러의 파이함수를 활용하여 문제를 공략할 것이다.
	//파이함수를 활용하기 위해서는
	//1. N을 배수로 가지는 소수를 모두 구해야 한다.
	//이를 위해서 약수를 찾는 코드를 활용할 것이다.
	if (N == 1) {
		cout << 1;
		return;
	}

	ull i, j, k=0;
	ull prime[10000];

	ull ret = N;

	//N^0.5의 연산을 한다.
	for (i = 1; i*i <= N; i++) {
		if (i*i == N)
			prime[k++] = i;
		else if (N%i == 0) {
			prime[k++] = i;
			prime[k++] = N / i;
		}
		
	}

	//오름차순으로 정렬해준다.
	sort(prime, prime+k);

	const int divisorSize = k;
	k = 0;
	//만일 약수의 배열 중에서 소수가 아닌 수가 있다면, 지워준다.(-1로 바꾸어 줄 것이다.)
	//약수의 개수는 500개 이하이므로, 최대 250000번의 연산을 할 것이다.
	//prime[1]에서 시작하는 이유는 prime[0]=1으로 특이케이스이기 때문에 고려를 해주었다.
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

	//이제 오일러 파이함수를 활용하자.
	//prime에 담긴 수를 활용하자.
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
