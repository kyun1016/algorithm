//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<cstdlib>	//abs()를 사용하기 위한 헤더
//
//using namespace std;
//
//
//
//
//
////위치를 빼주는 값을 배열에 
//
//
//int Count;
//int arr[6][52];
//int max_length;
//
//void make_vortex(int y1, int x1, int y2, int x2){
//	//절댓값 중 최대값을 구한다.
//	int MAX = max(max(abs(y1),abs(x1)),max(abs(y2),abs(x2)));
//	//pos_x, pos_y는 현재 위치이다.
//	int pos_x, pos_y;
//	pos_x = pos_y = 0;
//	//count는 지금 출력해야 할 값이다.
//	++Count;
//
//	//현재 위치가 찾아야 할 위치 사이라면 출력한다.
//	if ((x1 <= pos_x && pos_x <= x2) && (y1 <= pos_y && pos_y <= y2))
//		arr[pos_x - x1][pos_y - y1] = Count;
//
//
//	for (int i = 1; i <= MAX; i++) {
//		//pos_x, pos_y는 현재 위치를 나타내는 것으로, 계속적으로 증가, 감소를 해준다.
//		++pos_x;
//		++pos_y;
//		int flag = 0;
//		for (int j = 1; j <= i * 8; j++) {
//			switch (flag)
//			{
//			case 0:
//				--pos_y;
//				++Count;
//				//현재 위치가 찾아야 할 위치 사이라면 출력한다.
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
//			//배열의 수에서 가장 긴 수의 자리수를 찾는다.
//			temp = to_string(arr[x][y]).length();
//			max_length = max(temp, max_length);
//		}
//	}
//	
//	for (int y = 0; y < (y2-y1)+1; y++) {
//		for (int x = 0; x < (x2-x1)+1; x++) {
//			//지금 출력할 수의 길이가 최대 길이보다 짧다면 그 차이만큼 " "(공백)을 출력한다.
//			sub = max_length - to_string(arr[x][y]).size();
//			for (int i = 0; i < sub; i++) {
//				cout << " ";
//			}
//			//숫자를 출력.
//			cout << arr[x][y] << " ";
//		}
//		cout << endl;
//	}
//}