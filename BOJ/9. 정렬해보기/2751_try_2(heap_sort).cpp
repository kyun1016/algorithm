//#include <iostream>
//#include <vector>		//이건 말 그대로 vector를 사용하기 위함
//#include <algorithm>	//swap을 사용하기 위해서
//
//
//void push_heap(std::vector<int>& heap, int newValue) {
//	//힙의 맨 끝에 newValue를 삽입한다.
//	heap.push_back(newValue);
//	//현재 newValue의 위치
//	int idx = heap.size() - 1;
//	//루트에 도달하거나 newValue 이상의 원소를 가진 조상을 만날 때까지
//	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
//		std::swap(heap[idx], heap[(idx - 1) / 2]);
//		idx = (idx - 1) / 2;
//	}
//}
//
//
////이왕 구현한거 끝까지
////정수 원소를 갖는 최대 힙에서 최대 원소 삭제하기
//void pop_heap(std::vector<int>& heap) {
//	//heap의 맨 끝에서 값을 가져와 루트에 덮어씌운다.
//	heap[0] = heap.back();
//	heap.pop_back();
//	int here = 0;
//	while (true) {
//		int left = here * 2 + 1, right = here * 2 + 2;
//		//리프에 도달한 경우
//		if (left >= heap.size()) break;
//		//heap[here]가 내려갈 위치를 찾는다.
//		int next = here;
//		if (heap[next] < heap[left]) next = left;
//		if (right < heap.size() && heap[next] < heap[right]) next = right;
//		if (next == here) break;
//		std::swap(heap[here], heap[next]);
//		here = next;
//	}
//}
//
////문제부분 heap sort
//void sort_heap(std::vector<int>& heap) {
//	for (int count = 1;count < heap.size();count++) {
//		std::swap(heap[heap.size() - count] ,heap[0]);
//		int here = 0;
//		while (true) {
//			int left = here * 2 + 1, right = here * 2 + 2;
//			//리프에 도달한 경우
//			if (left >= heap.size()-count) break;
//			//heap[here]가 내려갈 위치를 찾는다.
//			int next = here;
//			if (heap[next] < heap[left]) next = left;
//			if (right < heap.size()-count && heap[next] < heap[right]) next = right;
//			if (next == here) break;
//			std::swap(heap[here], heap[next]);
//			here = next;
//		}
//	}
//}
//
//
//
//int main(void) {
//	int n;
//	std::cin >> n;
//	std::vector<int> heap;
//	for (int t = 0;t < n;t++) {
//		int a;
//		std::cin >> a;
//		push_heap(heap, a);
//	}
//	sort_heap(heap);
//	for (auto a: heap)
//		std::cout << a << "\n";
//}