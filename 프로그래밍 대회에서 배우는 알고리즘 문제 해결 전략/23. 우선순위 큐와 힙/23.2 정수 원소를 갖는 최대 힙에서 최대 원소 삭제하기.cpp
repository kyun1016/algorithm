//#include<vector>
//#include<iostream>
//
//using namespace std;
//
////������ ��� �ִ� �� heap�� �� ���� newValue�� �����Ѵ�.
//void push_heap(vector<int>& heap, int newValue) {
//	//���� �� ���� newValue�� �����Ѵ�.
//	heap.push_back(newValue);
//	//���� newValue�� ��ġ
//	int idx = heap.size();
//	//��Ʈ�� �����ϰų� newValue �̻��� ���Ҹ� ���� ������ ���� ������
//	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
//		swap(heap[idx], heap[(idx - 1) / 2]);
//		idx = (idx - 1) / 2;
//	}
//}
//
//////23.2 ���� ���Ҹ� ���� �ִ� ������ �ִ� ���� �����ϱ�
//
////������ ��� �ִ� �� heap���� heap[0]�� �����Ѵ�.
//void pop_heap(vector<int>& heap) {
//	//���� �� ������ ���� ������ ��Ʈ�� ���� �����.
//	heap[0] = heap.back();
//	heap.pop_back();
//	int here = 0;
//	while (true) {
//		int left = here * 2 + 1, right = here * 2 + 2;
//		//������ ������ ���
//		if(left >= heap.size()) break;
//		//heap[here]�� ������ ��ġ�� ã�´�.
//		int next = here;
//		if (heap[next] < heap[left])
//			next = left;
//		if (right < heap.size() && heap[next] < heap[right])
//			next = right;
//		if (next == here) break;
//		swap(heap[here], heap[next]);
//		here = next;
//	}
//}