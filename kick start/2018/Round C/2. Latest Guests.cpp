//#include<iostream>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
//int N, G, M;
//
//pair<pair<int, int>, int> Arr[100001];
//int Circleburg[100001];
//
//void move() {
//	for (int i = 0; i < G; i++) {
//		Circleburg[i] = 1;
//	}
//	for (int i = 1; i <= M; i++) {
//		for (int j = 0; j < G; j++) {
//			if (Arr[j].first.first % i == 0) {
//				Circleburg[Arr[j].second]--;
//				Circleburg[Arr[j].second + Arr[j].first.second]++;
//				Arr[j].second = Arr[j].second + Arr[j].first.second;
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int T;
//	int time;
//	string temp;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		cin >> N >> G >> M;
//		for (int j = 0; j < G; j++) {
//			cin >> time >> temp;
//			if (temp == "A") {
//				Arr[i] = { {time, -1}, i };
//			}
//			else {
//				Arr[i] = { {time, 1}, i };
//			}
//		}
//
//		move();
//
//		cout << "Case #" << i + 1 << ": ";
//		for (int j = 0; j < G; j++) {
//			cout << Circleburg[j] << " ";
//		}
//		cout << endl;
//	}
//
//}