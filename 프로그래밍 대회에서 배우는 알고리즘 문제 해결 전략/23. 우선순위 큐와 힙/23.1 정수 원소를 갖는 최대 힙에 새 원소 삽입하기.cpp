//#include<vector>
//#include<iostream>
//
//using namespace std;
//
////정수를 담는 최대 힙 heap에 새 원소 newValue를 삽입한다.
//void push_heap(vector<int>& heap, int newValue) {
//	//힙의 맨 끝에 newValue를 삽입한다.
//	heap.push_back(newValue);
//	//현재 newValue의 위치
//	int idx = heap.size();
//	//루트에 도달하거나 newValue 이상의 원소를 가진 조상을 만날 때까지
//	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
//		swap(heap[idx], heap[(idx - 1) / 2]);
//		idx = (idx - 1) / 2;
//	}
//}