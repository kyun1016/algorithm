//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//string arr[51];
//vector<pair<int, int> > location[3];
//
//
//int makePortfolio(const int& N, const int& M) {
//	//�켱 �ʱ� �������� �ο�����.
//	int ret = location[0].size() * location[1].size() * location[2].size();
//	if (ret == 0)
//		return 0;
//	pair<int, int> Red = location[0][0];
//	pair<int, int> Green = location[1][0];
//	pair<int, int> Blue = location[2][0];
//	int count_MAX = 0;
//	int MAX_Size = 0;
//
//	//�ﰢ���� ���̸� ���ϴ� ����
//	//S = 1/2 * |(x1y2 + x2y3 + x3y1) - (x1y3 + x3y2 + x2y1)|
//
//	//������ �Ʒ��� �����δ� 20*50�� �Ѱ�
//	for (int a = 0; a < location[0].size(); a++) {
//		Red = location[0][a];
//		for (int b = 0; b < location[1].size(); b++) {
//			Green = location[1][b];
//			for (int c = 0; c < location[2].size(); c++) {
//				Blue = location[2][c];
//				int tri_size = (Red.first*Green.second + Green.first*Blue.second + Blue.first*Red.second) - (Red.first*Blue.second + Blue.first*Green.second + Green.first* Red.second);
//				tri_size = abs(tri_size);
//				
//				if (MAX_Size < tri_size) {
//					MAX_Size = tri_size;
//					count_MAX = 0;
//				}
//					
//				if (MAX_Size == tri_size)
//					count_MAX++;
//
//			}
//		}
//	}
//	ret -= count_MAX;
//
//	return ret;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int T, N, M;
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//		cin >> N >> M;
//		//���� �ʱ�ȭ
//		for (int order = 0; order < 3; order++)
//			while (!location[order].empty())
//				location[order].pop_back();
//		for (int j = 0; j < N; j++) {
//			cin >> arr[j];
//			for (int k = 0; k < arr[j].size(); k++) {
//				if (arr[j][k] == 'R') {
//					location[0].push_back({ j,k });
//				}
//					
//				else if (arr[j][k] == 'G') {
//					location[1].push_back({ j,k });
//				}
//				else {
//					location[2].push_back({ j,k });
//				}
//			}
//		}
//		cout << "#" << i << " " << makePortfolio(N, M) << "\n";
//	}
//	return 0;
//}