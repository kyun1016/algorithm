#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int N;
vector<string> poorHouse;
bool visited[25][25];
int Count;
vector<int> countArr;
int dirY[4] = { 0,0,1,-1 };
int dirX[4] = { 1,-1,0,0 };

//DFS


//BFS
void BFS(int hereY, int hereX) {
	if (visited[hereY][hereX])
		return;
	visited[hereY][hereX] = true;
	Count++;
	for (int i = 0; i < 4; i++) {
		int thereX = hereX - dirX[i], thereY = hereY - dirY[i];
		//������ ����� �ʰ�,
		if (thereX < N&& thereX >= 0 && thereY < N&&thereY >= 0)
			//���� �湮���� �ʾҰ�, �װ��� 1�̶�� �湮����.
			if (!visited[thereY][thereX] && poorHouse[thereY][thereX] == '1') {
				//�װ��� �湮�Ѵ�.
				BFS(thereY, thereX);
			}
		
	}
}


int main() {
	
	//int num = 0;
	cin >> N;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		poorHouse.push_back(temp);
	}

	//BFS
	for(int y=0;y<N;y++)
		for (int x = 0; x < poorHouse[y].size(); x++) {
			if (poorHouse[y][x] == '1' && !visited[y][x]) {			
				Count = 0;
				BFS(y, x);
				/*cout << "x : " << x << " Y : " << y << " count : " << Count << endl;*/
				countArr.push_back(Count);
			}
		}


	sort(countArr.begin(), countArr.end());
	cout << countArr.size() << endl;
	for (int i = 0; i < countArr.size(); i++) {
		cout << countArr[i] << endl;
	}
}