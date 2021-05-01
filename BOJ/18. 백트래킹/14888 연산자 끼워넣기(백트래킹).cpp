#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[105];
int operator_count[4];		//µ¡¼À, »¬¼À, °ö¼À, ³ª´°¼À

pair<int,int> dfs(const int& depth) {
	//±âÀú»ç·Ê : ÃÖÁ¾ ±íÀÌÀÎ °æ¿ì.
	if (depth == 0)
		return make_pair(arr[depth], arr[depth]);

	//ÃÖ´ë ÃÖÀú¸¦ ³ª´©¾î return;
	pair<int, int> ret = make_pair(-987654321, 987654321);
	pair<int, int> temp;
	//4°¡Áö ¹æ¹ıÀ» ¼±ÅÃÇØ¼­ ¸ğµç °æ¿ì ½Ãµµ
	////1. µ¡¼À
	//if (operator_count[0] != 0) {
	//	operator_count[0]--;
	//	temp = dfs(depth + 1);
	//	temp.first += arr[depth];
	//	temp.second += arr[depth];
	//	ret.first = max(ret.first, temp.first);
	//	ret.second = min(ret.second, temp.second);
	//	operator_count[0]++;
	//}
	////2. »¬¼À
	//if (operator_count[1] != 0) {
	//	operator_count[1]--;
	//	temp = dfs(depth + 1);
	//	temp.first -= arr[depth];
	//	temp.second -= arr[depth];
	//	ret.first = max(ret.first, temp.first);
	//	ret.second = min(ret.second, temp.second);
	//	operator_count[1]++;
	//}
	////3. °ö¼À
	//if (operator_count[2] != 0) {
	//	operator_count[2]--;
	//	temp = dfs(depth + 1);
	//	temp.first *= arr[depth];
	//	temp.second *= arr[depth];
	//	ret.first = max(ret.first, temp.first);
	//	ret.second = min(ret.second, temp.second);
	//	operator_count[2]++;
	//}
	////4. ³ª´°¼À
	//if (operator_count[3] != 0) {
	//	operator_count[3]--;
	//	temp = dfs(depth + 1);
	//	temp.first /= arr[depth];
	//	temp.second /= arr[depth];
	//	ret.first = max(ret.first, temp.first);
	//	ret.second = min(ret.second, temp.second);
	//	operator_count[3]++;
	//}


	//1. µ¡¼À
	if (operator_count[0] != 0) {
		operator_count[0]--;
		temp = dfs(depth - 1);
		temp.first += arr[depth];
		temp.second += arr[depth];
		ret.first = max(ret.first, temp.first);
		ret.second = min(ret.second, temp.second);
		operator_count[0]++;
	}
	//2. »¬¼À
	if (operator_count[1] != 0) {
		operator_count[1]--;
		temp = dfs(depth - 1);
		temp.first -= arr[depth];
		temp.second -= arr[depth];
		ret.first = max(ret.first, temp.first);
		ret.second = min(ret.second, temp.second);
		operator_count[1]++;
	}
	//3. °ö¼À
	if (operator_count[2] != 0) {
		operator_count[2]--;
		temp = dfs(depth - 1);
		temp.first *= arr[depth];
		temp.second *= arr[depth];
		ret.first = max(ret.first, temp.first);
		ret.second = min(ret.second, temp.second);
		operator_count[2]++;
	}
	//4. ³ª´°¼À
	if (operator_count[3] != 0) {
		operator_count[3]--;
		temp = dfs(depth - 1);
		temp.first /= arr[depth];
		temp.second /= arr[depth];
		ret.first = max(ret.first, temp.first);
		ret.second = min(ret.second, temp.second);
		operator_count[3]++;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();

	//input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> operator_count[i];

	pair<int, int> ret = dfs(N-1);

	cout << ret.first << "\n" << ret.second << endl;

	return 0;
}