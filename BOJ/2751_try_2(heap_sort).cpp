//#include <iostream>
//#include <vector>		//�̰� �� �״�� vector�� ����ϱ� ����
//#include <algorithm>	//swap�� ����ϱ� ���ؼ�
//
//
//void push_heap(std::vector<int>& heap, int newValue) {
//	//���� �� ���� newValue�� �����Ѵ�.
//	heap.push_back(newValue);
//	//���� newValue�� ��ġ
//	int idx = heap.size() - 1;
//	//��Ʈ�� �����ϰų� newValue �̻��� ���Ҹ� ���� ������ ���� ������
//	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
//		std::swap(heap[idx], heap[(idx - 1) / 2]);
//		idx = (idx - 1) / 2;
//	}
//}
//
//
////�̿� �����Ѱ� ������
////���� ���Ҹ� ���� �ִ� ������ �ִ� ���� �����ϱ�
//void pop_heap(std::vector<int>& heap) {
//	//heap�� �� ������ ���� ������ ��Ʈ�� ������.
//	heap[0] = heap.back();
//	heap.pop_back();
//	int here = 0;
//	while (true) {
//		int left = here * 2 + 1, right = here * 2 + 2;
//		//������ ������ ���
//		if (left >= heap.size()) break;
//		//heap[here]�� ������ ��ġ�� ã�´�.
//		int next = here;
//		if (heap[next] < heap[left]) next = left;
//		if (right < heap.size() && heap[next] < heap[right]) next = right;
//		if (next == here) break;
//		std::swap(heap[here], heap[next]);
//		here = next;
//	}
//}
//
////�����κ� heap sort
//void sort_heap(std::vector<int>& heap) {
//	for (int count = 1;count < heap.size();count++) {
//		std::swap(heap[heap.size() - count] ,heap[0]);
//		int here = 0;
//		while (true) {
//			int left = here * 2 + 1, right = here * 2 + 2;
//			//������ ������ ���
//			if (left >= heap.size()-count) break;
//			//heap[here]�� ������ ��ġ�� ã�´�.
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