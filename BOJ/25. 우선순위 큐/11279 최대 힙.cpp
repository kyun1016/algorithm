//#include<iostream>
//
//using namespace std;
//
//int N;
//
//int heap[100050];
//int pointer = 0;
//
//void push(int num) {
//	heap[++pointer] = num;
//	int iter = pointer;
//	int temp;
//	while (iter > 1) {
//		if (heap[iter] > heap[iter / 2]) {
//			temp = heap[iter];
//			heap[iter] = heap[iter / 2];
//			heap[iter / 2] = temp;
//		}
//		else
//			break;
//		iter /= 2;
//	}
//}
//
//void pop() {
//	if (pointer > 0) {
//		cout << heap[1] << "\n";
//		heap[1] = heap[pointer--];
//		int iter = 1, temp;
//		int flag = 0;
//		while (iter < pointer) {
//			flag = 0;
//			if (heap[iter] < heap[iter * 2] && iter * 2 <= pointer) {
//				flag = 1;
//				if (heap[iter * 2] < heap[iter * 2 + 1] && iter * 2 + 1 <= pointer) {
//					flag = 2;
//				}
//			}
//			else if (heap[iter] < heap[iter * 2 + 1] && iter * 2 + 1 <= pointer) {
//				flag = 2;
//			}
//			if (flag == 0)
//				break;
//			else if (flag == 1) {
//				iter *= 2;
//				temp = heap[iter];
//				heap[iter] = heap[iter / 2];
//				heap[iter / 2] = temp;
//			}
//			else {
//				iter = iter * 2 + 1;
//				temp = heap[iter];
//				heap[iter] = heap[iter / 2];
//				heap[iter / 2] = temp;
//			}
//		}
//	}
//	else {
//		cout << 0 << "\n";
//	}
//}
//
//int main() {
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	cin >> N;
//	int temp;
//	for (int i = 0;i < N;i++) {
//		cin >> temp;
//		if (temp == 0) {
//			pop();
//		}
//		else {
//			push(temp);
//		}
//	}
//}

#include <iostream>
#include <queue>

using namespace std;

int N;

int main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(num);
	}
}