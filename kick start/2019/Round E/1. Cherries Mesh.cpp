//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int N, M;
//vector<pair<int, int> > qu;
//int visited[1002];
//vector<pair<int, int> > IsLink;
//
//int same_visited;
//
//int Check() {
//	int ret = 0;
//	int count = 0;
//
//	for (int i = 0; i < M; i++) {
//		int first = visited[qu[i].first];
//		int second = visited[qu[i].second];
//
//		if (first > second) {
//			int temp = first;
//			first = second;
//			second = first;
//		}
//
//		//�Ѵ� 0�� �ƴ� ���
//		if (first != 0 && second != 0) {
//			IsLink.push_back({ first, second });
//		}
//		//���� first�� 0�� �ƴ϶��
//		else if (first != 0) {
//				visited[qu[i].second] = first;
//				ret += 1;
//		}
//		//second�� 0�� �ƴ϶��
//		else if (second != 0) {
//				visited[qu[i].first] = second;
//				ret += 1;
//		}
//		//�Ѵ� 0�̶��
//		else {
//			visited[qu[i].first] = ++count;
//			visited[qu[i].second] = count;
//			//�� ������ �ٸ� ������ �����ϴ� �߰����� ������ ����������.
//			if(count != 1)
//				ret += 2;
//			ret += 1;
//		}
//	}
//
//	for (int i = 1; i <= N; i++) {
//		if (visited[i] == 0)
//			ret += 2;
//		visited[i] = 0;
//	}
//
//	sort(IsLink.begin(), IsLink.end());
//		
//	count = 0;
//	for (int i = 0; i < IsLink.size(); i++) {
//		if (!visited[IsLink[i].first]) {
//			visited[IsLink[i].first] = ++count;
//			visited[IsLink[i].second] = count;
//			ret--;
//		}
//		else {
//
//		}
//	}
//	
//
//	IsLink.clear();
//
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int T;
//	cin >> T;
//
//	int a, b;
//	
//	for (int i = 0; i < T; i++) {
//		cin >> N >> M;
//		for (int j = 0; j < M; j++) {
//			cin >> a >> b;
//			qu.push_back({ a,b });
//		}
//
//		cout << "Case #" << i + 1 << ": " << Check() << endl;
//
//		qu.clear();
//	}
//
//}