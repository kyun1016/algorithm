//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<cstdlib>	//abs()�� ����ϱ� ���� ���
//
//using namespace std;
//
//
//
//
//
////��ġ�� ���ִ� ���� �迭�� 
//
//
//int Count;
//int arr[6][52];
//int max_length;
//
//void make_vortex(int y1, int x1, int y2, int x2){
//	//���� �� �ִ밪�� ���Ѵ�.
//	int MAX = max(max(abs(y1),abs(x1)),max(abs(y2),abs(x2)));
//	//pos_x, pos_y�� ���� ��ġ�̴�.
//	int pos_x, pos_y;
//	pos_x = pos_y = 0;
//	//count�� ���� ����ؾ� �� ���̴�.
//	++Count;
//
//	//���� ��ġ�� ã�ƾ� �� ��ġ ���̶�� ����Ѵ�.
//	if ((x1 <= pos_x && pos_x <= x2) && (y1 <= pos_y && pos_y <= y2))
//		arr[pos_x - x1][pos_y - y1] = Count;
//
//
//	for (int i = 1; i <= MAX; i++) {
//		//pos_x, pos_y�� ���� ��ġ�� ��Ÿ���� ������, ��������� ����, ���Ҹ� ���ش�.
//		++pos_x;
//		++pos_y;
//		int flag = 0;
//		for (int j = 1; j <= i * 8; j++) {
//			switch (flag)
//			{
//			case 0:
//				--pos_y;
//				++Count;
//				//���� ��ġ�� ã�ƾ� �� ��ġ ���̶�� ����Ѵ�.
//				if ((x1 <= pos_x && pos_x <= x2) && (y1 <= pos_y && pos_y <= y2))
//					arr[pos_x - x1][pos_y - y1] = Count;
//				break;
//
//			case 1:
//				--pos_x;
//				++Count;
//				if ((x1 <= pos_x && pos_x <= x2) && (y1 <= pos_y && pos_y <= y2))
//					arr[pos_x - x1][pos_y - y1] = Count;
//				break;
//
//			case 2:
//				++pos_y;
//				++Count;
//				if ((x1 <= pos_x && pos_x <= x2) && (y1 <= pos_y && pos_y <= y2))
//					arr[pos_x - x1][pos_y - y1] = Count;
//				break;
//
//			case 3:
//				++pos_x;
//				++Count;
//				if ((x1 <= pos_x && pos_x <= x2) && (y1 <= pos_y && pos_y <= y2))
//					arr[pos_x - x1][pos_y - y1] = Count;
//				break;
//			}
//			if (j%(i * 2) == 0) flag++;
//		}
//	}
//}
//
//int main() {
//	int x1, y1, x2, y2;
//	cin >> y1 >> x1 >> y2 >> x2;
//	make_vortex(y1,x1,y2,x2);
//	int temp, sub;
//	for (int y = 0; y < (y2 - y1) + 1; y++) {
//		for (int x = 0; x < (x2 - x1) + 1; x++) {
//			//�迭�� ������ ���� �� ���� �ڸ����� ã�´�.
//			temp = to_string(arr[x][y]).length();
//			max_length = max(temp, max_length);
//		}
//	}
//	
//	for (int y = 0; y < (y2-y1)+1; y++) {
//		for (int x = 0; x < (x2-x1)+1; x++) {
//			//���� ����� ���� ���̰� �ִ� ���̺��� ª�ٸ� �� ���̸�ŭ " "(����)�� ����Ѵ�.
//			sub = max_length - to_string(arr[x][y]).size();
//			for (int i = 0; i < sub; i++) {
//				cout << " ";
//			}
//			//���ڸ� ���.
//			cout << arr[x][y] << " ";
//		}
//		cout << endl;
//	}
//}