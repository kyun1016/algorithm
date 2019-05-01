////#include <iostream>
////#include <queue>
//
////std::queue<int> q;
////int priorities[10] = { 0 };
////int my_priority;
////
////void find_my_order(int m) {
////	int count(0), max, temp;
////	for (int i = 0; i < q.size(); i++) {
////		max = 0;
////		for (int j = 1; j < 10; j++) {
////			if (priorities[j] != 0) {
////				max = j;
////			}
////				
////		}
////		while (q.front() != max) {
////			temp = q.front();
////			q.pop();
////			q.push(temp);
////			m++;
////			if (m >= q.size()) {
////				m = 0;
////			}
////		}
////
////		if (q.size() == m + 1 && q.front() == my_priority)
////			std::cout << ++count << "\n";
////		q.pop();
////		count++;
////		priorities[max]--;
////
////	}
////}
////
////
////int main() {
////	int test_case, n, m,input_to_queue;
////	std::cin >> test_case;
////	for (int i = 0; i < test_case; i++) {
////		std::cin >> n >> m;
////
////		//리셋을 시킨다.
////		while (!q.empty())
////			q.pop();
////		memset(priorities, 0, sizeof(priorities));
////
////		for (int j = 0; j < n; j++) {
////			std::cin >> input_to_queue;
////			if(j == m)
////				my_priority = input_to_queue;
////			q.push(input_to_queue);
////			priorities[input_to_queue]++;
////		}
////		find_my_order(m);
////	}
////}
//
////std::queue<int> q;
////
////int find_max(int priorities[]) {
////	int max = 0;
////	for (int i = 0; i < 10; i++) {
////		if (priorities[i] != 0) {
////			max = i;
////		}
////	}
////	return max;
////}
////
////void print_order(int ptr, int priorities[]) {
////	int count(0), max(0),temp;
////
////	for (int k = 0; k < q.size(); k++) {
////		//우선순위의 최댓값을 찾아서 이번에 출력해야할 것을 판단하자.
////		max = find_max(priorities);
////		//q.front()를 확인하여 max보다 작은경우 출력을 하지 않고,
////		//큐의 맨 처음으로 돌려보낸다.
////		if (q.front() != max) {
////			temp = q.front();
////			q.pop();
////			q.push(temp);
////			//포인터의 위치를 변경한다.
////			ptr++;
////			if (ptr >= q.size()) {
////				ptr = 0;
////			}
////		}
////		//q.front()가 max와 같은 경우
////		else if (q.front() == max) {
////			//만일 내가 찾는 수의 차례라면?
////			if (ptr + 1 == q.size())
////				std::cout << count+1 << "\n";	//지금껏 카운트 한 수를 출력해준다.
////			//문서 하나를 출력하고, 카운터를 올려준다.
////			q.pop();
////			count++;
////			//포인터의 위치를 변경한다.
////			ptr++;
////			if (ptr >= q.size()) {
////				ptr = 0;
////			}
////			//priorities를 변경한다.
////			priorities[max]--;
////		}
////
////	}
////
////
////
////
////	
////
////	
////}
////
////int main() {
////	int test, n, m, input;
////	int priorities[10] = { 0 };
////	std::cin >> test;
////	for (int i = 0; i < test; i++) {
////		std::cin >> n >> m;
////		while (!q.empty()) {
////			q.pop();
////		}
////		memset(priorities, 0, 10);
////		for (int j = 0; j < n; j++) {
////			std::cin >> input;
////			q.push(input);
////			priorities[input]++;
////		}
////		print_order(m,priorities);
////	}
////}
//
//
////#include <cstdio>
////#include <algorithm>
////#include <queue>
////using namespace std;
////int t, n, m, x, r;
////int main() {
////	scanf("%d", &t);
////	while (t--) {
////		r = 0;
////		queue<pair<int, int>> qu;
////		priority_queue<int> pq;
////		scanf("%d%d", &n, &m);
////		for (int i = 0; i < n; i++) {
////			scanf("%d", &x);
////			qu.push({ x,i });
////			pq.push(x);
////		}
////		while (qu.size()) {
////			int here = qu.front().first;
////			int num = qu.front().second;
////			qu.pop();
////			if (pq.top() == here) {
////				r++;
////				pq.pop();
////				if (num == m)break;
////			}
////			else qu.push({ here,num });
////		}
////		printf("%d\n", r);
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <queue>
//
//int main() {
//	int test, n, m, input;
//	std::cin >> test;
//	while(test--) {
//		int count(0);
//		std::queue<std::pair<int, int>> queue;
//		std::priority_queue<int> priority_queue;
//		std::cin >> n >> m;
//		for (int i = 0; i < n; i++) {
//			std::cin >> input;
//			//내가 넣은 순서를 판단해야하기에 pair로 집어넣었다.
//			queue.push({ input,i });
//			//priority_queue를 활용해 우선도에 따라 배열이 자동으로 정렬된다.
//			priority_queue.push(input);
//		}
//		while (queue.size()) {
//			int priority = queue.front().first;
//			int num = queue.front().second;
//			if (priority_queue.top() == priority) {
//				count++;
//				priority_queue.pop();
//				queue.pop();
//				//이번 순서가 내가 원하는 순서였다면,
//				if (num == m) break;
//			}
//			else {
//				queue.pop();
//				queue.push({ priority, num });
//			}
//		}
//		std::cout << count << "\n";
//	}
//}