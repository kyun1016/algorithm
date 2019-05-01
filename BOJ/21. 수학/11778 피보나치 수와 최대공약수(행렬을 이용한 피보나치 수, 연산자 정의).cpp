#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<ull>> matrix;



const ull MOD = 1000000007;

//2*2 행렬 곱셈
matrix operator*(matrix &a, matrix &b)
{
	ull x = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	ull y = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	ull z = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	ull w = a[1][0] * b[0][1] + a[1][1] * b[1][1];

	x %= MOD;
	y %= MOD;
	z %= MOD;
	w %= MOD;

	matrix ret = { { x,y },{ z,w } };
	return ret;
}

ull gcd(ull a, ull b) {
	return a % b ? gcd(b, a%b) : b;
}

//행렬 제곱
void power(matrix &F, ull n)
{
	if (n <= 1) return;

	matrix E = { { 1, 1 },{ 1, 0 } };
	power(F, n / 2);
	F = F * F;
	if (n % 2 != 0) {
		F = F * E;
	}
}

//행렬을 이용한 피보나치 수열 구하기
ull fib(ull n)
{
	matrix F = { { 1, 1 },{ 1, 0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);
	return F[0][0];
}

int main() {
	ull n, m;
	std::cin >> n >> m;
	ull ngcd = gcd(n, m);
	std::cout << fib(ngcd) << "\n";


	return 0;
}