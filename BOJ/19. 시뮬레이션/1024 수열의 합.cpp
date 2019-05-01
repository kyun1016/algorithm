//#include<iostream>
//
//int N, L;
//
//void calc() {
//	int count, sum(0), i(L-1), flag(0);
//	while (sum != N) {
//		sum = 0;
//		//괜한 연산을 줄이기 위해 count는 N/i부터 시작한다.
//		//길이는 L부터 시작하여 1씩 증가하도록 하였다.
//		count = N / ++i;
//		
//		//이번에 구할 길이가 100을 초과한다면 flag를 세우고 탈출!
//		if (i > 100) {
//			flag = 1;
//			break;
//		}
//
//		//N/i로 나누어 값을 준 것은 찾아야 할 값의 평균 값에 불과하다.
//		//우리는 count++한 값을 지속적으로 더할 것이므로, 대략 (평균 값) - (길이/2)이 되어야한다.
//		//허나 따로 구현하기 귀찮으므로, i=100인 것을 기준으로 50을 빼버렸다.
//		count -= 50;
//		
//		//음이 아닌 정수 리스트여야 하므로 0보다 작은 경우는 0부터 시작하도록 하였다.
//		if (count < 0)
//			count = 0;
//
//		//리스트에 수를 넣어주자.
//		for (int t = 0; t < i; t++) {
//			sum += count++;
//		}
//
//		//sum < N인 경우 리스트 전체에 1씩 더해준다.(결과적으로 sum += i가 된다.)
//		//이때, count가 가리키는 숫자는 리스트의 마지막 숫자이다.
//		while (sum < N) {
//			sum += i;
//			count++;
//		}
//	}
//
//	if (flag) {
//		std::cout << "-1";
//	}
//	else
//		//이건 뭐, 그냥 출력이다.
//		for (i; i > 0; i--)
//			std::cout << count - i << " ";
//}
//
//int main() {
//	std::cin >> N >> L;
//	calc();
//}
//
//
//
////#include<iostream>
////
////int N, L;
////
////void calc() {
////	int count, sum(0), i(L-1), flag(0);
////	while (sum != N) {
////		sum = 0;
////		//여기서는 count를 0에서 부터 시작한다.
////		count = 0;
////		i++;
////		if (i > 100) {
////			flag = 1;
////			break;
////		}
////		for (int t = 0; t < i; t++) {
////			sum += count++;
////		}
////		while (sum < N) {
////			sum += i;
////			count++;
////		}
////	}
////	if (flag) {
////		std::cout << "-1";
////	}
////	else
////		for (i; i > 0; i--)
////			std::cout << count - i << " ";
////}
////
////int main() {
////	std::cin >> N >> L;
////	calc();
////}