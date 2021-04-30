//8*8을 확인하며 수정하는 수를 체크한다.

#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

int N, M;
string arr[50];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ret = 987654321;

	for(int y_start=0;y_start<N-7;y_start++)
		for (int x_start = 0; x_start < M - 7; x_start++) {
			int count1 = 0, count2 = 0;
			for (int x = x_start; x < x_start + 8; x++) {
				int x_min = (x - x_start) % 2;
				for (int y = y_start; y < y_start + 8; y++) {
					int y_min = (y - y_start) % 2;
					int sol = (x_min + y_min) % 2;
					if (((sol == 0) && (arr[y][x] == 'W')) || ((sol == 1) && (arr[y][x] == 'B'))) {
						count1++;
					}
					if (((sol == 0) && (arr[y][x] == 'B')) || ((sol == 1) && (arr[y][x] == 'W'))) {
						count2++;
					}
				}
			}
			ret = min(ret, count1);
			ret = min(ret, count2);
		}
			
	cout << ret << endl;

	return 0;
}