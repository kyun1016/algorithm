//#include <cstdio>
//#include <algorithm>
//#define P 1000000007LL
//typedef long long ll;
//using namespace std;
//ll fac[4000001], n, k, inv[4000001];//inv[x]�� ���Ǵ� x��inverse�� �ƴ� x!�� inverse
//ll power(ll x, ll y) {    //���� ������ �̿��Ͽ� x^y ���ϱ�
//	ll ret = 1;
//	while (y > 0) {
//		if (y % 2) {
//			ret *= x;
//			ret %= P;
//		}
//		x *= x;
//		x %= P;
//		y /= 2;
//	}
//	return ret;
//}
//int main() {
//	fac[1] = 1;
//	for (int i = 2; i <= 4000000; i++)
//		fac[i] = (fac[i - 1] * i) % P;            //factorial ��ó��
//	inv[4000000] = power(fac[4000000], P - 2);    //�丣���� �������� �̿��Ͽ� fac(400��)�� inverse�� ����(�̶� ���� ������ �̿��Ͽ� logP�� �ð��� ó��) 
//	for (int i = 4000000 - 1; i > 0; i--)
//		inv[i] = (inv[i + 1] * (i + 1)) % P;    //inverse(fac(i))=inverse(fac(i+1))*(i+1)�̶�� ������ �̿��Ͽ� ��ó��
//	//�� O(N+logP)�ð��� ��ó���� ���� 
//	//��ó���� ������ ������ � ������ ���͵� ����ð��� ���� ����� ��� ����
//	scanf("%lld%lld", &n, &k);
//	if (n == k || !k) {
//		puts("1");
//		return 0;
//	}
//	ll r = (fac[n] * inv[n - k]) % P;
//	r = (r*inv[k]) % P;
//	printf("%lld\n", r);
//	return 0;
//}


//#include<iostream>
//
//long x, y, temp;
//long factorial[4000000];
//
//void euclidean(long B, long p) {
//	if (B%p > 0) {
//		euclidean(p, B%p);
//		temp = y;
//		y = x - (B / p)*y;
//		x = temp;
//	}
//	else {
//		x = 0;
//		y = 1;
//	}
//}
//
//int main() {
//
//	int N, K;
//	std::cin >> N >> K;
//	long long p = 1000000007;
//
//
//	factorial[0] = 1;
//	factorial[1] = 1;
//	// factorial ���ϱ�
//	for (int i = 2; i <= N; i++) factorial[i] = (factorial[i - 1] * i) % p;
//	long denominator = (factorial[K] * factorial[N - K]) % p;
//
//	euclidean(p, denominator);
//	long result = ((factorial[N] % p)*(y%p)) % p;
//	if (result < 0) result += p;
//	std::cout << result << std::endl;
//}


