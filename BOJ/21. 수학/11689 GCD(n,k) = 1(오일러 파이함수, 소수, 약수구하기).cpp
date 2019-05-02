//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//typedef unsigned long long ull;
//
////새로 만들자
//void coprime(ull N) {
//	//이번에는 오일러의 파이함수를 활용하여 문제를 공략할 것이다.
//	//파이함수를 활용하기 위해서는
//	//1. N을 배수로 가지는 소수를 모두 구해야 한다.
//	//이를 위해서 약수를 찾는 코드를 활용할 것이다.
//	if (N == 1) {
//		cout << 1;
//		return;
//	}
//
//	ull i, j, k=0;
//	ull prime[10000];
//
//	ull ret = N;
//
//	//N^0.5의 연산을 한다.
//	for (i = 1; i*i <= N; i++) {
//		if (i*i == N)
//			prime[k++] = i;
//		else if (N%i == 0) {
//			prime[k++] = i;
//			prime[k++] = N / i;
//		}
//		
//	}
//
//	//오름차순으로 정렬해준다.
//	sort(prime, prime+k);
//	//만일 약수의 배열 중에서 소수가 아닌 수가 있다면, 지워준다.(-1로 바꾸어 줄 것이다.)
//	//약수의 개수는 500개 이하이므로, 최대 250000번의 연산을 할 것이다.
//	//prime[1]에서 시작하는 이유는 prime[0]=1으로 특이케이스이기 때문에 고려를 해주었다.
//	for (i = 1; i < k-1; i++) {
//		ull temp = prime[i];
//		for (j = i + 1; j < k; j++) {
//			if (temp == -1)
//				break;
//			if (prime[j] != -1 && prime[j] % temp == 0) {
//				prime[j] = -1;
//			}
//				
//		}
//	}
//
//	//이제 오일러 파이함수를 활용하자.
//	//prime에 담긴 수를 활용하자.
//	for (i = 1; i < k; i++) {
//		if (prime[i] != -1) {
//			ret *= prime[i] - 1;
//			ret /= prime[i];
//		}
//	}
//
//	cout << ret << endl;
//
//}
//
//
//int main() {
//	ull N;
//	std::cin >> N;
//
//	coprime(N);
//	return 0;
//}
