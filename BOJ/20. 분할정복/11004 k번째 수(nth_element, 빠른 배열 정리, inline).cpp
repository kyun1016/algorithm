////동적으로 설계
//
////#include<iostream>
////#include<algorithm>
////
////using namespace std;
////
////int main() {
////	ios_base::sync_with_stdio(0);
////	cin.tie(0);
////	int N, K, i,a;
////	cin >> N >> K;
////
////	int * arr = new int[N];
////	
////	for (i = 0; i < N; i++) {
////		cin >> a;
////		arr[i] = a;
////	}
////	sort(&arr[0],&arr[N]);
////	cout << arr[K - 1];
////
////	delete []arr;
////	return 0;
////}
////
//
//
//
//
////직접 inline함수를 만들어서 읽어들이는 방법을 컨트롤(가장 빠르다)
//
////#include <cstdio>
////#include <algorithm>
////using namespace std;
////
////char buf[60000100];
////int a[5000000];
////inline int readint()
////{
////	static int i = 0;
////	int ret;
////	bool flag = false;
////	if (buf[i] == '-')
////	{
////		flag = true;
////		i++;
////	}
////	ret = buf[i++] - '0';
////	while (buf[i] >= '0')
////	{
////		ret *= 10;
////		ret += buf[i++] - '0';
////	}
////	return ++i, (flag ? -ret : ret);
////}
////
////int main()
////{
////	fread(buf, 1, sizeof(buf), stdin);
////	int n = readint();
////	int k = readint();
////	for (int i = 0; i < n; i++)
////		a[i] = readint();
////	nth_element(a, a + k - 1, a + n);
////	printf("%d", a[k - 1]);
////}
//
////nth_element를 활용하여 n번째 수를 찾아내기(2번째로 빠르다)
//
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int num[5000000];
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL);
//	int N, K;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//	K--;
//	nth_element(num, num + K, num + N);
//	for (int i = 0; i < N; i++) {
//		cout << i <<"번째 수 : " <<num[K] << endl;
//	}
//	cout << num[K];
//
//}